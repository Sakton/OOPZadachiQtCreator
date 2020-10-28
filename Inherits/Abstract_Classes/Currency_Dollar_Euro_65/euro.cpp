#include "euro.h"

#include <iostream>

Euro::Euro( double sum ) : sum_ { sum } {}

double Euro::change( ) const {
  std::cout << "Change Euro" << std::endl;
  return 0;
}
void Euro::display( ) const { std::cout << "Display Euro" << std::endl; }
