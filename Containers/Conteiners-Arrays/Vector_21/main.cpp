#include <iostream>

#include "vector.h"

void printVector( const MY::Vector &vec );

int main( ) {
  try {
    MY::Vector::value_type arr[ 10 ] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    MY::Vector vec( arr, arr + 10 );
    printVector( vec );
    std::cout << std::endl;
    MY::Vector vec1( 10, 1 );
    printVector( vec1 );
    std::cout << std::endl;
    vec += vec1;
    printVector( vec );
    std::cout << std::endl;
    vec *= 2;
    printVector( vec );
    std::cout << std::endl;
    vec /= 2;
    printVector( vec );
    std::cout << std::endl;

    vec = vec1 + vec1 + vec1;
    printVector( vec );
    std::cout << std::endl;

    vec = vec - vec1 * 2;
    printVector( vec );
    std::cout << std::endl;

    vec = vec1 * 25;
    printVector( vec );
    std::cout << std::endl;

    vec = 33 * vec1;
    printVector( vec );
    std::cout << std::endl;

    MY::Vector euck( 4, 4 );
    std::cout << "euckNorm = " << euck.euclidNorm( ) << std::endl;

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
