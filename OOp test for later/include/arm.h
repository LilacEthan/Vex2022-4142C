//arm Class

class arm {
 public:
  bool Off;
  double tAng;
  double getAng();

  void liftSet(int pwr);

  void liftStop();

  void toPos();

  void setPos(double ang);
};
