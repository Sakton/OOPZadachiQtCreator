#include <algorithm>
#include <ctime>
#include <iostream>

#include "poligon.h"

void print( const Poligon &pl );

int main( ) {
  enum { SIZE = 3 };
  using Points = std::pair< double, double >;
  Points point[ SIZE ];
  std::srand( std::time( nullptr ) );
  for ( int i = 0; i < SIZE; ++i ) {
    point[ i ].first = std::rand( ) % 50;
    point[ i ].second = std::rand( ) % 50;
  }

  Points p[ 3 ] { { 16, 19 }, { 6, 9 }, { 49, 40 } };

  Poligon poligon( p, SIZE );
  print( poligon );
  std::cout << "S = " << poligon.area( ) << std::endl;
  std::cout << "P = " << poligon.perimetr( ) << std::endl;
}

void print( const Poligon &pl ) {
  std::for_each( pl.begin( ), pl.end( ),
                 []( const Poligon::value_type &el ) { std::cout << el.first << " : " << el.second << std::endl; } );
}
