#include"vex.h"

using namespace vex;

int robotControl(){
 while(1){
  if(!Drive.Off){ //Drive Task control
   Drive.moveMent();
  }
  if(!Arm.Off){ //Arm Task Control
   Arm.toPos();
  }
  if(!Conv.Off){ //Conveyor Task Control
    if(Conv.Direc){
      Conv.Intake();
    }
    else if(!Conv.Direc){
      Conv.Outtake();
    }
  }
  if(Mbg.fStatus){ // MBG Task for sensor detection
    if(Mbg.inFrnt()){
      Mbg.setFrnt(true);
      Mbg.fStatus = false;
    }
  }
  if(Mbg.bStatus){
    if(Mbg.inBack()){
      Mbg.setBack(true);
      Mbg.bStatus = false;
    }
  }

  //Task Break out for when the Robot goes into Driver control just incase
 if(Competition.isDriverControl()){
   break;
  } 
 }
 wait(15,msec);
 return(0);
}

int brainControl(){
 screen.background(); //Will print non moving background and non Checkers like (StayC Girlsssssssssss :)
  while(1){
    if(Competition.isDriverControl()){
      break;
    }
  }
  wait(20,msec);
  return(0);
}

void waitTillOff(){ // Function that checks my tasks to see if their done and waits fro them to be done
  while (1){
    wait(200,msec);
    if(Conv.Off  && Drive.Off && Arm.Off) {
      break;
    }
    wait(20,msec);
  }
}