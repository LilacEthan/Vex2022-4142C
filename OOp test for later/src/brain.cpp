#include"vex.h"
#include"STAYC_logo.h"

using namespace vex;



void brainScreen::background(){
  // Brain.Screen.drawImageFromBuffer(StayC , 10,10, sizeof(StayC));
   Brain.Screen.drawImageFromFile("StayC.png",10,10);
}

void brainScreen::checking(){
  if(lftFrnt.installed() && lftMid.installed() && lftBack.installed() && rgtFrnt.installed() && rgtMid.installed() && rgtBack.installed() && Brain.SDcard.isInserted()){
   Brain.Screen.printAt(10,120, "Its Going Down");
  }
}