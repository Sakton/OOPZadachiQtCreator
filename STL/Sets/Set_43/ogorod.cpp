#include "ogorod.h"

#include <algorithm>

Ogorod::Ogorod( ) { getRandomCulture( ); }

void Ogorod::clear( ) { cult_.clear( ); }

void Ogorod::getRandomCulture( ) {
  FabriqueCulture f;
  for ( int i = 0; i < 4; ++i ) {
    cult_.insert( f.random( ) );
  }
}

std::ostream &operator<<( std::ostream &out, const Ogorod &og ) {
  for ( auto &el : og.cult_ ) out << el->name( ) << std::endl;
  return out;
}

Ogorod operator+( const Ogorod &o1, const Ogorod &o2 ) {
  Ogorod temp;
  temp.clear( );
  CulturePredicat cp;
  std::set_union( o1.cult_.cbegin( ), o1.cult_.cend( ), o2.cult_.cbegin( ), o2.cult_.cend( ),
                  std::inserter( temp.cult_, temp.cult_.end( ) ), cp );
  return temp;
}

Ogorod operator-( const Ogorod &o1, const Ogorod &o2 ) {
  Ogorod temp;
  temp.clear( );
  CulturePredicat cp;
  std::set_difference( o1.cult_.cbegin( ), o1.cult_.cend( ), o2.cult_.cbegin( ), o2.cult_.cend( ),
                       std::inserter( temp.cult_, temp.cult_.end( ) ), cp );
  return temp;
}

Ogorod operator/( const Ogorod &o1, const Ogorod &o2 ) {
  Ogorod temp;
  temp.clear( );
  CulturePredicat cp;
  std::set_intersection( o1.cult_.cbegin( ), o1.cult_.cend( ), o2.cult_.cbegin( ), o2.cult_.cend( ),
                         std::inserter( temp.cult_, temp.cult_.end( ) ), cp );
  return temp;
}
