#include "cmath"
#include "vex.h"

using namespace vex;


//---------------------------------Position Tracking Drive Class functions----------------------------------------------//
float chassis::getAvg(){
  return((Left.position(degrees) + Right.position(degrees)) /2);
}
void chassis::setStart(double x,double y,double ang){
  chassis::sX =x;
  chassis::sY =y;
  chassis::sang += ang;

  chassis::prevX = x;
  chassis::prevY = y;
}
void chassis::updatePos() { // sets class constants to real world values and will get value after motion done so almost like pre values
  chassis::x = (chassis::getX() / 647) + (chassis::sX);
  chassis::y = (chassis::getY() / 647)  + (chassis::sY);
  chassis::ang = chassis::getAng(false);
}
float chassis::getX() { // gets Raw X value of robot "int encoder ticks"
  return (cosf(chassis::getAng(true)) * chassis::getAvg());
}

float chassis::getY() { // gets Raw Y value of robot "in encoder ticks"
  return (sinf(chassis::getAng(true)) * chassis::getAvg());
}
float chassis::getAng( bool radian) { // Translates Curheading from degrees to radians
  if (radian) {
    return ((Inertial.heading() * (M_PI / 180)) + ((M_PI/180) * (chassis::sang))); // gets Angle of robot in radians
  } else if (!radian) {
     return (Inertial.heading() + chassis::sang); // gets Angle of robot in degrees limited to a range of (0-360)
  } else
    return (0);
}
float chassis::MgetTang(){ //returns the target angle based on current target angles in degrees (both positive and negetive)
  return(((atan(chassis::tY/chassis::tX)) * 180/M_PI ) + chassis::sang);
}

float chassis::MgetTdis(){ //uses distance formula to find how far the robot neds to travel (always positive)
  return((sqrt(pow((chassis::tX - chassis::prevX),2) + pow((chassis::tY - chassis::prevY),2))) * 647);
}

double chassis::PID(float target, bool turning) { //PID calculator for if Turning and what axis to move "moves like a box"
  double error;
  float pOut;
  float iOut;
  double iEr = 0;
  float dOut;
  double preEr = 0;
  float output = 0;

  if (!turning ) {
   error = target - chassis::getAvg() ;

   pOut = chassis::dP * error;
   
   iEr += error;
   if(iEr >= 4300 ){
     iEr = 4300;
   }
   else if(iEr <= -4300){
     iEr = -4300;
   }   
   iOut = chassis::dI * iEr ;
   
   dOut = chassis::dD * preEr;

   preEr = error;

   output = pOut + iOut + dOut ;
  } 
  else if (turning) {
   error = target - chassis::getAng(false);

   pOut = chassis::tP * error;

   iEr += error;
   if(iEr > 360){
    iEr = 360;
   }
   else if(iEr < -360){
     iEr = -360;
   }

   iOut = chassis::tI * iEr;

   dOut = chassis::tD * preEr;

   preEr = error;

   output = pOut + iOut + dOut;
  }
  //finally returns PID out put for spesific Axis
  return(output);
}

bool chassis::reverse(){
  if(fabs(chassis::MgetTang()) >= 85 && (chassis::tX <= chassis::prevX || chassis::tY >= chassis::prevY)){
   return(false);
  }
  else if(fabs(chassis::MgetTang()) < 95 && (chassis::tX >= chassis::prevX || chassis::tY >= chassis::prevY)){
    return(false);
  }
  else{
    return(true);
  }
}

bool chassis::revolution(){
  if(((chassis::MgetTang() - chassis::getAng(false)) > 1) || (chassis::tAng - chassis::getAng(false)) < 1){
    return(true);
  }
  else if(((chassis::MgetTang() - chassis::getAng(false)) < 1 ) || (chassis::tAng - chassis::getAng(false)) < 1){
    return(false);
  }
  return(0);
}


//------------------------------------Drive Class Movement Functions-------------------------------------// 
void chassis::setLft(int pwr){
  leftDrive.spin(fwd,pwr,pct);
}
void chassis::setRgt(int pwr){
  rightDrive.spin(fwd,pwr,pct);
}
void chassis::stopDrive(){
  leftDrive.stop(coast);
  rightDrive.stop(coast);
}

void chassis::setPos(double x,double y,double ang){
  chassis::tX = x;
  chassis::tY = y ;
  chassis::tAng = ang + sang;
  chassis::Off = false;
}
void chassis::moveMent(){
  if((fabs(chassis::MgetTang()) - chassis::getAng(false)) > 1){
    if(chassis::revolution()){
      chassis::setRgt(-chassis::PID(chassis::MgetTang(),true));
      chassis::setLft(chassis::PID(chassis::MgetTang(),true));
    }
    else {
      chassis::setRgt(chassis::PID(chassis::MgetTang(),true));
      chassis::setLft(-chassis::PID(chassis::MgetTang(),true));
    }
  }
  else if((fabs(chassis::tX - chassis::prevX) > 0.1) || (fabs(chassis::tY - chassis::prevY) > 0.1)){
    if(chassis::reverse()){
     chassis::setRgt(-chassis::PID(chassis::MgetTdis(),false));
     chassis::setLft(-chassis::PID(chassis::MgetTdis(),false));
    }
    else{
      chassis::setRgt(chassis::PID(chassis::MgetTdis(),false));
      chassis::setLft(chassis::PID(chassis::MgetTdis(),false));
    }
  }
  else if(fabs(chassis::tAng - chassis::getAng(false)) > 1){
    Brain.Screen.printAt(280,140,"Piss on my TITTIEs DADDY");
    if(chassis::revolution()){
      chassis::setRgt(-chassis::PID(chassis::tAng,true));
      chassis::setLft(chassis::PID(chassis::tAng,true));
    }
    else{
      chassis::setRgt(chassis::PID(chassis::tAng,true));
      chassis::setLft(-chassis::PID(chassis::tAng,true));
    }
  } 
  else{
     chassis::Off = true;
     chassis::prevX = chassis::x;
     chassis::prevY = chassis::y;

    }
}

