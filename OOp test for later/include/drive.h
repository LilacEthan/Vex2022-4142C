using namespace vex;


class chassis {
 private:
  const double dP = 0.09;
  const double dI = 0;
  const double dD = 0;

  const double tP = 0.5;
  const double tI = 0.5;
  const double tD = 0.5;

  const double kP = 0.5;

 public:
  bool Off = true; //current staus of the chassis

  float getAvg();
  float align();
  void stopDrive();
  void setLft(int pwr);
  void setRgt(int pwr);

  void Drive(int target,bool pid); //function to go straight forward based on encoder distance (choose PID)

  //odometry like functions "odometry based on the center of the robot"
  bool reverse();
  bool revolution();
  //target X,Y, and Ang values 
  double tX;
  double tY;
  double tAng;
  double sY;
  double sX;
  double sang = 90;
  double prevX;
  double prevY;
  double prevAng;
  //current X,Y,and Angle Values
  float x;
  float y;
  float ang;

  void resetT();
  double PID(float target, bool turning); //PID controller based on Odometry (choose Which axis X,Y, or turning the robot)
  float getX();
  float getY();
  float getAng(bool radian);
  
  void updatePos();
  void setStart(double x,double y, double ang);

  void setPos(double x,double y, double ang);

  void moveMent();
  
  float MgetTang();

  float MgetTdis();
};
