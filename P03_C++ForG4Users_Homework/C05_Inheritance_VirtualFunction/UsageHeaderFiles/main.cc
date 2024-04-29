#include <iostream>
#include <string>
#include "Shape_2P.hh"
#include "Rectangle.hh"
#include "Ellipse.hh"
using namespace std;

int main() {
  Shape_2P pict{ };
  cout << "Shape: " << pict.shape() << endl;
  cout << "Area: "  << pict.area()  << endl;

  Rectangle rect{3.0, 4.0};
  cout << "Shape: " << rect.shape() << endl;
  cout << "Area: "  << rect.area()  << endl;

  Ellipse elps{5.0, 6.0};
  cout << "Shape: " << elps.shape() << endl;
  cout << "Area: "  << elps.area()  << endl;

}