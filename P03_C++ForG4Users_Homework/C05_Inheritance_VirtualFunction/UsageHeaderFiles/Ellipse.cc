#include "Ellipse.hh"

Ellipse::Ellipse( double x, double y ) { 
  sizeX = x; 
  sizeY = y;
  name = "Ellipse";
}

double Ellipse::area() { 
  return sizeX*sizeY*pi/4.0; 
}
