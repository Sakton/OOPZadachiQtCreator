#include "circle.h"

#include <iostream>

const double PI = 3.14;

Circle::Circle( double r ) : r_ { r } {
  std::cout << "i'm circle" << std::endl;
}

double Circle::Area( ) { return PI * r_ * r_; }

double Circle::Perimeter( ) { return 2 * PI * r_; }
