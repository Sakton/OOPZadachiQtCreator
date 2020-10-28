#include "ball.h"

#include <iostream>

Ball::Ball( double r ) : r_ { r } {}

double Ball::Area( ) const {
  std::cout << "It's Area Ball" << std::endl;
  return 0;
}

double Ball::Volume( ) const {
  std::cout << "It's Volume Ball" << std::endl;
  return 0;
}
