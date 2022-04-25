using namespace vex;

class MBG{
 public:
  bool fStatus;
  bool bStatus;

  void setFrnt(bool pos);

  void setBack(bool pos);

  bool inFrnt();

  bool inBack();

  void autoClamp(bool side);
};

void mbg(bool take);

void clamp (bool pos);


