#include "rectangle.h"

#include <iostream>

Rectangle::Rectangle( double a, double b ) : a_ { a }, b_ { b } {
  std::cout << "i'm rectangle" << std::endl;
}

double Rectangle::Area( ) { return a_ * b_; }

double Rectangle::Perimeter( ) { return 2 * ( a_ + b_ ); }
