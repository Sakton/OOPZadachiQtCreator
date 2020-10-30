#include <iostream>

#include "dynamiclist.h"
#include "listiteratorasmethod.h"

void printList( const DynamicList &dl );
void printList( const ListIteratorAsMethod &dl );

int main( ) {
  //  {
  //    try {
  //      DynamicList lst;
  //      lst.push_back( 10 );
  //      lst.push_back( 20 );
  //      lst.push_back( 30 );
  //      lst.push_back( 40 );
  //      lst.push_back( 50 );
  //      printList( lst );
  //      lst.clear( );
  //      if ( !lst.empty( ) ) printList( lst );

  //      //      std::cerr << "debug point 1" << std::endl;

  //    } catch ( NullNodeException &e ) {
  //      std::cerr << e.what( ) << std::endl;
  //    } catch ( std::exception &e ) {
  //      std::cerr << e.what( ) << std::endl;
  //    }
  //  }

  {
    ListIteratorAsMethod li;
    li.push_back( 10 );
    li.push_back( 20 );
    li.push_back( 30 );
    li.push_back( 40 );
    li.push_back( 50 );
    li.push_back( 60 );
    printList( li );
  }

  return 0;
}

void printList( const DynamicList &dl ) {
  for ( auto it = dl.begin( ); it != dl.end( ); ++it ) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void printList( const ListIteratorAsMethod &dl ) {
  for ( auto it = dl.begin( ); it != dl.end( ); ++it ) {
    std::cout << it->item_ << " ";
  }
  std::cout << std::endl;
}
