//------------------------------------------------------------------------------------------------
//----------------------------------Conveyor Functions--------------------------------------------
//Motion
void Intake(int Speed); // Function to set conveyor speed
void stop_Intake();// Function to stop the conveyor 
int IntakeT(); // Task to control the converyor
//sensing
bool IntakeOff();// checks to see if thei ntake has stoped its movement