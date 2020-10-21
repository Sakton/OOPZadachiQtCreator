#include <iostream>

#include "calculator44.h"
#include "calculator44private.h"
#include "fraction35.h"

int main( ) {
  Calculator44 calc;
  calc( "- ( ( ( 11 + 22 ) * 33 ) + ( 44 / 55 ) )" ).Display( );

  Calculator44private pcalc;
  pcalc( "- ( ( ( 11 + 22 ) * 33 ) + ( 44 / 55 ) )" ).Display( );
}
