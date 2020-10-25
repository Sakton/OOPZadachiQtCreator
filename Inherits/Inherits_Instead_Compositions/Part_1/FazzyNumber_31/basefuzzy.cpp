#include "basefuzzy.h"

#include <iostream>
#include <sstream>

BaseFuzzy::BaseFuzzy( double e1, double x, double e2 )
    : e1_ { e1 }, x_ { x }, e2_ { e2 } {}

void Display( const BaseFuzzy& fn ) {
  std::cout << ToString( fn ) << std::endl;
}

std::string ToString( const BaseFuzzy& fn ) {
  std::stringstream ss;
  ss << "( " << fn.x_ << "-" << std::abs( fn.e1_ ) << ", " << fn.x_ << ", "
     << fn.x_ << "+" << std::abs( fn.e1_ ) << " )";
  return ss.str( );
}
