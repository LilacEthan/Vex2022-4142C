#include "vex.h"



using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
//----------Drive------------
motor rgtFrnt = motor(PORT8, ratio18_1, false);
motor rgtMid = motor(PORT9, ratio18_1, false);
motor rgtBack = motor(PORT10,ratio18_1,false);
motor lftFrnt = motor(PORT18, ratio18_1, true);
motor lftMid = motor(PORT19, ratio18_1, true);
motor lftBack = motor(PORT14, ratio18_1, true);
motor_group leftDrive = {lftFrnt, lftBack,lftMid};
motor_group rightDrive = {rgtFrnt, rgtBack,rgtMid};
//------------arm--------------
triport Expander21 = triport(PORT21);
controller Controller1 = controller(primary);
motor conveyor = motor(PORT1, ratio6_1, false);
motor lift = motor(PORT7, ratio36_1, false);
inertial Inertial = inertial(PORT20);
encoder Right = encoder(Expander21.A);
encoder Left = encoder(Expander21.C);
potV2 armPot = potV2(Expander21.H);
digital_out mbgIntakeR = digital_out(Brain.ThreeWirePort.F);
digital_out mbgIntakeL = digital_out(Brain.ThreeWirePort.G);
digital_out claw = digital_out(Brain.ThreeWirePort.H);
digital_out lok = digital_out(Brain.ThreeWirePort.E);
vex::distance disSen = vex::distance(PORT5);
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}