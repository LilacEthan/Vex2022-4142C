#include "cmath"
#include "vex.h"

using namespace vex;


int ArmStat = 0;
double height = 0;
// Function to put the lift up
void armUp(int speed) { lift.spin(fwd, speed, pct); }

// Function to stop the Lift
void lift_Stop() { lift.stop(hold); }
// Returns position of arm
double LiftPos() {
  // return ((lftLift.position(degrees) + rgtLift.position(degrees)) / 2);
  return(armPot.angle(degrees));
}
// Sets arm position to specific degree
bool ArmOff(){
  if (ArmStat == 0){
    return(true);
  }
  else{
    return(false);
  }
}

void armPos(int Angle){
  height = Angle;
  ArmStat = 1;
}
//Arm task 
int ArmT(){
  while(1){
    double ArmError = (height - LiftPos());
    if (ArmStat == 1){
      printf("Arm height %f" , ArmError);
      if(ArmError > 9){
        lift.spin(fwd,90,pct);
      }
      else if(ArmError < -9){
        armUp(-90);
      }
      else if (fabs(ArmError) <= 8){
        ArmStat = 0;
      }
    }
    else if(ArmStat == 0){
      lift_Stop();
    }
  }
  wait(20,msec);
  return(0);
}