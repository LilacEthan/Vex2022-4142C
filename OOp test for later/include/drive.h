using namespace vex;


class chassis {
 private:
  const double dP = 7;
  const double dI = 1;
  const double dD = 1;

  const double tP = 0.5;
  const double tI = 0.5;
  const double tD = 0.5;

  const double kP = 0.5;

 public:
  bool Off; //current staus of the chassis

  int driving(); //Chasssis moving task

  float align();
  void stopDrive();
  void setLft(int pwr);
  void setRgt(int pwr);

  void Drive(int target,bool pid); //function to go straight forward based on encoder distance (choose PID)

  //odometry like functions "odometry based on the center of the robot"
  
  //current X,Y,and Angle Values
  float x;
  float y;
  float ang;
  //target X,Y, and Ang values 
  float targetX;
  float targetY;
  float targetAng;

  float PID(float target, bool turning, bool axis); //PID controller based on Odometry (choose Which axis X,Y, or turning the robot)
  float getX();
  float getY();
  float getAng(bool radian);
  void updatePos();
  void setStart(double x,double y, double ang);

  void setPos(double x,double y, double ang);

  void toX(int trgt);

  void toY(int trgt);

  void toAng(int trgt);
  
};
