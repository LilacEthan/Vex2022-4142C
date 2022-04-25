#include "vex.h"
using namespace vex;

void intake::Intake(){
  conveyor.spin(fwd,80,pct);
}

void intake::Outtake(){
  conveyor.spin(fwd,-90,pct);
}

void intake::stopTake(){
  intake::Off = true;
}

void intake::setTake(bool Direction){
  intake::Off = false;
  intake::Direc = Direction;
}