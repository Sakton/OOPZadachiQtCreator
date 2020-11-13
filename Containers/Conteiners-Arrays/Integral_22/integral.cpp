#include "integral.h"

#include <algorithm>
#include <iostream>
#include <new>

Integral::Integral( const Integral::value_type arr[], Integral::size_type n ) : data_ { nullptr }, sz_ { n } {
  if ( n == 0 ) throw std::bad_alloc( );
  data_ = new value_type[ n ];
  std::copy( arr, arr + n, data_ );
}

Integral::Integral( Integral::const_iterator beg, Integral::const_iterator end ) : data_ { nullptr }, sz_ { 0 } {
  if ( beg == end ) throw std::bad_alloc( );
  auto i = beg;
  while ( i != end ) {
    ++sz_;
    ++i;
  }
  data_ = new value_type[ sz_ ];
  std::copy( beg, end, data_ );
}

Integral::~Integral( ) { delete[] data_; }

Integral::Integral( const Integral& other ) : data_ { new value_type[ other.size( ) ] }, sz_ { other.size( ) } {
  std::copy( other.begin( ), other.end( ), data_ );
}

Integral::Integral( Integral&& other ) : data_ { other.data_ }, sz_ { other.size( ) } { other.data_ = nullptr; }

const Integral& Integral::operator=( const Integral& other ) {
  if ( this != &other ) {
    Integral tmp = other;
    swap( tmp );
  }
  return *this;
}

const Integral& Integral::operator=( Integral&& other ) {
  std::cout << "move = " << std::endl;
  if ( this != &other ) {
    swap( other );
  }
  return *this;
}

Integral::iterator Integral::begin( ) { return const_cast< value_type* >( static_cast< const Integral& >( *this ).begin( ) ); }

Integral::const_iterator Integral::begin( ) const { return data_; }

Integral::iterator Integral::end( ) { return const_cast< value_type* >( static_cast< const Integral& >( *this ).end( ) ); }

Integral::const_iterator Integral::end( ) const { return data_ + sz_; }

Integral::reference Integral::operator[]( Integral::size_type idx ) {
  return const_cast< Integral::reference >( static_cast< const Integral& >( *this )[ idx ] );
}

Integral::const_reference Integral::operator[]( Integral::size_type idx ) const {
  if ( idx < 0 || ( sz_ - 1 ) < idx ) throw std::out_of_range( "OUT OF RANGE" );
  return data_[ idx ];
}

Integral::size_type Integral::size( ) const { return sz_; }

void Integral::swap( Integral& other ) {
  std::swap( data_, other.data_ );
  std::swap( sz_, other.sz_ );
}

double Integral::methodRectangle( ) const {
  double s = 0;
  for ( size_type i = 1; i < sz_; ++i ) {
    s += ( static_cast< double >( data_[ i - 1 ] + data_[ i ] ) / 2 ) * ( data_[ i ] - data_[ i - 1 ] );
  }
  return s;
}

double Integral::methodTrapecy( ) const {
  double f = ( static_cast< double >( ( *this )[ 1 ] ) / 2 ) * ( ( *this )[ 1 ] - ( *this )[ 0 ] );
  for ( size_type i = 1; i < sz_ - 1; ++i ) {
    f += ( static_cast< double >( ( *this )[ i ] ) / 2 ) * ( ( *this )[ i + 1 ] - ( *this )[ i - 1 ] );
  }
  f += ( static_cast< double >( ( *this )[ sz_ - 1 ] ) / 2 ) * ( ( *this )[ sz_ - 1 ] - ( *this )[ sz_ - 2 ] );
  return f;
}

double Integral::methodSimpson( ) const {
  double k = static_cast< double >( ( *this )[ sz_ - 1 ] - ( *this )[ 0 ] ) / ( 3 * ( sz_ ) );
  double t = 0;
  for ( size_type i = 1; i < sz_ - 2; i += 2 ) {
    t += ( ( *this )[ i - 1 ] + 4 * ( *this )[ i ] + ( *this )[ i + 1 ] );
  }
  return k * t;
}
