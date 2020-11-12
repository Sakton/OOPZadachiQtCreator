#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <numeric>

#include "dynamicarray.h"

using value_type = double;
// utulities
void generateArr( value_type arr[], int n );
void printArr( value_type arr[], int n );
void printArr( const DynamicArray &arr );
// algorithm
template < typename T >
T tMax( T *arr, int n );
double root( double x );
template < typename T >
T tMin( T *arr, int n );
//**
void f( );

DynamicArray foo1( value_type arr[], int n );
DynamicArray foo2( value_type arr[], int n );
DynamicArray foo3( value_type arr[], int n );
DynamicArray foo4( value_type arr[], int n );
DynamicArray foo5( value_type arr[], int n );
DynamicArray foo6( value_type arr[], int n );
DynamicArray foo7( value_type arr[], int n );
DynamicArray foo8( value_type arr[], int n );
// DynamicArray foo9( value_type arr[], int n );
// DynamicArray foo10( value_type arr[], int n );
// DynamicArray foo11( value_type arr[], int n );
// DynamicArray foo12( value_type arr[], int n );
// DynamicArray foo13( value_type arr[], int n );
// DynamicArray foo14( value_type arr[], int n );
// DynamicArray foo15( value_type arr[], int n );
// DynamicArray foo16( value_type arr[], int n );
// DynamicArray foo17( value_type arr[], int n );
// DynamicArray foo18( value_type arr[], int n );
// DynamicArray foo19( value_type arr[], int n );
// DynamicArray foo20( value_type arr[], int n );

int main( ) {
  set_unexpected( f );

  try {
    const int N = 6;
    value_type *arr = new value_type[ N ];
    std::srand( std::time( nullptr ) );
    generateArr( arr, N );
    printArr( arr, N );
    std::cout << std::endl;
    //****************   program Driver   ******************
    //
    using p_funktion = DynamicArray ( * )( value_type arr[], int n );
    p_funktion funk = foo7;
    //******************************************************
    DynamicArray darr = funk( arr, N );
    printArr( darr );
    //******************************************************

    std::cin >> darr;
    //******
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
    arr[ i ] = rand * ( ( rand % 3 ) ? -1 : 1 );
  }
}

void printArr( value_type arr[], int n ) {
  for ( int i = 0; i < n; ++i ) {
    std::cout << std::setprecision( 2 ) << std::fixed << std::setw( 8 )
              << arr[ i ] << ' ';
    if ( i != 0 && !( i % 10 ) ) std::cout << '\n';
  }
}

void printArr( const DynamicArray &daar ) {
  int i = 1;
  for ( auto it = daar.begin( ); it != daar.end( ); ++it ) {
    std::cout << std::fixed << std::setprecision( 2 ) << std::setw( 8 ) << *it
              << ' ';
    if ( !( i++ % 10 ) ) std::cout << std::endl;
  }
}

void f( ) { throw std::runtime_error( "RUNTIME ERROR" ); }

double root( double x ) {
  double x0 = 0;
  double root = x / 2;
  double e = 1e-4;
  while ( ( root - ( x / root ) ) > e ) {
    x0 = root;
    root = ( x0 + ( x / x0 ) ) / 2;
  }
  return root;
}

template < typename T >
T tMax( T *arr, int n ) {
  T max = std::numeric_limits< T >::min( );
  for ( int i = 0; i < n; ++i ) {
    if ( max < arr[ i ] ) max = arr[ i ];
  }
  return max;
}

template < typename T >
T tMin( T *arr, int n ) {
  value_type min = std::numeric_limits< value_type >::max( );
  std::for_each( arr, arr + n, [ & ]( value_type &el ) {
    if ( el < min ) min = el;
  } );
  return min;
}

DynamicArray foo1( value_type arr[], int n ) {
  // 1. Поиск максимума
  value_type max = tMax( arr, n );
  // 2. Вычисление корня
  double rt = root( max );
  // 3. Создание возврата
  DynamicArray res( arr, arr + n );
  //  for ( int i = 0; i < n; ++i ) {
  //    res[ i ] += rt;
  //  }
  std::for_each( res.begin( ), res.end( ),
                 [ &rt ]( value_type &el ) { el += rt; } );
  return res;
}

DynamicArray foo2( value_type arr[], int n ) {
  value_type firstNegative = 0;
  for ( value_type *it = arr; it != ( arr + n ); ++it ) {
    if ( *it < 0 ) {
      firstNegative = *it;
      break;
    }
  }
  value_type dx = ( arr[ 49 ] + firstNegative ) / 2;
  DynamicArray res( arr, arr + n );
  std::for_each( res.begin( ), res.end( ),
                 [ &dx ]( value_type &el ) { el /= dx; } );
  return res;
}

DynamicArray foo3( value_type arr[], int n ) {
  value_type max = tMax( arr, n );
  DynamicArray res( arr, arr + n );
  std::for_each( res.begin( ), res.end( ),
                 [ &max ]( value_type &el ) { el -= max; } );
  return res;
}

DynamicArray foo4( value_type arr[], int n ) {
  int min = *std::min_element( arr, arr + n );
  std::cout << "min = " << min << std::endl;
  DynamicArray res( n );
  std::transform( arr, arr + n, res.begin( ), [ & ]( int el ) { return el * min; } );
  return res;
}

DynamicArray foo5( value_type arr[], int n ) {
  int mid_arif = std::accumulate( arr, arr + n, 0, []( int acc, int el ) { return ( acc + el ); } );
  mid_arif /= n;
  std::cout << "mid_arif = " << mid_arif << std::endl;
  DynamicArray res( n );
  std::transform( arr, arr + n, res.begin( ), [ = ]( int el ) {
    if ( std::abs( el ) % 2 ) return el / mid_arif;
    return el;
  } );
  return res;
}

DynamicArray foo6( value_type arr[], int n ) {
  int summ = std::accumulate( arr, arr + n, 0, []( int acc, int el ) { return acc + el; } );
  std::cout << "summ = " << summ << std::endl;
  DynamicArray res( n );
  std::transform( arr, arr + n, res.begin( ), [ = ]( int el ) { return el - summ; } );
  return res;
}

DynamicArray foo7( value_type arr[], int n ) {
  int first_neg = *std::find_if( arr, arr + n, []( int el ) { return el < 0; } );
  int last_neg = 0;
  for ( auto it = arr + n - 1; it != arr; --it ) {
    if ( *it < 0 ) {
      last_neg = *it;
      break;
    }
  }
  int two_summ = 2 * ( first_neg + last_neg );
  std::cout << "two_summ = " << two_summ << std::endl;
  DynamicArray res( n );
  int count = 1;
  std::transform( arr, arr + n, res.begin( ), [ & ]( double el ) {
    if ( !( ( count++ ) % 3 ) ) {
      return el * two_summ;
    }
    return el;
  } );
  return res;
}

// DynamicArray foo8( value_type arr[], int n ) {}
