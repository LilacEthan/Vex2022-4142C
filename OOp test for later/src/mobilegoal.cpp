#include "vex.h"
using namespace vex;

void MBG::setFrnt(bool pos){
  frntMbg.set(pos);
}

void MBG::setBack(bool pos){
  bckMbg1.set(pos);
  bckMbg2.set(pos);
}

bool MBG::inFrnt(){
  bool status = (frntBump.pressing())? true : false ;
  return(status);
}

bool MBG::inBack(){
  bool status = (backSen.objectDistance(mm) < 10 ) ? true : false;
  return(status);
}

void MBG::autoClamp(bool side){
  if(side){
    MBG::fStatus = true;
  }
  else if(!side){
    MBG::bStatus = true;
  }
}

void MBG::waitFrnt(){   
 if(Mbg.inFrnt()){
    Mbg.setFrnt(true);
    Mbg.fStatus = false;
  }
}

void MBG::waitBack(){
  if(Mbg.inBack()){
    Mbg.setBack(true);
    Mbg.bStatus = false;
   }
}