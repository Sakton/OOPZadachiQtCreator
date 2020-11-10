#include <iostream>

#include "Array8.h"

int main( ) {
  try {
    //    Array8< int > a1( 5 );
    //    std::copy( a1.cbegin( ), a1.cend( ),
    //               std::ostream_iterator< int >( std::cout, " " ) );
    //    std::cout << std::endl;
    //    Array8< int > a2( 5, 5 );
    //    std::copy( a2.cbegin( ), a2.cend( ),
    //               std::ostream_iterator< int >( std::cout, " " ) );
    //    std::cout << std::endl;
    //    a1.isert( 0, 10 );
    //    std::copy( a1.cbegin( ), a1.cend( ),
    //               std::ostream_iterator< int >( std::cout, " " ) );
    //    std::cout << std::endl;
    //    a1.isert( a1.size( ) - 1, 20 );
    //    std::copy( a1.cbegin( ), a1.cend( ),
    //               std::ostream_iterator< int >( std::cout, " " ) );
    //    std::cout << std::endl;

    // std::cout << std::max( 10, 20 );

    Array8< int > array;
    array.insert( array.size( ), 10 );
    array.insert( array.size( ), 20 );
    //    array.isert( array.size( ), 30 );
    //    array.isert( array.size( ), 40 );
    //    array.isert( array.size( ), 50 );
    //    array.isert( array.size( ), 60 );
    //    array.isert( array.size( ), 70 );
    array.insert( 0, 1 );
    array.insert( 1, 2 );
    array.insert( 2, 3 );
    array.insert( 3, 4 );
    array.insert( 4, 5 );
    array.insert( 5, 6 );
    array.insert( 6, 7 );
    array.insert( 7, 8 );
    array.insert( 8, 9 );
    array.remove( 9 );
    array.remove( 9 );
    array.remove( 9 );
    array.remove( 9 );
    array.remove( 9 );
    while ( array.size( ) ) {
      array.remove( 0 );
    }
    array.insert( 0, 1 );
    array.insert( 1, 2 );
    array.insert( 2, 3 );
    array.insert( 3, 4 );
    array.insert( 4, 5 );
    array.insert( 5, 6 );
    array.insert( 6, 7 );
    array.insert( 7, 8 );
    array.insert( 8, 9 );
    std::copy( array.cbegin( ), array.cend( ),
               std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << std::endl;

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( ... ) {
    std::cerr << "OTHER BAD" << std::endl;
  }
}
