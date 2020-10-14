#include "rightangled.h"

#include <cmath>
#include <iostream>

RightAngled::RightAngled( double c1, double c2 ) : Pair10( c1, c2 ) {}

void RightAngled::Display( ) {
  Pair10::Display( );
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

RightAngled::operator std::string( ) {
  return " area: =" + std::to_string( Area( ) ) +
         " Hyp = " + std::to_string( Hypotenuse( ) );
}

double RightAngled::Hypotenuse( ) {
  return std::sqrt( first( ) * first( ) + second( ) * second( ) );
}

double RightAngled::Area( ) { return Mult( ) / 2; }
