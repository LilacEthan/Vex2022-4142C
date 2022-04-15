
//-----------------------------------------------------------------------------------------------
//------------------------------Lift/Arm functions-----------------------------------------------
//Motion
void armUp(int speed); //Function to set the lift motors to certain speed
void lift_Stop(); //Function to Stop the lift and set to hold motors 
int ArmT(); // Arm task
void armPos(int Angle); // sets desired position for the arm and activates task
//Sensing
void ResetArm(); // Resets internal encoders for the Arm motors used in pre auto
double LiftPos(); //gets the curent position of the lift
bool ArmOff(); // checks to see if the Arm task is done moving