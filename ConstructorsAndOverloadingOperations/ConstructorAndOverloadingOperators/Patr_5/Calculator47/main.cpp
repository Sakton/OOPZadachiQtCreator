#include <iostream>

#include "calculator47.h"
#include "fraction35.h"

int main( ) {
  Calculator47 calc;
  // std::cout << calc.Parse(
  //    "- ( ( ( 11.11 + 22.22 ) * 33.33 ) + ( 44.44 / 55.55 ) )" );
  // calc( "- ( ( ( 11 + 22 ) * 33 ) + ( 44 / 55 ) )" ).Display( );
  calc( "( ( ( 1 + 2 ) * 3 ) + ( 4 / 5 ) )" ).Display( );
  calc( "( ( ( 11 + 22 ) * 33 ) + ( 44 / 55 ) )" ).Display( );
}
