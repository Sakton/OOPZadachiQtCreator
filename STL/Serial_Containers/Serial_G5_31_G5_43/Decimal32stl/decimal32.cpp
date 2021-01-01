#include "decimal32.h"

#include <algorithm>

sktn::Decimal32::Decimal32( container_type::size_type n ) : decimal_( n, 0 ) {}

sktn::Decimal32::Decimal32( const std::string &str ) {
  container_type tmp( str.size( ), 0 );
  std::transform( str.crbegin( ), str.crend( ), tmp.begin( ), []( const char &el ) { return el - '0'; } );
  decimal_.swap( tmp );
  trimZero( );
}

sktn::Decimal32 &sktn::Decimal32::operator+=( const Decimal32 &rhs ) {
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
/*

 Decimal32 &Decimal32::operator-=( const Decimal32 &rhs ) {
  if ( ( *this ) < rhs ) return *this = Decimal32( "0" );
  Decimal32 tmp = *this;
  value_type perenos = 0;
  container_type::size_type i = 0;
  for ( ; i < std::min( size( ), rhs.size( ) ); ++i ) {
    int t = decimal_[ i ] - rhs.decimal_[ i ] - perenos;
    if ( t < 0 ) {
      tmp.decimal_[ i ] = t + 10;
      perenos = 1;
    } else {
      tmp.decimal_[ i ] = t;
      perenos = 0;
    }
  }
  if ( size( ) < i ) {
    for ( ; i < size( ); ++i ) {
      int t = decimal_[ i ] - perenos;
      if ( t < 0 ) {
        tmp.decimal_[ i ] = t + 10;
        perenos = 1;
      } else {
        tmp.decimal_[ i ] = t;
        perenos = 0;
      }
    }
  }
  swap( tmp );
  return *this;
}

*/

sktn::Decimal32 &sktn::Decimal32::operator-=( const Decimal32 &rhs ) {
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

sktn::Decimal32 &sktn::Decimal32::operator*=( const Decimal32 &rhs ) {
  if ( rhs == Decimal32( "0" ) ) return *this = Decimal32( "0" );
  Decimal32 tmp( size( ) + rhs.size( ) );
  container_type::iterator it_tmp = tmp.decimal_.begin( );
  for ( auto it_this = decimal_.begin( ); it_this != decimal_.cend( ); ++it_this ) {
    for ( auto it_rhs = rhs.decimal_.begin( ); it_rhs != rhs.decimal_.cend( ); ++it_rhs ) {
      auto deltaIterThis = it_this - decimal_.begin( );
      auto deltaIterRhs = it_rhs - rhs.decimal_.begin( );
      auto n = deltaIterThis + deltaIterRhs;
      auto t = ( *it_this ) * ( *it_rhs );
      auto tmpt = ( it_tmp[ n ] + t );
      it_tmp[ n ] = tmpt % 10;
      it_tmp[ n + 1 ] += tmpt / 10;
    }
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

sktn::Decimal32 &sktn::Decimal32::operator/=( const Decimal32 &rhs ) {
  if ( *this < rhs ) return *this = Decimal32( "0" );
  const std::string delimoe = static_cast< std::string >( *this );

  std::string string_t_delim = delimoe.substr( 0, rhs.size( ) );
  std::string::const_iterator next_pos_delimoe = delimoe.begin( ) + rhs.size( );
  //ОШИБКА!!!ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ НЕ ПОХОДИТ!!! 654 > 546789746 всегда
  //  std::cout << "( std::string( \"654\" ) > std::string( \"546789746\" ) ) = !!!===>>> " << std::boolalpha
  //            << ( std::string( "654" ) > std::string( "546789746" ) ) << std::endl;
  Decimal32 t_delim( string_t_delim );
  if ( next_pos_delimoe != delimoe.cend( ) && t_delim < rhs ) {
    string_t_delim += *next_pos_delimoe++;
    t_delim = Decimal32( string_t_delim );
  }
  std::string string_result;

  while ( t_delim >= rhs ) {  // пока можно делить
    //********************************************************************************************************* цикл деления
    //ввод переменных и начальных значений
    Decimal32 t_result_number( "1" );
    Decimal32 t_mul = t_result_number * rhs;  // multiple
    Decimal32 t_sub = t_delim - t_mul;        // substraction
    // 1. подбор числа
    while ( t_sub >= rhs ) {
      t_result_number += Decimal32( "1" );
      t_mul = t_result_number * rhs;
      t_sub = t_delim - t_mul;
    }
    // 2. Сохраняем подобранное число в строку
    string_result += static_cast< std::string >( t_result_number );

    // 3. Вычисляем новое делимое
    string_t_delim = static_cast< std::string >( t_sub );
    if ( next_pos_delimoe != delimoe.cend( ) && ( t_sub != Decimal32( "0" ) ) ) {
      string_t_delim += *next_pos_delimoe++;
    }
    t_delim = Decimal32( string_t_delim );
    while ( ( next_pos_delimoe != delimoe.cend( ) ) && ( t_delim <= rhs ) ) {
      string_t_delim += *next_pos_delimoe++;
      if ( string_t_delim.back( ) == '0' ) string_result += '0';
      t_delim = Decimal32( string_t_delim );
    }

    //********************************************************************************************************* цикл деления
  }

  Decimal32 loc( string_result );
  loc.trimZero( );
  swap( loc );
  return *this;
}

sktn::Decimal32 &sktn::Decimal32::operator%=( const Decimal32 &rhs ) {
  if ( *this < rhs ) return *this = Decimal32( "0" );

  const std::string delimoe = static_cast< std::string >( *this );

  std::string string_t_delim = delimoe.substr( 0, rhs.size( ) );
  std::string::const_iterator next_pos_delimoe = delimoe.begin( ) + rhs.size( );
  Decimal32 t_delim( string_t_delim );
  if ( next_pos_delimoe != delimoe.cend( ) && t_delim < rhs ) {
    string_t_delim += *next_pos_delimoe++;
    t_delim = Decimal32( string_t_delim );
  }

  while ( t_delim >= rhs ) {  // пока можно делить
    //********************************************************************************************************* цикл деления
    //ввод переменных и начальных значений
    Decimal32 t_result_number( "1" );
    Decimal32 t_mul = t_result_number * rhs;  // multiple
    Decimal32 t_sub = t_delim - t_mul;        // substraction
    // 1. подбор числа
    while ( t_sub > rhs ) {
      t_result_number += Decimal32( "1" );
      t_mul = t_result_number * rhs;
      t_sub = t_delim - t_mul;
    }
    // 3. Вычисляем новое делимое
    string_t_delim = static_cast< std::string >( t_sub );
    if ( next_pos_delimoe != delimoe.cend( ) && ( t_sub != Decimal32( "0" ) ) ) {
      string_t_delim += *next_pos_delimoe++;
    }
    t_delim = Decimal32( string_t_delim );
    while ( ( next_pos_delimoe != delimoe.cend( ) ) && ( t_delim <= rhs ) ) {
      string_t_delim += *next_pos_delimoe++;
      t_delim = Decimal32( string_t_delim );
    }
    //********************************************************************************************************* цикл деления
  }

  Decimal32 loc( t_delim );
  loc.trimZero( );
  swap( loc );
  return *this;
}

void sktn::Decimal32::swap( Decimal32 &oth ) { decimal_.swap( oth.decimal_ ); }

sktn::Decimal32::operator std::string( ) const {
  std::string res( size( ), ' ' );
  std::transform( decimal_.crbegin( ), decimal_.crend( ), res.begin( ), []( const value_type &ch ) { return ch + '0'; } );
  return res;
}

sktn::Decimal32::container_type::size_type sktn::Decimal32::size( ) const { return decimal_.size( ); }

void sktn::Decimal32::trimZero( ) {
  while ( decimal_.back( ) == 0 && decimal_.size( ) > 1 ) decimal_.pop_back( );
}

std::ostream &sktn::operator<<( std::ostream &out, const Decimal32 &dcm ) {
  std::copy( dcm.decimal_.crbegin( ), dcm.decimal_.crend( ), std::ostream_iterator< int >( out ) );
  return out;
}
bool sktn::operator<( const Decimal32 &a, const Decimal32 &b ) {
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
bool sktn::operator<=( const Decimal32 &a, const Decimal32 &b ) { return a < b || a == b; }
bool sktn::operator>=( const Decimal32 &a, const Decimal32 &b ) { return a > b || a == b; }
bool sktn::operator>( const Decimal32 &a, const Decimal32 &b ) { return !( a <= b ); }
bool sktn::operator==( const Decimal32 &a, const Decimal32 &b ) { return a.decimal_ == b.decimal_; }
bool sktn::operator!=( const Decimal32 &a, const Decimal32 &b ) { return !( a == b ); }

const sktn::Decimal32 sktn::operator+( const Decimal32 &lhs, const Decimal32 &rhs ) {
  Decimal32 loc = lhs;
  loc += rhs;
  return loc;
}

const sktn::Decimal32 sktn::operator-( const Decimal32 &lhs, const Decimal32 &rhs ) {
  Decimal32 loc = lhs;
  loc -= rhs;
  return loc;
}

const sktn::Decimal32 sktn::operator*( const Decimal32 &lhs, const Decimal32 &rhs ) {
  Decimal32 loc = lhs;
  loc *= rhs;
  return loc;
}

const sktn::Decimal32 sktn::operator/( const Decimal32 &lhs, const Decimal32 &rhs ) {
  Decimal32 loc = lhs;
  loc /= rhs;
  return loc;
}

const sktn::Decimal32 sktn::operator%( const Decimal32 &lhs, const Decimal32 &rhs ) {
  Decimal32 loc = lhs;
  loc %= rhs;
  return loc;
}

void sktn::swap( Decimal32 &lhs, Decimal32 &rhs ) {
  using std::swap;
  lhs.swap( rhs );
}
