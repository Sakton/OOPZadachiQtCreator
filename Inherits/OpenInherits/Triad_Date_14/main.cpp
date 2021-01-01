#include <iostream>

#include "date.h"

Triad &foo( Triad &tr ) {
  tr.Show( std::cout );
  return tr;
}

int main( ) {
  Date d( 31, 12, 2020 );
  std::cout << d << std::endl;
  d.firstNext( );
  d.secondNext( );
  d.thirdNext( );
  std::cout << d << std::endl;
}
