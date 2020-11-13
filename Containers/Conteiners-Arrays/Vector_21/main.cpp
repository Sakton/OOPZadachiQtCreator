#include <iostream>

#include "vector.h"

void printVector( const MY::Vector &vec );

int main( ) {
  try {
    MY::Vector::value_type arr[ 10 ] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    MY::Vector vec( arr, arr + 10 );

    MY::Vector vec1( 10, 1 );
    printVector( vec1 );

  } catch ( std::bad_alloc &e ) {
    std::cerr << e.what( );
  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( );
  }
}

void printVector( const MY::Vector &vec ) {
  std::copy( vec.begin( ), vec.end( ), std::ostream_iterator< MY::Vector::value_type >( std::cout, " " ) );
}
