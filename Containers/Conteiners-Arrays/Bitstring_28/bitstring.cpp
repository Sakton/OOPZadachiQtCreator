#include "bitstring.h"

#include <algorithm>
#include <iostream>

Bitstring::Bitstring( size_type n ) : sz_ { n }, data_ { std::make_unique< value_type[] >( n ) } {
  for ( size_type i = 0; i < n; ++i ) data_[ i ] = 0;
}

Bitstring::Bitstring( const Bitstring& rhs ) : sz_ { rhs.size( ) }, data_ { std::make_unique< value_type[] >( rhs.size( ) ) } {
  std::copy( rhs.begin( ), rhs.end( ), begin( ) );
}

Bitstring::Bitstring( Bitstring&& rhs ) : sz_ { 0 }, data_ { nullptr } {
  std::cout << "move ctor" << std::endl;
  swap( rhs );
}

Bitstring& Bitstring::operator=( const Bitstring& rhs ) {
  if ( this == &rhs ) return *this;
  Bitstring tmp = rhs;
  swap( tmp );
  return *this;
}

Bitstring& Bitstring::operator=( Bitstring&& rhs ) {
  std::cout << "move op=" << std::endl;
  if ( this != &rhs ) return *this;
  swap( rhs );
  rhs.data_ = nullptr;
  return *this;
}

Bitstring::const_iterator Bitstring::begin( ) const { return data_.get( ); }

Bitstring::const_iterator Bitstring::end( ) const { return data_.get( ) + sz_; }

Bitstring::iterator Bitstring::begin( ) { return const_cast< Bitstring::iterator >( static_cast< const Bitstring& >( *this ).begin( ) ); }

Bitstring::iterator Bitstring::end( ) { return const_cast< Bitstring::iterator >( static_cast< const Bitstring& >( *this ).end( ) ); }

Bitstring::const_reference Bitstring::operator[]( Bitstring::size_type idx ) const { return data_[ index( idx ) ]; }

Bitstring::reference Bitstring::operator[]( Bitstring::size_type idx ) {
  return const_cast< Bitstring::reference >( static_cast< const Bitstring& >( *this )[ idx ] );
}

Bitstring& Bitstring::operator&=( const Bitstring& rhs ) {
  valiLenth( rhs );
  Bitstring tmp( rhs.size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ),
                  []( const value_type& el1, const value_type& el2 ) { return ( el1 && el2 ) ? 1 : 0; } );
  swap( tmp );
  return *this;
}

Bitstring& Bitstring::operator|=( const Bitstring& rhs ) {
  valiLenth( rhs );
  Bitstring tmp( rhs.size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ),
                  []( const value_type& el1, const value_type& el2 ) { return ( !el1 && !el2 ) ? 0 : 1; } );
  swap( tmp );
  return *this;
}

Bitstring& Bitstring::operator^=( const Bitstring& rhs ) {
  valiLenth( rhs );
  Bitstring tmp( rhs.size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ),
                  []( const value_type& el1, const value_type& el2 ) { return ( ( !el1 && el2 ) || ( el1 && !el2 ) ) ? 1 : 0; } );
  swap( tmp );
  return *this;
}

Bitstring& Bitstring::operator~( ) {
  std::transform( begin( ), end( ), begin( ), []( const value_type& el1 ) { return el1 ? 0 : 1; } );
  return *this;
}

Bitstring& Bitstring::cycleShiftLeft( Bitstring::size_type n ) {
  std::shared_ptr< value_type[] > t = std::make_unique< value_type[] >( n );
  std::copy( begin( ), begin( ) + n, t.get( ) );
  ( *this ) <<= n;
  std::copy( t.get( ), t.get( ) + n, end( ) - n );
  return *this;
}

Bitstring& Bitstring::cycleShiftRight( Bitstring::size_type n ) {
  reverse( );
  cycleShiftLeft( n );
  reverse( );
  return *this;
}

Bitstring& Bitstring::operator<<=( Bitstring::size_type n ) {
  if ( size( ) <= n )
    clear( );
  else {
    size_type i = 0;
    for ( ; i < size( ) - n; ++i ) {
      ( *this )[ index( i ) ] = ( *this )[ index( n + i ) ];
    }
    for ( ; i < size( ); ++i ) {
      ( *this )[ index( i ) ] = 0;
    }
  }
  return *this;
}

Bitstring& Bitstring::operator>>=( Bitstring::size_type n ) {
  if ( size( ) <= n )
    clear( );
  else {
    reverse( );
    ( *this ) <<= n;
    reverse( );
  }
  return *this;
}

Bitstring::size_type Bitstring::size( ) const { return sz_; }

void Bitstring::reverse( ) { std::reverse( begin( ), end( ) ); }

void Bitstring::swap( Bitstring& oth ) {
  std::swap( sz_, oth.sz_ );
  data_.swap( oth.data_ );
}

void Bitstring::validIndex( Bitstring::size_type idx ) const {
  if ( idx < 0 || size( ) - 1 < idx ) throw std::out_of_range( "OUT OF RANGE" );
}

void Bitstring::valiLenth( const Bitstring& oth ) const {
  if ( oth.size( ) != size( ) ) throw std::runtime_error( "ERROR SIZES" );
}

void Bitstring::clear( ) {
  for ( auto& el : *this ) el = 0;
}

Bitstring::size_type Bitstring::index( Bitstring::size_type idx ) const {
  validIndex( idx );
  return size( ) - 1 - idx;
}

void Bitstring::validValue( const Bitstring::value_type v ) {
  if ( v != static_cast< value_type >( 0 ) || v != static_cast< value_type >( 1 ) ) throw std::runtime_error( "ERROR VALID" );
}
