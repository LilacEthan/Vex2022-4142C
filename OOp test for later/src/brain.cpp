#include"vex.h"
#include"STAYC_logo.h"

using namespace vex;

void brainScreen::background(){
  Brain.Screen.drawImageFromBuffer(StayC , 10,10,sizeof(StayC));

  //use the buffer of png inages or
  //Brain.Screen.drawImageFromFile();
  //use and SD card name the picture StayC_logo.png
}