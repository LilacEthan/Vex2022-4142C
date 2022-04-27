using namespace vex;

class MBG{
 public:
  bool fStatus;
  bool bStatus;

  void setFrnt(bool pos);

  void setBack(bool pos);

  void waitFrnt();
  void waitBack();

  bool inFrnt();

  bool inBack();

  void autoClamp(bool side);
};
