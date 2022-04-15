#include "vex.h"
using namespace vex;

int intakeStat = 0;
double sped = 0;
//function to run the intake
void Intake(int speed){
 intakeStat = 1;
 sped = speed;
}
//function to stop the intake
void stop_Intake(){
 intakeStat = 0;
}



int IntakeT(){
  while(1){
   if (intakeStat  == 1){
     conveyor.spin(fwd,sped,pct);
   }
   else if(intakeStat == 0){
     conveyor.stop(coast);
   }
  }
  wait(20,msec);
  return(0);
}

bool IntakeOff(){
  if(intakeStat == 0){
    return(true);
  }
  else{
    return(false);
  }
}
