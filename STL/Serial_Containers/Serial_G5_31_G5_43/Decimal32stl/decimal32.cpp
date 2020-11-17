#include "decimal32.h"

#include <algorithm>

Decimal32::Decimal32( container_type::size_type n ) : decimal_( n, 0 ) {}

Decimal32::Decimal32( const std::string &str ) {
  container_type tmp( str.size( ), 0 );
  std::transform( str.crbegin( ), str.crend( ), tmp.begin( ), []( const char &el ) { return el - '0'; } );
  decimal_.swap( tmp );
}

Decimal32 &Decimal32::operator+=( const Decimal32 &rhs ) {
  Decimal32 tmp = ( size( ) > rhs.size( ) ) ? ( *this ) : rhs;
  value_type perenos = 0;
  container_type::size_type i = 0;
  for ( ; i < std::min( decimal_.size( ), rhs.decimal_.size( ) ); ++i ) {
    tmp.decimal_[ i ] = decimal_[ i ] + rhs.decimal_[ i ] + perenos;
    perenos = tmp.decimal_[ i ] / 10;
    tmp.decimal_[ i ] %= 10;
  }
  if ( size( ) > i ) {
    for ( ; i < decimal_.size( ); ++i ) {
      tmp.decimal_[ i ] = decimal_[ i ] + perenos;
      perenos = tmp.decimal_[ i ] / 10;
      tmp.decimal_[ i ] %= 10;
    }
  }
  if ( rhs.size( ) > i ) {
    for ( ; i < rhs.decimal_.size( ); ++i ) {
      tmp.decimal_[ i ] = rhs.decimal_[ i ] + perenos;
      perenos = tmp.decimal_[ i ] / 10;
      tmp.decimal_[ i ] %= 10;
    }
  }
  if ( perenos ) {
    tmp.decimal_.push_back( perenos );
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

// Decimal32 &Decimal32::operator-=( const Decimal32 &rhs ) {
//  if ( ( *this ) < rhs ) return *this = Decimal32( "0" );
//  Decimal32 tmp = *this;
//  value_type perenos = 0;
//  container_type::size_type i = 0;
//  for ( ; i < std::min( size( ), rhs.size( ) ); ++i ) {
//    int t = decimal_[ i ] - rhs.decimal_[ i ] - perenos;
//    if ( t < 0 ) {
//      tmp.decimal_[ i ] = t + 10;
//      perenos = 1;
//    } else {
//      tmp.decimal_[ i ] = t;
//      perenos = 0;
//    }
//  }
//  if ( size( ) < i ) {
//    for ( ; i < size( ); ++i ) {
//      int t = decimal_[ i ] - perenos;
//      if ( t < 0 ) {
//        tmp.decimal_[ i ] = t + 10;
//        perenos = 1;
//      } else {
//        tmp.decimal_[ i ] = t;
//        perenos = 0;
//      }
//    }
//  }
//  swap( tmp );
//  return *this;
//}

Decimal32 &Decimal32::operator-=( const Decimal32 &rhs ) {
  if ( ( *this ) < rhs ) return *this = Decimal32( "0" );
  Decimal32 tmp = *this;
  value_type perenos = 0;
  container_type::iterator it_tmp = tmp.decimal_.begin( );
  container_type::const_iterator it_this = decimal_.cbegin( );
  container_type::const_iterator it_rhs = rhs.decimal_.cbegin( );
  for ( ; it_this != decimal_.cend( ) && it_rhs != rhs.decimal_.cend( ); ++it_this, ++it_rhs, ++it_tmp ) {
    int t = *it_this - *it_rhs - perenos;
    if ( t < 0 ) {
      *it_tmp = t + 10;
      perenos = 1;
    } else {
      *it_tmp = t;
      perenos = 0;
    }
  }
  if ( it_this != decimal_.cend( ) ) {
    for ( ; it_this != decimal_.cend( ); ++it_this, ++it_tmp ) {
      int t = *it_this - perenos;
      if ( t < 0 ) {
        *it_tmp = t + 10;
        perenos = 1;
      } else {
        *it_tmp = t;
        perenos = 0;
      }
    }
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

Decimal32 &Decimal32::operator*=( const Decimal32 &rhs ) {
  if ( rhs == Decimal32( "0" ) ) return *this = Decimal32( "0" );
  Decimal32 tmp( size( ) + rhs.size( ) );
  container_type::iterator it_tmp = tmp.decimal_.begin( );
  //  container_type::const_iterator it_this = decimal_.begin( );
  // container_type::const_iterator it_rhs = rhs.decimal_.begin( );
  for ( auto it_this = decimal_.begin( ); it_this != decimal_.cend( ); ++it_this ) {
    for ( auto it_rhs = rhs.decimal_.begin( ); it_rhs != rhs.decimal_.cend( ); ++it_rhs ) {
      auto deltaIterThis = it_this - decimal_.begin( );
      auto deltaIterRhs = it_rhs - rhs.decimal_.begin( );
      auto n = deltaIterThis + deltaIterRhs;
      //      it_tmp[ n ] += ( *it_this ) * ( *it_rhs ) % 10;
      //      it_tmp[ n + 1 ] += ( *it_this ) * ( *it_rhs ) / 10;
      // FIXME ТУТ
      auto t = ( *it_this ) * ( *it_rhs );
      it_tmp[ n ] = ( it_tmp[ n ] + t ) % 10;
      it_tmp[ n + 1 ] += ( it_tmp[ n ] ) / 10;
    }
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

void Decimal32::swap( Decimal32 &oth ) { decimal_.swap( oth.decimal_ ); }

void Decimal32::printDebugTryth( ) { std::copy( decimal_.begin( ), decimal_.end( ), std::ostream_iterator< int >( std::cout ) ); }

Decimal32::container_type::size_type Decimal32::size( ) const { return decimal_.size( ); }

void Decimal32::trimZero( ) {
  while ( decimal_.back( ) == 0 && decimal_.size( ) > 1 ) decimal_.pop_back( );
}

std::ostream &operator<<( std::ostream &out, const Decimal32 &dcm ) {
  std::copy( dcm.decimal_.crbegin( ), dcm.decimal_.crend( ), std::ostream_iterator< int >( out ) );
  return out;
}
bool operator<( const Decimal32 &a, const Decimal32 &b ) {
  if ( a.size( ) < b.size( ) )
    return true;
  else if ( a.size( ) > b.size( ) )
    return false;
  else
    for ( auto i = a.decimal_.crbegin( ), j = b.decimal_.crbegin( ); i != a.decimal_.crend( ); ++i, ++j ) {
      if ( *i < *j )
        return true;
      else if ( *i > *j )
        return false;
    }
  return false;
}
bool operator<=( const Decimal32 &a, const Decimal32 &b ) { return a < b || a == b; }
bool operator>=( const Decimal32 &a, const Decimal32 &b ) { return a > b || a == b; }
bool operator>( const Decimal32 &a, const Decimal32 &b ) { return !( a <= b ); }
bool operator==( const Decimal32 &a, const Decimal32 &b ) { return a.decimal_ == b.decimal_; }
bool operator!=( const Decimal32 &a, const Decimal32 &b ) { return !( a == b ); }
