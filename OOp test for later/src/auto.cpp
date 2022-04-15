#include "vex.h"

extern chassis Drive;

int SelectedAuto = 1;

void waitTillOff(){ // Function that checks my tasks to see if their done and waits fro them to be done
  while (1){
    wait(200,msec);
    if( ArmOff() && IntakeOff() ){
      break;
    }
    wait(20,msec);
  }
}

void autoSelector() {
 
 int width = 80; //Basic Rectangle Dimensions
 int height = 80;

 int TRx = 30; //Top Red Rect starting pos
 int TRy = 20;

 int BRx = 120; //Bot Red rect Starting pos
 int BRy = 20;

 int TBx = 210; //Top blue rect  Starting pos
 int TBy = 20;

 int BBx = 300; //Bot Blue rect Sratring pos
 int BBy = 20;

 int Sx = 160; //Skils rect Srating pos 
 int Sy = 120;

//Draws all of the rectancgles on the brain according to Start pos and Dimensions
 Brain.Screen.drawRectangle(TRx,TRy,width,height,red);
 Brain.Screen.drawRectangle(BRx,BRy,width,height,red);
 Brain.Screen.drawRectangle(TBx,TBy,width,height,blue);
 Brain.Screen.drawRectangle(BBx,BBy,width,height,blue);
 Brain.Screen.drawRectangle(Sx,Sy,width,height,yellow);
 while(1){
  if(Brain.Screen.pressing()){
   int selX = Brain.Screen.xPosition(); //Reports the X and Y of the Brain screen selection press
   int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))){ //Creates the Top Red rect selecting points
       SelectedAuto = 1 ;
       Brain.Screen.printAt(20,200, "Top Red");
      }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){ //Creates the Bot Red rect Selecting points
       SelectedAuto = 2;
       Brain.Screen.printAt(20,200, "Bot Red");
      }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){ //Creates the Top Blue rect Selecting points
        SelectedAuto = 3;
        Brain.Screen.printAt(20,200, "TopBlue");
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){ //Creates the Bot Blue rect Selecting points
        SelectedAuto = 4;
        Brain.Screen.printAt(20,200, "BotBlue");
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){ //Creates the SKills Skills rect selecting points
        SelectedAuto = 5;
        Brain.Screen.printAt(20,200, "Skills");
    }
  }
   else if(Competition.isEnabled()){
    break;
  }
 }
}

void Auto(void){ //Auto function definition
 Inertial.setHeading(0,degrees);
 if(SelectedAuto == 1){ }
}