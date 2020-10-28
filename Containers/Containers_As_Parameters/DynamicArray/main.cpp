#include <cstdlib>
#include <ctime>
#include <iostream>

#include "dynamicarray.h"

using value_type = double;

void generateArr( value_type arr[], int n );
void printArr( value_type arr[], int n );

void f( );

int main( ) {
  set_unexpected( f );

  try {
    DynamicArray da;
    value_type *arr = new value_type[ 100 ];

    std::srand( std::time( nullptr ) );
    generateArr( arr, 100 );
    printArr( arr, 100 );

    DynamicArray da1( arr, arr + 100 );

    delete[] arr;
  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( );
  }
}

void generateArr( value_type arr[], int n ) {
  for ( int i = 0; i < n; ++i ) {
    int rand = std::rand( ) % 50;
    arr[ i ] = rand * ( ( rand % 2 ) ? -1 : 1 );
  }
}

void printArr( value_type arr[], int n ) {
  for ( int i = 0; i < n; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
  std::cout << std::endl;
}

void f( ) { throw std::runtime_error( "RUNTIME ERROR" ); }
