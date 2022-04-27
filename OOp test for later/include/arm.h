//arm Class

class arm {
 public:
  bool Off  = true;
  double tAng;
  double getAng();

  void liftSet(int pwr);

  void liftStop();

  void toPos();

  void setPos(double ang);
};
