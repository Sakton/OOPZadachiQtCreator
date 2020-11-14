#include <algorithm>
#include <iostream>

#include "array.h"
template < class T, class Iterator >
void print( Iterator beg, Iterator end );

int main( ) {
  MY::Array ar1( 10, 300 );
  print< MY::Array::value_type >( ar1.begin( ), ar1.end( ) );
  std::cout << std::endl;

  double array[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  MY::Array ar2( array, array + 10 );
  print< MY::Array::value_type >( ar2.begin( ), ar2.end( ) );
  std::cout << std::endl;

  ar1 += ar2;
  print< MY::Array::value_type >( ar1.begin( ), ar1.end( ) );
  std::cout << std::endl;

  MY::Array ar3 = ar1 - ar2;
  print< MY::Array::value_type >( ar3.begin( ), ar3.end( ) );
  std::cout << std::endl;

  std::cout << std::boolalpha << ( ar3 == ar2 ) << std::endl;

  MY::Array res = ar1 * ar2 - ( ar2 * ar2 ) + ar3 / ar2;
  print< MY::Array::value_type >( res.begin( ), res.end( ) );
  std::cout << std::endl;
}

template < class T, class Iterator >
void print( Iterator beg, Iterator end ) {
  std::copy( beg, end, std::ostream_iterator< T >( std::cout, " " ) );
}
