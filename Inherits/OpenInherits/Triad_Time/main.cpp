#include <iostream>

#include "time.h"

Triad& foo( Triad& tr ) {
  tr.show( std::cout );
  std::cout << std::endl;
  return tr;
}

int main( ) {
  Time t( 20, 30, 10 );
  t.show( std::cout );
  std::cout << std::endl;
  t.AddSecund( 300 );
  t.show( std::cout );
  std::cout << std::endl;
  t.AddMinut( 300 );
  t.show( std::cout );
  std::cout << std::endl;
  std::cout << "******************" << std::endl;
  Triad ttr( 1000, 2000, 3000 );
  std::cout << std::endl;
  foo( ttr );
  std::cout << std::endl;
  Triad* trr = &foo( t );
  trr->show( std::cout );
  std::cout << std::endl;
}
