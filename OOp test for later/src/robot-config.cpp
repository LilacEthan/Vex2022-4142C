#include "vex.h"



using namespace vex;
using signature = vision::signature;
using code = vision::code;

//--Important-devices-needing-constructing-early-----
brain  Brain; //Vex V5 Brain
controller Controller = controller(primary);//Vex V5 Primary controller
triport Expander = triport(PORT5); //Vex V5 Triport expander

// VEXcode device constructors
//----------Drive------------
motor rgtFrnt = motor(PORT8, ratio18_1, false);
motor rgtMid = motor(PORT9, ratio18_1, false);
motor rgtBack = motor(PORT10,ratio18_1,false);
motor lftFrnt = motor(PORT6, ratio18_1, true);
motor lftMid = motor(PORT12, ratio18_1, true);
motor lftBack = motor(PORT7, ratio18_1, true);
motor_group leftDrive = {lftFrnt, lftBack,lftMid};
motor_group rightDrive = {rgtFrnt, rgtBack,rgtMid};
encoder Right = encoder(Brain.ThreeWirePort.C);
encoder Left = encoder(Expander.A);
inertial Inertial = inertial(PORT20);
//------------arm--------------
potV2 armPot = potV2(Brain.ThreeWirePort.A);
motor lift = motor(PORT4, ratio36_1, true);
//----------conveyor------------
motor conveyor = motor(PORT19, ratio6_1, false);
//------------MBG-subsystems-----
digital_out bckMbg1 = digital_out(Expander.H);
digital_out bckMbg2 = digital_out(Expander.G);
distance backSen = distance(PORT21);
digital_out frntMbg = digital_out(Expander.F);
bumper frntBump = bumper(Expander.E);


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