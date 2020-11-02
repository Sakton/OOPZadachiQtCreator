#include <iostream>
#include <iterator>

#include "array.h"

int main( ) {
  const std::size_t N1 = 10;
  const std::size_t N2 = 120;

  Array< int, N1, N2 > arr;
  arr.print( std::cout );
  std::cout << std::endl;
  //вывод
  std::cout << arr << std::endl;

  //индексирование
  for ( int i = N1; i < N2; ++i ) {
    arr[ i ] = i;
  }
  //итераторы
  std::copy( arr.begin( ), arr.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );

  // 2.
  Array< char, N1, N2 > arr1;
  arr1.print( std::cout );
  std::cout << std::endl;
  //вывод
  std::cout << arr1 << std::endl;

  //индексирование
  for ( int i = N1; i < N2; ++i ) {
    arr1[ i ] = i;
  }
  //итераторы
  std::copy( arr1.begin( ), arr1.end( ),
             std::ostream_iterator< char >( std::cout, " " ) );

  return 0;
}
