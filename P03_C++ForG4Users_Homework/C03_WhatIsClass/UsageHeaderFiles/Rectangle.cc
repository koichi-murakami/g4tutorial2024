#include "Rectangle.hh"

Rectangle:: Rectangle( double x, double y ) { 
  sizeX = x; 
  sizeY = y;
}

double Rectangle::area() { 
  return sizeX*sizeY; 
}
