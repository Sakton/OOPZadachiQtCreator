#include "dollar.h"

#include <iostream>

Dollar::Dollar( double sum ) : sum_ { sum } {}

double Dollar::change( ) const {
  std::cout << "Change Dollar" << std::endl;
  return 0;
}

void Dollar::display( ) const { std::cout << "Dollar Display" << std::endl; }
