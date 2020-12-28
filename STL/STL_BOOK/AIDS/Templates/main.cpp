#include <iostream>

template < typename T >
void print( T arg ) {
  std::cout << arg << " ";
}

template < typename T, typename... Types >
void print( T first, Types... arg ) {
  print( first );
  print( arg... );
}

int main( ) { print( 1, "Hello", std::string( "World" ), 2.23F, "ersdfsdcasdcz" ); }
