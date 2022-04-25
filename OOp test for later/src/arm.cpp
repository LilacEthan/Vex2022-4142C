#include "vex.h"

using namespace vex;

double arm::getAng(){
  return(armPot.angle(degrees));
}

void arm::liftSet( int pwr){
  lift.spin(fwd,pwr,pct);
}

void arm::liftStop(){
  lift.stop(hold);
}

void arm::toPos(){
  if((arm::tAng - arm::getAng()) >= 0.5){
    arm::liftSet(100);
  }
  else{
    arm::liftStop();
    arm::Off = true;
  }
}

void arm::setPos(double ang){
  arm::Off = false;
  arm::tAng = ang;
}
