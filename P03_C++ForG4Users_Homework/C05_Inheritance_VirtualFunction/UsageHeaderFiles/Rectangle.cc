#include "Rectangle.hh"

Rectangle::Rectangle( double x, double y ) { 
  sizeX = x; 
  sizeY = y;
  name = "Rectangle";
}

double Rectangle::area() { 
  return sizeX*sizeY; 
}
