#include <ctime>
#include <iostream>

#include "dynamiclist.h"

void printList( const DynamicList &dl );

void fillArray( int arr[], int n );
void printArr( int arr[], int n );

//***functions
DynamicList::con foo1( DynamicList &list );
//остальные примеры решаются аналогично
//**

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

  //  {
  //    ListIteratorAsMethod li;
  //    li.push_back( 10 );
  //    li.push_back( 20 );
  //    li.push_back( 30 );
  //    li.push_back( 40 );
  //    li.push_back( 50 );
  //    li.push_back( 60 );
  //    printList( li );
  //  }

  {
    // driver for tasks
    try {
      using func = ListIteratorAsMethod::const_iterator ( * )( ListIteratorAsMethod & list );
      //тут меняем функции
      func f = foo1;
      std::srand( std::time( nullptr ) );
      const std::size_t N = 2;
      // int *arr = new int[ N ] { 0 };
      ListIteratorAsMethod list;
      fillList( list, N );
      printList( list );
      f( list );
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

void printList( ListIteratorAsMethod &dl ) {
  auto it = dl.begin( );
  for ( ; it != dl.end( ); it = ++dl ) {
    std::cout << it->item_ << " ";
  }
  std::cout << std::endl;
}

void fillArray( int arr[], int n ) {
  for ( int i = 0; i < n; ++i ) {
    int r = rand( ) % 50;
    arr[ i ] = r * ( ( r % 2 ) ? -1 : 1 );
  }
}

void fillList( ListIteratorAsMethod &list, int n ) {
  for ( int i = 0; i < n; ++i ) {
    int r = rand( ) % 50;
    list.push_back( r * ( ( r % 2 ) ? -1 : 1 ) );
  }
}

void printArr( int arr[], int n ) {
  for ( int i = 0; i < n; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}

//***
// ListIteratorAsMethod::const_iterator foo1( ListIteratorAsMethod &list ) {
//  double max = 0;
//  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( );
//        it = ++list ) {
//    if ( max < it->item_ ) {
//      max = it->item_;
//    }
//  }

//  ListIteratorAsMethod::const_iterator endIt = list.end( );
//  endIt = --list;
//  double endEl = endIt->item_;

//  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( );
//        it = ++list ) {
//    it->item_ *= std::sqrt( std::abs( max * endEl ) );
//  }

//  return list.begin( );
//}

ListIteratorAsMethod::const_iterator foo1( ListIteratorAsMethod &list ) {
  double max = 0;
  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( ); it = list.next( ) ) {
    if ( max < it->item_ ) {
      max = it->item_;
    }
  }

  ListIteratorAsMethod::const_iterator endIt = list.end( );
  endIt = list.prev( );
  double endEl = endIt->item_;

  for ( ListIteratorAsMethod::iterator it = list.begin( ); it != list.end( ); it = list.next( ) ) {
    it->item_ *= std::sqrt( std::abs( max * endEl ) );
  }

  return list.begin( );
}
