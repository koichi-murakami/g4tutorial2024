#include <iostream>
#include "Rectangle.hh"
using namespace std;

int main() {
  Rectangle rect{ 3.0, 4.0 };
  cout << "Area: " << rect.area() << endl;
}