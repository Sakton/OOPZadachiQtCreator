#include "array.h"

#include <algorithm>
#include <functional>
#include <stdexcept>

MY::Array::Array( MY::Array::size_type n, const MY::Array::value_type& d ) : sz_ { n }, data_ { new value_type[ n ] } {
  for ( size_type i = 0; i < n; ++i ) data_[ i ] = d;
}

MY::Array::Array( MY::Array::const_iterator beg, MY::Array::const_iterator end ) : sz_ { 0 }, data_ { nullptr } {
  auto i = beg;
  size_type count = 0;
  while ( i != end ) {
    ++i;
    ++count;
  }
  if ( !count ) throw std::runtime_error( "ERROR CTOR" );
  sz_ = count;
  data_ = new value_type[ count ];
  std::copy( beg, end, data_ );
}

MY::Array::~Array( ) { delete[] data_; }

MY::Array::Array( const MY::Array& oth ) : sz_ { oth.sz_ }, data_ { new value_type[ oth.sz_ ] } { std::copy( oth.begin( ), oth.end( ), data_ ); }

MY::Array::Array( MY::Array&& oth ) : sz_ { 0 }, data_ { nullptr } {
  if ( this != &oth ) {
    swap( oth );
  }
}

MY::Array::const_iterator MY::Array::begin( ) const { return data_; }

MY::Array::const_iterator MY::Array::end( ) const { return data_ + sz_; }

MY::Array::iterator MY::Array::begin( ) { return const_cast< MY::Array::iterator >( static_cast< const Array& >( *this ).begin( ) ); }

MY::Array::iterator MY::Array::end( ) { return const_cast< MY::Array::iterator >( static_cast< const Array& >( *this ).end( ) ); }

MY::Array::size_type MY::Array::size( ) const { return sz_; }

MY::Array::const_reference MY::Array::operator[]( MY::Array::size_type idx ) const {
  if ( idx < 0 || sz_ < idx ) throw std::out_of_range( "ERROR INDEX" );
  return data_[ idx ];
}

MY::Array::reference MY::Array::operator[]( MY::Array::size_type idx ) {
  return const_cast< MY::Array::reference >( static_cast< const Array& >( *this )[ idx ] );
}

const MY::Array& MY::Array::operator+=( const MY::Array& oth ) {
  if ( size( ) != oth.size( ) ) throw std::runtime_error( "ERROR" );
  Array loc( oth.size( ) );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::plus<>( ) );
  swap( loc );
  return *this;
}

const MY::Array& MY::Array::operator-=( const MY::Array& oth ) {
  if ( size( ) != oth.size( ) ) throw std::runtime_error( "ERROR" );
  Array loc( oth.size( ) );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::minus<>( ) );
  swap( loc );
  return *this;
}

const MY::Array& MY::Array::operator*=( const MY::Array& oth ) {
  if ( size( ) != oth.size( ) ) throw std::runtime_error( "ERROR" );
  Array loc( oth.size( ) );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::multiplies<>( ) );
  swap( loc );
  return *this;
}

const MY::Array& MY::Array::operator/=( const MY::Array& oth ) {
  if ( size( ) != oth.size( ) ) throw std::runtime_error( "ERROR" );
  Array loc( oth.size( ) );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::divides<>( ) );
  swap( loc );
  return *this;
}

void MY::Array::swap( MY::Array& oth ) {
  std::swap( sz_, oth.sz_ );
  std::swap( data_, oth.data_ );
}

const MY::Array MY::operator+( const Array& lhs, const Array& rhs ) {
  MY::Array loc = lhs;
  loc += rhs;
  return loc;
}

const MY::Array MY::operator-( const Array& lhs, const Array& rhs ) {
  MY::Array loc = lhs;
  loc -= rhs;
  return loc;
}
const MY::Array MY::operator*( const Array& lhs, const Array& rhs ) {
  MY::Array loc = lhs;
  loc *= rhs;
  return loc;
}

const MY::Array MY::operator/( const Array& lhs, const Array& rhs ) {
  MY::Array loc = lhs;
  loc /= rhs;
  return loc;
}

bool MY::operator==( const Array& lhs, const Array& rhs ) {
  if ( lhs.size( ) != rhs.size( ) )
    return false;
  else {
    return std::equal( lhs.begin( ), lhs.end( ), rhs.begin( ),
                       []( const MY::Array::value_type& el1, const MY::Array::value_type& el2 ) { return el1 == el2; } );
  }
}

bool MY::operator!=( const Array& lhs, const Array& rhs ) { return !( lhs == rhs ); }
