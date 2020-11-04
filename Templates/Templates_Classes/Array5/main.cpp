#include <iostream>

#include "Array5.h"

int main( ) {
  Array5< int > arr;
  arr.push_back( 100 );
  arr.push_back( 200 );
  arr.push_back( 300 );
  arr.push_back( 100 );
  arr.push_back( 200 );
  arr.push_back( 300 );
  arr.push_back( 100 );
  arr.push_back( 200 );
  arr.push_back( 300 );
  arr.push_back( 666 );
  arr.push_back( 555 );
  arr.push_back( 222 );
  arr.push_back( 111 );

  for ( int i = arr.size( ) - 1; !arr.empty( ); --i ) {
    std::cout << arr.back( ) << " ";
    arr.pop_back( );
  }
  std::cout << std::endl;
  std::cout << "size = " << arr.size( ) << std::endl;

  int a[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  Array5< int > arr2( a, a + 9 );
  std::cout << arr2 << std::endl;
}
