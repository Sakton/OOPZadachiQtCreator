#include <iostream>

#include "Array5.h"
// Array 5 & 6

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
  arr.push_back( 600 );
  arr.push_back( 500 );
  arr.push_back( 200 );
  arr.push_back( 100 );

  //  for ( int i = arr.size( ) - 1; !arr.empty( ); --i ) {
  //    std::cout << arr.back( ) << " ";
  //    arr.pop_back( );
  //  }
  std::cout << std::endl;
  std::cout << "size = " << arr.size( ) << std::endl;

  int a[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  Array5< int > arr2( a, a + 9 );
  std::cout << arr2 << std::endl;

  Array5< int > arr3 = ( arr + arr2 );
  std::cout << arr3 << std::endl;
  Array5< int > arr4 = ( arr - arr2 );
  std::cout << arr4 << std::endl;
  Array5< int > arr5 = arr * arr2;
  std::cout << arr5 << std::endl;
  Array5< int > arr6 = arr / arr2;
  std::cout << arr6 << std::endl;
}
