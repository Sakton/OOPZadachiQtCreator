#include <ctime>
#include <iostream>
#include <list>

#include "listiteratorasmethod.h"

const int N = 6;

void printList( ListIteratorAsMethod &dl );
void fillList( ListIteratorAsMethod &list, int n );

void testList( ListIteratorAsMethod &dl );

//***functions
ListIteratorAsMethod::const_iterator foo1( ListIteratorAsMethod &list );
ListIteratorAsMethod::const_iterator foo2( ListIteratorAsMethod &list );

//**

int main( ) {
  {
    // driver for tasks
    try {
      using func = ListIteratorAsMethod::const_iterator ( * )( ListIteratorAsMethod & list );
      //тут меняем функции
      ListIteratorAsMethod list;
      //      fillList( list, N );
      //      printList( list );

      testList( list );

      //****************************
      //      func f = foo1;
      //      f( list );
      //******************************
      printList( list );
    } catch ( ... ) {
      std::cerr << "ERROR";
    }
  }

  return 0;
}

// void printList( ListIteratorAsMethod &dl ) {
//  auto it = dl.begin( );
//  for ( ; it != dl.end( ); it = ++dl ) {
//    std::cout << it->item_ << " ";
//  }
//  std::cout << std::endl;
//}

// void fillList( ListIteratorAsMethod &list, int n ) {
//  std::srand( std::time( nullptr ) );
//  for ( int i = 0; i < n; ++i ) {
//    int r = rand( ) % 50;
//    list.push_back( r * ( ( r % 2 ) ? -1 : 1 ) );
//  }
//}

// ListIteratorAsMethod::const_iterator foo1( ListIteratorAsMethod &list ) {
//  double max = 0;
//  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( ); it = ++list ) {
//    if ( max < it->item_ ) {
//      max = it->item_;
//    }
//  }
//  ListIteratorAsMethod::const_iterator endIt = list.end( );
//  endIt = --list;
//  double endEl = endIt->item_;

//  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( ); it = ++list ) {
//    it->item_ *= std::sqrt( std::abs( max * endEl ) );
//  }
//  return list.begin( );
//}

// ListIteratorAsMethod::const_iterator foo2( ListIteratorAsMethod &list ) {
//  auto fNeg = *std::find_if( list.begin( ), list.end( ), []( int el ) { return el < 0; } );
//}

void testList( ListIteratorAsMethod &dl ) {
  // std::cout << *dl.begin( );
  std::cout << "dl = " << *dl.begin( ) << std::endl;
  //  dl.push_back( 100 );
  //  dl.push_back( 200 );
  //  dl.push_back( 300 );
  //  dl.push_back( 400 );
  // std::cout << "dl = " << *dl.begin( ) << std::endl;
  //++dl;
  // std::cout << "dl = " << *dl << std::endl;
  std::list< int > s;
  s.push_back( 111 );
  std::cout << *s.begin( ) << std::endl;
}
