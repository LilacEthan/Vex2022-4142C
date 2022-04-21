using namespace vex;

extern brain Brain;
extern controller Controller;

// VEXcode devices
extern motor lftBack;
extern motor rgtBack;
extern motor conveyor;
extern motor lift;
extern inertial Inertial;
extern motor rgtFrnt;
extern motor lftFrnt;
extern encoder Right;
extern encoder Left;
extern motor lftMid;
extern motor rgtMid;
extern potV2 armPot;
extern digital_out bckMbg1;
extern digital_out bckMbg2;
extern digital_out frntMbg;
extern bumper frntBump;

extern motor_group leftDrive;
extern motor_group rightDrive;

void driverControlled(void);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

//Robot Tasks 

extern task robo;
extern task debug;

int robotControl();

int brainControl();