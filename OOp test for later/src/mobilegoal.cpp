#include "vex.h"
using namespace vex;


void mbg(bool take){
  mbgIntakeR.set(take);
  mbgIntakeL.set(take);
  lok.set(take);
}

void clamp (bool pos){
  claw.set(pos);
}