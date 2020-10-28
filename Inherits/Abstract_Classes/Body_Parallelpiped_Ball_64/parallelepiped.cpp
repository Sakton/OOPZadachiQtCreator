#include "parallelepiped.h"

#include <iostream>

Parallelepiped::Parallelepiped( double a, double b, double h )
    : a_ { a }, b_ { b }, h_ { h } {}

double Parallelepiped::Area( ) const {
  std::cout << "It's Area Parallelepiped" << std::endl;
  return 0;
}

double Parallelepiped::Volume( ) const {
  std::cout << "It's Volume Parallelepiped" << std::endl;
  return 0;
}
