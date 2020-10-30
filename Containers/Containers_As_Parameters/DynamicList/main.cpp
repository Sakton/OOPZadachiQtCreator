#include <iostream>

#include "dynamiclist.h"

void printList( const DynamicList &dl ) {
  for ( auto it = dl.begin( ); it != dl.end( ); ++it ) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main( ) {
  {
    try {
      DynamicList lst;
      lst.push_back( 10 );
      printList( lst );

      lst.pop_back( );
      if ( !lst.empty( ) ) printList( lst );
      //      lst.pop_back( );

      std::cerr << "debug point 1" << std::endl;

    } catch ( NullNodeException &e ) {
      std::cerr << e.what( ) << std::endl;
    } catch ( std::exception &e ) {
      std::cerr << e.what( ) << std::endl;
    }
  }

  return 0;
}
