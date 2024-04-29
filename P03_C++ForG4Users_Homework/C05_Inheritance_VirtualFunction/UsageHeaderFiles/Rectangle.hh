#ifndef Rectangle_hh
#define Rectangle_hh

#include "Shape_2P.hh"

class Rectangle : public Shape_2P {
  public:
    Rectangle( double x, double y );
    double area();
};
#endif
