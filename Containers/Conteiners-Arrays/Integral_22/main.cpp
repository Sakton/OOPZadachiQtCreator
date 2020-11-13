#include <iostream>

#include "integral.h"

void printIntegral( const Integral& igr );

int main( ) {
  int arr[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  Integral in1( arr, 10 );
  printIntegral( in1 );
  std::cout << std::endl;
  Integral in2( arr, arr + 10 );
  printIntegral( in2 );
  std::cout << std::endl;
  int arr1[] { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
  in1 = Integral( arr1, arr1 + 10 );
  printIntegral( in1 );
  std::cout << std::endl;

  std::cout << "methosRectangle = " << in1.methodRectangle( ) << std::endl;
  std::cout << "methodTrapecy = " << in1.methodTrapecy( ) << std::endl;
  std::cout << "methodSimpson = " << in1.methodSimpson( ) << std::endl;
}

void printIntegral( const Integral& igr ) { std::copy( igr.begin( ), igr.end( ), std::ostream_iterator< Integral::value_type >( std::cout, " " ) ); }
