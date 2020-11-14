#include "poligon.h"

#include <cmath>
#include <numeric>
#include <stdexcept>

Poligon::Poligon( const value_type points[], size_type n ) : size_ { n }, data_ { new value_type[ n ] } {
  std::copy( points, points + n, data_.get( ) );
}

Poligon::const_iterator Poligon::begin( ) const { return data_.get( ); }

Poligon::const_iterator Poligon::end( ) const { return data_.get( ) + size_; }

Poligon::iterator Poligon::begin( ) { return const_cast< Poligon::iterator >( static_cast< const Poligon& >( *this ).begin( ) ); }

Poligon::iterator Poligon::end( ) { return const_cast< Poligon::iterator >( static_cast< const Poligon& >( *this ).end( ) ); }

Poligon::const_reference Poligon::operator[]( Poligon::size_type idx ) const {
  validIndex( idx );
  return data_[ idx ];
}

Poligon::reference Poligon::operator[]( Poligon::size_type idx ) {
  return const_cast< Poligon::reference >( static_cast< const Poligon& >( *this )[ idx ] );
}

double Poligon::area( ) const {
  double S = 0;
  size_type i = 0;
  for ( ; i < size_ - 1; ++i ) {
    S += ( ( ( *this )[ i ].first - ( *this )[ i + 1 ].first ) * ( ( *this )[ i ].second + ( *this )[ i + 1 ].second ) ) / 2.0;
  }
  S += ( ( ( *this )[ i ].first - ( *this )[ 0 ].first ) * ( ( *this )[ i ].second + ( *this )[ 0 ].second ) ) / 2.0;
  return std::abs( S );
}

double Poligon::perimetr( ) const {
  double P = 0;
  size_type i = 0;
  for ( ; i < size_ - 1; ++i ) {
    P += lenStraight( ( *this )[ i ], ( *this )[ i + 1 ] );
  }
  P += lenStraight( ( *this )[ i ], ( *this )[ 0 ] );
  return P;
}

void Poligon::validIndex( Poligon::size_type idx ) const {
  if ( idx < 0 || size_ <= idx ) throw std::out_of_range( "OUT INDEX" );
}

double Poligon::lenStraight( Poligon::const_reference a, Poligon::const_reference b ) const {
  return std::sqrt( std::pow( b.first - a.first, 2 ) + std::pow( b.second - a.second, 2 ) );
}
