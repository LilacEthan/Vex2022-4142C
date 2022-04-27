using namespace vex ;

class brainScreen {

 public:
 int w = 60;
 int l = 60;

 int awpX = 100; 
 int awpY = 20;

 int nonAwpX = 300;
 int nonAwpY = 20;
  

  enum Autoselection{ awpLine = 1, nonAwp = 2};

  Autoselection selectedAuto;


  // int selectedAuto = 0;
  void background();

  void selection();

  void reset();

  void checking();
};