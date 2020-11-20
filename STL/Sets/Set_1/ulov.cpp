#include "ulov.h"

#include <algorithm>
#include <vector>
Ulov::Ulov( ) {}

void Ulov::push( std::shared_ptr< IFish > f ) { ulov_.insert( f ); }

size_t Ulov::size( ) const { return ulov_.size( ); }

std::ostream& operator<<( std::ostream& out, const Ulov& r ) {
  for ( auto& f : r.ulov_ ) out << *f << std::endl;
  return out;
}

const Ulov operator+( const Ulov& u1, const Ulov& u2 ) {
  Ulov temp;
  Predicat pr;
  std::set_union( u1.ulov_.cbegin( ), u1.ulov_.cend( ), u2.ulov_.cbegin( ), u2.ulov_.cend( ),
                  std::inserter( temp.ulov_, temp.ulov_.begin( ) ), pr );
  return temp;
}

const Ulov operator-( const Ulov& u1, const Ulov& u2 ) {
  Ulov temp;
  Predicat pr;
  std::set_difference( u1.ulov_.cbegin( ), u1.ulov_.cend( ), u2.ulov_.cbegin( ), u2.ulov_.cend( ),
                       std::inserter( temp.ulov_, temp.ulov_.begin( ) ), pr );
  return temp;
}

const Ulov operator/( const Ulov& u1, const Ulov& u2 ) {
  Ulov temp;
  Predicat pr;
  std::set_intersection( u1.ulov_.cbegin( ), u1.ulov_.cend( ), u2.ulov_.cbegin( ), u2.ulov_.cend( ),
                         std::inserter( temp.ulov_, temp.ulov_.begin( ) ), pr );
  return temp;
}
