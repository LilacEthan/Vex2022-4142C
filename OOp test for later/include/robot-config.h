using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lftBack;
extern motor rgtBack;
extern motor conveyor;
extern motor lift;
extern inertial Inertial;
extern motor rgtFrnt;
extern motor lftFrnt;
extern encoder Right;
extern encoder Left;
extern triport Expander21;
extern motor Tilter;
extern encoder Midd;
extern motor lftMid;
extern motor rgtMid;
extern potV2 armPot;
extern digital_out mbgIntakeR;
extern digital_out mbgIntakeL;
extern digital_out claw;
extern digital_out lok;

extern motor_group leftDrive;
extern motor_group rightDrive;

void driverControlled(void);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );


