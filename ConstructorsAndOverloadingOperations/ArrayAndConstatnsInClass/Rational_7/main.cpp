#include <iostream>

#include "rational7.h"

int main( ) {
  Rational7 r(
      "11111/"
      "1111111111111111111111111111111111111111111" );
  auto x = r.Summa_2_Arrays( r.chislitel_, r.chislitel_size_, r.znamenatel_,
                             r.znamenatel_size_ );
  for ( int i = x.second - 1; i >= 0; --i ) {
    std::cout << static_cast< char >( x.first[ i ] + '0' );
  }
}
