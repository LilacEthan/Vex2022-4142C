#include "cmath"
#include "vex.h"

using namespace vex;
//---------------------------------Position Tracking Drive Class functions----------------------------------------------//
void chassis::setStart(double x,double y,double ang){
  chassis::x =x;
  chassis::y =y;
  chassis::ang = ang;
}
void chassis::updatePos() { // sets class constants to real world values and will get value after motion done so almost like pre values
  chassis::x += (chassis::getX() / 860);
  chassis::y += (chassis::getY() / 860);
  chassis::ang = chassis::getAng(false);
}
float chassis::getX() { // gets Raw X value of robot "int encoder ticks"
  return ((cos(chassis::getAng(true)) * ((Right + Left) / 2)));
}

float chassis::getY() { // gets Raw Y value of robot "in encoder ticks"
  return ((sin(chassis::getAng(true)) * ((Right + Left) / 2)));
}
float chassis::getAng( bool radian) { // Translates Curheading from degrees to radians
  if (radian) {
    return ((Inertial.heading() * M_PI / 180) + (chassis::ang * (M_PI / 180))); // gets Angle of robot in radians
  } else if (!radian) {
    float Degree = Inertial.heading() + chassis::ang;
    if (Degree > 360) {
      Degree = Degree - 360;
    }
    return (
        Degree); // gets Angle of robot in degrees limited to a range of (0-360)
  } else
    return (0);
}

float chassis::PID(float target, bool turning, bool axis) { //PID calculator for if Turning and what axis to move "moves like a box"
  double error;
  float pOut;
  float iOut;
  double iEr = 0;
  float dOut;
  double preEr = 0;
  float output = 0;

  if (!turning && axis) {
   error = target - chassis::getX();

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
   if(output <= 2){
    updatePos();
   }
  } 
  else if(!turning && !axis){
    error = target - chassis::getY();

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
   if(output <= 2){
     updatePos();
   }
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
   if(output <= 1 ){
     updatePos();
   }
  }
  //finally returns PID out put for spesific Axis
  return(output);
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

int chassis::driving(){
  while(1){
   if(!chassis::Off){
    
   }
   else if(chassis::Off){
    chassis::updatePos();
    chassis::stopDrive();
   }
  }
  wait(15,msec);
  return(0);
}