#include "vex.h"
using namespace vex;


void mbg(bool take){
  bckMbg1.set(take);
  bckMbg2.set(take);
}

void clamp (bool pos){
  frntMbg.set(pos);
}