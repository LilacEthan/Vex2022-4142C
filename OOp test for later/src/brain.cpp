#include"vex.h"
#include"STAYC_logo.h"

using namespace vex;



void brainScreen::background(){
  // Brain.Screen.drawImageFromBuffer(StayC , 10,10, sizeof(StayC));
   Brain.Screen.drawImageFromFile("StayC.png",10,10);
   Brain.Screen.drawImageFromFile("Jang.png",230,20);
  //dont need selection rectangles because their faces will be the rectangles :)))))
  Brain.Screen.drawRectangle(brainScreen::awpX,brainScreen::awpY,brainScreen::w,brainScreen::l);
}

void brainScreen::checking(){
  if(lftFrnt.installed() && lftMid.installed() && lftBack.installed() && rgtFrnt.installed() && rgtMid.installed() && rgtBack.installed() && Brain.SDcard.isInserted()){
  Brain.Screen.printAt(100,200, "Gurls Its Going Down");
  }
  else{}
  
}

void brainScreen::selection(){
 if(Brain.Screen.pressing()){
   int x = Brain.Screen.xPosition();
   int y = Brain.Screen.yPosition();

   if((x > brainScreen::awpX && x < (brainScreen::awpX + brainScreen::w)) && (y > brainScreen::awpY && y < (brainScreen::awpY + brainScreen::l))){
     brainScreen::selectedAuto = awpLine;
     Brain.Screen.printAt(300,220,"AwpLine");  
   }
   else if(x > brainScreen::nonAwpX && x < (brainScreen::nonAwpX + brainScreen::w) && y > brainScreen::nonAwpY && y < (brainScreen::nonAwpY + brainScreen::l)){
     brainScreen::selectedAuto = nonAwp;
     Brain.Screen.printAt(300,220,"PlatSide");
   }
 }
 else{}
}