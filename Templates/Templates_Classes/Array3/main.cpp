#include <iostream>

#include "Array3.h"

int main( ) {
  try {
    Array3< int, 10, 15 > arr;
    //  arr.print( std::cout );
    std::cout << arr << std::endl;
    for ( int i = arr.LEFT; i < arr.RIGHT; ++i ) arr[ i ] = 100 + i + 10;
    std::cout << arr << std::endl;
    // std::cin >> arr;
  } catch ( std::range_error e ) {
    std::cerr << e.what( ) << std::endl;
  }
}
