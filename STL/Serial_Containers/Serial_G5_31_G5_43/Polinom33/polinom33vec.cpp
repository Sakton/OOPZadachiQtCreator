#include "polinom33vec.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

Polinom33Vec::Polinom33Vec( size_type n, value_type k ) : coeff_( n, k ) {}

Polinom33Vec::Polinom33Vec( value_type *beg, value_type *end ) { std::copy( beg, end, std::back_inserter( coeff_ ) ); }

Polinom33Vec &Polinom33Vec::operator+=( const Polinom33Vec &rhs ) {
  Polinom33Vec temp( std::max( size( ), rhs.size( ) ) );
  size_type i = 0;
  for ( ; i < std::min( size( ), rhs.size( ) ); ++i ) {
    temp.coeff_[ i ] = coeff_[ i ] + rhs.coeff_[ i ];
  }
  if ( size( ) > i ) {
    for ( ; i < size( ); ++i ) {
      temp.coeff_[ i ] = coeff_[ i ];
    }
  }
  if ( rhs.size( ) > i ) {
    for ( ; i < rhs.size( ); ++i ) {
      temp.coeff_[ i ] = rhs.coeff_[ i ];
    }
  }
  swap( temp );
  return *this;
}

Polinom33Vec &Polinom33Vec::operator+=( const value_type &dx ) {
  Polinom33Vec temp( size( ) );
  std::transform( coeff_.cbegin( ), coeff_.cend( ), temp.coeff_.begin( ), [ & ]( const value_type &el ) { return dx + el; } );
  swap( temp );
  return *this;
}

Polinom33Vec &Polinom33Vec::operator-=( const Polinom33Vec &rhs ) {
  Polinom33Vec temp( std::max( size( ), rhs.size( ) ) );
  size_type i = 0;
  for ( ; i < std::min( size( ), rhs.size( ) ); ++i ) {
    temp.coeff_[ i ] = coeff_[ i ] - rhs.coeff_[ i ];
  }
  if ( size( ) > i ) {
    for ( ; i < size( ); ++i ) {
      temp.coeff_[ i ] = coeff_[ i ];
    }
  }
  if ( rhs.size( ) > i ) {
    for ( ; i < rhs.size( ); ++i ) {
      temp.coeff_[ i ] = rhs.coeff_[ i ];
    }
  }
  swap( temp );
  return *this;
}

Polinom33Vec &Polinom33Vec::operator-=( const value_type &dx ) {
  Polinom33Vec temp( size( ) );
  std::transform( coeff_.cbegin( ), coeff_.cend( ), temp.coeff_.begin( ), [ & ]( const value_type &el ) { return dx - el; } );
  swap( temp );
  return *this;
}

Polinom33Vec &Polinom33Vec::operator*=( const value_type &dx ) {
  Polinom33Vec temp( size( ) );
  std::transform( coeff_.cbegin( ), coeff_.cend( ), temp.coeff_.begin( ), [ & ]( const value_type &el ) { return dx * el; } );
  swap( temp );
  return *this;
}

Polinom33Vec &Polinom33Vec::operator/=( const value_type &dx ) {
  if ( dx == 0 ) throw std::runtime_error( "DIVIDE_ZERO" );
  Polinom33Vec temp( size( ) );
  std::transform( coeff_.cbegin( ), coeff_.cend( ), temp.coeff_.begin( ), [ & ]( const value_type &el ) { return el / dx; } );
  swap( temp );
  return *this;
}

Polinom33Vec::value_type Polinom33Vec::integral( Polinom33Vec::value_type x ) {
  value_type res = 0;
  for ( size_type i = 0; i < size( ); ++i ) {
    res += coeff_[ i ] * std::pow( x, ( i + 1 ) ) / ( i + 1 );
  }
  return res;
}

Polinom33Vec::value_type Polinom33Vec::differencial( Polinom33Vec::value_type x ) {
  value_type res = 0;
  for ( size_type i = size( ) - 1; i > 1; --i ) {
    res += coeff_[ i ] * i * pow( x, i - 1 );
  }
  return res;
}

void Polinom33Vec::swap( Polinom33Vec &oth ) { coeff_.swap( oth.coeff_ ); }

void Polinom33Vec::swap( Polinom33Vec &rhs, Polinom33Vec &lhs ) {
  using std::swap;
  rhs.swap( lhs );
}

Polinom33Vec::size_type Polinom33Vec::size( ) const { return coeff_.size( ); }

std::ostream &operator<<( std::ostream &out, const Polinom33Vec &p ) {
  int i = p.size( );
  std::for_each( p.coeff_.crbegin( ), p.coeff_.crend( ), [ & ]( const Polinom33Vec::value_type &el ) {
    out << std::setprecision( 1 ) << std::fixed;
    out << "(" << el << ")";
    out << "*x^" << ( --i );
    if ( i ) out << " + ";
  } );
  return out;
}

bool operator==( const Polinom33Vec &lhs, const Polinom33Vec &rhs ) {
  return std::equal( lhs.coeff_.cbegin( ), lhs.coeff_.cend( ), rhs.coeff_.cend( ) );
}

bool operator!=( const Polinom33Vec &lhs, const Polinom33Vec &rhs ) { return !( lhs == rhs ); }

const Polinom33Vec operator+( const Polinom33Vec &lhs, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = lhs;
  loc += rhs;
  return loc;
}

const Polinom33Vec operator+( const Polinom33Vec &lhs, Polinom33Vec::value_type dx ) {
  Polinom33Vec loc = lhs;
  loc += dx;
  return loc;
}

const Polinom33Vec operator+( Polinom33Vec::value_type dx, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = rhs;
  loc += dx;
  return loc;
}

const Polinom33Vec operator-( const Polinom33Vec &lhs, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = lhs;
  loc -= rhs;
  return loc;
}

const Polinom33Vec operator-( const Polinom33Vec &lhs, Polinom33Vec::value_type dx ) {
  Polinom33Vec loc = lhs;
  loc -= dx;
  return loc;
}

const Polinom33Vec operator-( Polinom33Vec::value_type dx, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = rhs;
  loc -= dx;
  return loc;
}

const Polinom33Vec operator*( const Polinom33Vec &lhs, Polinom33Vec::value_type dx ) {
  Polinom33Vec loc = lhs;
  loc *= dx;
  return loc;
}

const Polinom33Vec operator*( Polinom33Vec::value_type dx, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = rhs;
  loc *= dx;
  return loc;
}

const Polinom33Vec operator/( const Polinom33Vec &lhs, Polinom33Vec::value_type dx ) {
  Polinom33Vec loc = lhs;
  loc /= dx;
  return loc;
}

const Polinom33Vec operator/( Polinom33Vec::value_type dx, const Polinom33Vec &rhs ) {
  Polinom33Vec loc = rhs;
  loc /= dx;
  return loc;
}
