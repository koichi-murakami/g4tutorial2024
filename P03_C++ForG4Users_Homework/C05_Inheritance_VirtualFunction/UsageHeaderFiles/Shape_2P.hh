#ifndef Shape2P_hh
#define Shape2P_hh 1

#include <string>
using namespace std;

class Shape_2P {                         
  public:
    string shape();
    double area();
  protected:
    double sizeX, sizeY;
    string name = "Shape_2P";
    const double pi = 3.14159265;
};
#endif



