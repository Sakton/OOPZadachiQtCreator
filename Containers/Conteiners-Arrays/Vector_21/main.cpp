#include <iostream>

#include "vector.h"

void printArray( const MY::Vector &vec );

int main( ) {
  MY::Vector::value_type arr[ 10 ] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  MY::Vector vec( arr, arr + 10 );
  MY::Vector vec1( 0, 1 );
}

void printArray( const MY::Vector &vec ) {}
