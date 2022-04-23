#include"vex.h"

using namespace vex;

int robotControl(){
 while(1){
  if(!Drive.Off){
   Drive.moveMent();
  }
  



 if(Competition.isDriverControl()){
   break;
  } 
 }
 wait(15,msec);
 return(0);
}

int brainControl(){
  while(1){

    screen.background();
    if(Competition.isDriverControl()){
      break;
    }
  }
  wait(20,msec);
  return(0);
}