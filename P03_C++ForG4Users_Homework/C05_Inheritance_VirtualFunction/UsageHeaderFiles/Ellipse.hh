#ifndef Ellipse_hh
#define Ellipse_hh

#include "Shape_2P.hh"

class Ellipse : public Shape_2P {
  public:
    Ellipse( double x, double y );
    double area();
};
#endif
