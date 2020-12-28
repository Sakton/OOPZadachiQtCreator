#include <iostream>
#include <vector>

template < typename T >
void print( T arg ) {
  std::cout << arg << " ";
}

template < typename T, typename... Types >
void print( T first, Types... arg ) {
  print( first );
  print( arg... );
}

template < typename C, typename... Idx >
void printElems( const C& cont, Idx... index ) {
  print( cont[ index ]... );
}

int main( ) {
  print( 1, "Hello", std::string( "World" ), 2.23F, "ersdfsdcasdcz" );
  std::vector< std::string > v { "one", "two", "tree", "for" };
  printElems( v, 0, 0, 3, 3, 2, 1, 2, 3, 0, 1, 1, 1, 2, 3 );
}
