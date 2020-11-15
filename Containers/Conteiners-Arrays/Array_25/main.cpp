#include <iostream>

#include "array25_27_29.h"

void print( const ArrayGeneral &ar );
const ArrayGeneral foo( );

int main( ) {
  try {
    //************************************************
    ArrayGeneral a_1( -50, -40, -45 );
    ArrayGeneral a_2( -40, -30, -35 );
    ArrayGeneral a_3( -30, -20, -25 );
    ArrayGeneral a_4( -20, -10, -15 );
    ArrayGeneral a_5( -10, 0, -5 );
    ArrayGeneral a_6( 0, 10, 5 );
    ArrayGeneral a_7( 10, 20, 15 );
    print( a_1 );
    print( a_2 );
    print( a_3 );
    print( a_4 );
    print( a_5 );
    print( a_6 );
    print( a_7 );

    ArrayGeneral t_1 = a_1 - a_2 - a_4 - a_6;
    print( t_1 );
    ArrayGeneral t_2 = a_1 + a_2 / a_4 * a_6;
    print( t_2 );
    ArrayGeneral t_3 = ( a_1 + 200 ) + ( a_2 / 10 ) / a_4 * a_6 * ( 3 - a_7 ) * 50;
    print( t_3 );

    int arr[] { 123, 456, 789, 111, 1, 23, 25, 321, 222, -156 };
    ArrayGeneral forsort( arr, arr + 10, 0 );
    print( forsort );
    std::cout << "max = " << forsort.max( ) << std::endl;
    std::cout << "min = " << forsort.min( ) << std::endl;
    std::cout << "mid = " << forsort.midleArifvetic( ) << std::endl;
    forsort.sort( );
    print( forsort );
    ArrayGeneral g1( 0, 10, 0 ), g2( 0, 10, 0 ), g3( 0, 10, 0 );
    g1 = g2 = g3 = a_1;
    //************************************************
  } catch ( std::bad_alloc &e ) {
    std::cerr << e.what( );
  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( );
  } catch ( ... ) {
    std::cerr << "OTHER";
  }
}

void print( const ArrayGeneral &ar ) {
  std::copy( ar.begin( ), ar.end( ), std::ostream_iterator< ArrayGeneral::value_type >( std::cout, " " ) );
  std::cout << '\n';
}

const ArrayGeneral foo( ) { return ArrayGeneral( -100, -90, 33 ); }
