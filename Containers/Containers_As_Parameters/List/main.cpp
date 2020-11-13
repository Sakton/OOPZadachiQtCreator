#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric>

#include "dynamiclist.h"

using value_type = int32_t;
using size_type = std::size_t;
enum { N = 6 };

void printList( const DynamicList &dl );

void fillArray( value_type arr[], size_type n );
void printArray( value_type arr[], size_type n );

//***functions
DynamicList foo1( value_type ar[], size_type n );
//************

int main( ) {
  {
    // driver for tasks
    try {
      using func = DynamicList ( * )( value_type ar[], size_type n );
      //тут меняем функции
      func f = foo1;
      std::srand( std::time( nullptr ) );
      value_type *arr = new value_type[ N ] { 0 };
      fillArray( arr, N );
      printArray( arr, N );
      //********************************************************************
      DynamicList list = f( arr, N );
      printList( list );
    } catch ( ... ) {
      std::cerr << "ERROR";
    }
  }

  return 0;
}

void printList( const DynamicList &dl ) {
  for ( auto it = dl.begin( ); it != dl.end( ); ++it ) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void printList( DynamicList &dl ) {
  auto it = dl.begin( );
  for ( ; it != dl.end( ); ++it ) {
    std::cout << *it << '\n';
  }
  std::cout << std::endl;
}

void fillArray( value_type arr[], size_type n ) {
  for ( size_type i = 0; i < n; ++i ) {
    int r = rand( ) % 50;
    arr[ i ] = r * ( ( r % 3 ) ? -1 : 1 );
  }
}

void printArray( value_type arr[], size_type n ) {
  for ( size_type i = 0; i < n; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}

// tasks
DynamicList foo1( value_type ar[], size_type n ) {
  value_type max = *std::max_element( ar, ar + n );
  value_type x = std::sqrt( std::abs( max * ar[ n - 1 ] ) );
  std::cout << '\n' << "x = " << x << std::endl;
  DynamicList dl( n );
  std::transform( ar, ar + n, dl.begin( ), [ = ]( value_type el ) { return el * x; } );
  return dl;
}
