#include "decimal32list.h"

#include <algorithm>

sktn::Decimal32List::Decimal32List( container_type::size_type n ) : decimal_( n, 0 ) {}

sktn::Decimal32List::Decimal32List( const std::string &str ) {
  container_type tmp( str.size( ), 0 );
  std::transform( str.crbegin( ), str.crend( ), tmp.begin( ), []( const char &el ) { return el - '0'; } );
  decimal_.swap( tmp );
  trimZero( );
}

sktn::Decimal32List::const_reference sktn::Decimal32List::operator[]( sktn::Decimal32List::size_type idx ) const {
  if ( idx > decimal_.size( ) ) throw std::out_of_range( "OUT OF RANGE" );
  auto it = decimal_.cbegin( );
  for ( size_type i = 0; i < idx && it != decimal_.end( ); ++i ) {
    ++it;
  }
  return *it;
}

sktn::Decimal32List::reference sktn::Decimal32List::operator[]( sktn::Decimal32List::size_type idx ) {
  return const_cast< sktn::Decimal32List::reference >( static_cast< const Decimal32List & >( *this )[ idx ] );
}

sktn::Decimal32List &sktn::Decimal32List::operator+=( const Decimal32List &rhs ) {
  Decimal32List tmp = ( size( ) > rhs.size( ) ) ? ( *this ) : rhs;
  value_type perenos = 0;
  container_type::size_type i = 0;
  for ( ; i < std::min( decimal_.size( ), rhs.decimal_.size( ) ); ++i ) {
    // std::inserter(tmp.decimal_, );
    tmp[ i ] = ( *this )[ i ] + rhs[ i ] + perenos;
    perenos = tmp[ i ] / 10;
    tmp[ i ] %= 10;
  }
  if ( size( ) > i ) {
    for ( ; i < size( ); ++i ) {
      tmp[ i ] = ( *this )[ i ] + perenos;
      perenos = tmp[ i ] / 10;
      tmp[ i ] %= 10;
    }
  }
  if ( rhs.size( ) > i ) {
    for ( ; i < rhs.size( ); ++i ) {
      tmp[ i ] = rhs[ i ] + perenos;
      perenos = tmp[ i ] / 10;
      tmp[ i ] %= 10;
    }
  }
  if ( perenos ) {
    tmp.decimal_.push_back( perenos );
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

sktn::Decimal32List &sktn::Decimal32List::operator-=( const Decimal32List &rhs ) {
  if ( ( *this ) < rhs ) return *this = Decimal32List( "0" );
  Decimal32List tmp = *this;
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

sktn::Decimal32List &sktn::Decimal32List::operator*=( const Decimal32List &rhs ) {
  if ( rhs == Decimal32List( "0" ) ) return *this = Decimal32List( "0" );
  Decimal32List tmp( size( ) + rhs.size( ) );
  container_type::iterator it_tmp = tmp.decimal_.begin( );
  for ( auto it_this = decimal_.begin( ); it_this != decimal_.cend( ); ++it_this ) {
    for ( auto it_rhs = rhs.decimal_.begin( ); it_rhs != rhs.decimal_.cend( ); ++it_rhs ) {
      auto deltaIterThis = std::distance( decimal_.begin( ), it_this );   /*it_this - decimal_.begin( );*/
      auto deltaIterRhs = std::distance( rhs.decimal_.begin( ), it_rhs ); /*it_rhs - rhs.decimal_.begin( );*/
      auto n = deltaIterThis + deltaIterRhs;
      auto t = ( *it_this ) * ( *it_rhs );
      auto tmpt = ( tmp[ n ] + t );
      tmp[ n ] = tmpt % 10;
      tmp[ n + 1 ] += tmpt / 10;
    }
  }
  tmp.trimZero( );
  swap( tmp );
  return *this;
}

sktn::Decimal32List &sktn::Decimal32List::operator/=( const Decimal32List &rhs ) {
  if ( *this < rhs ) return *this = Decimal32List( "0" );
  const std::string delimoe = static_cast< std::string >( *this );

  std::string string_t_delim = delimoe.substr( 0, rhs.size( ) );
  std::string::const_iterator next_pos_delimoe = delimoe.begin( ) + rhs.size( );
  //ОШИБКА!!!ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ НЕ ПОХОДИТ!!! 654 > 546789746 всегда
  //  std::cout << "( std::string( \"654\" ) > std::string( \"546789746\" ) ) = !!!===>>> " << std::boolalpha
  //            << ( std::string( "654" ) > std::string( "546789746" ) ) << std::endl;
  Decimal32List t_delim( string_t_delim );
  if ( next_pos_delimoe != delimoe.cend( ) && t_delim < rhs ) {
    string_t_delim += *next_pos_delimoe++;
    t_delim = Decimal32List( string_t_delim );
  }
  std::string string_result;

  while ( t_delim >= rhs ) {  // пока можно делить
    //********************************************************************************************************* цикл деления
    //ввод переменных и начальных значений
    Decimal32List t_result_number( "1" );
    Decimal32List t_mul = t_result_number * rhs;  // multiple
    Decimal32List t_sub = t_delim - t_mul;        // substraction
    // 1. подбор числа
    while ( t_sub >= rhs ) {
      t_result_number += Decimal32List( "1" );
      t_mul = t_result_number * rhs;
      t_sub = t_delim - t_mul;
    }
    // 2. Сохраняем подобранное число в строку
    string_result += static_cast< std::string >( t_result_number );

    // 3. Вычисляем новое делимое
    string_t_delim = static_cast< std::string >( t_sub );
    if ( next_pos_delimoe != delimoe.cend( ) && ( t_sub != Decimal32List( "0" ) ) ) {
      string_t_delim += *next_pos_delimoe++;
    }
    t_delim = Decimal32List( string_t_delim );
    while ( ( next_pos_delimoe != delimoe.cend( ) ) && ( t_delim <= rhs ) ) {
      string_t_delim += *next_pos_delimoe++;
      if ( string_t_delim.back( ) == '0' ) string_result += '0';
      t_delim = Decimal32List( string_t_delim );
    }

    //********************************************************************************************************* цикл деления
  }

  Decimal32List loc( string_result );
  loc.trimZero( );
  swap( loc );
  return *this;
}

sktn::Decimal32List &sktn::Decimal32List::operator%=( const Decimal32List &rhs ) {
  if ( *this < rhs ) return *this = Decimal32List( "0" );

  const std::string delimoe = static_cast< std::string >( *this );

  std::string string_t_delim = delimoe.substr( 0, rhs.size( ) );
  std::string::const_iterator next_pos_delimoe = delimoe.begin( ) + rhs.size( );
  Decimal32List t_delim( string_t_delim );
  if ( next_pos_delimoe != delimoe.cend( ) && t_delim < rhs ) {
    string_t_delim += *next_pos_delimoe++;
    t_delim = Decimal32List( string_t_delim );
  }

  while ( t_delim >= rhs ) {  // пока можно делить
    //********************************************************************************************************* цикл деления
    //ввод переменных и начальных значений
    Decimal32List t_result_number( "1" );
    Decimal32List t_mul = t_result_number * rhs;  // multiple
    Decimal32List t_sub = t_delim - t_mul;        // substraction
    // 1. подбор числа
    while ( t_sub > rhs ) {
      t_result_number += Decimal32List( "1" );
      t_mul = t_result_number * rhs;
      t_sub = t_delim - t_mul;
    }
    // 3. Вычисляем новое делимое
    string_t_delim = static_cast< std::string >( t_sub );
    if ( next_pos_delimoe != delimoe.cend( ) && ( t_sub != Decimal32List( "0" ) ) ) {
      string_t_delim += *next_pos_delimoe++;
    }
    t_delim = Decimal32List( string_t_delim );
    while ( ( next_pos_delimoe != delimoe.cend( ) ) && ( t_delim <= rhs ) ) {
      string_t_delim += *next_pos_delimoe++;
      t_delim = Decimal32List( string_t_delim );
    }
    //********************************************************************************************************* цикл деления
  }

  Decimal32List loc( t_delim );
  loc.trimZero( );
  swap( loc );
  return *this;
}

void sktn::Decimal32List::swap( Decimal32List &oth ) { decimal_.swap( oth.decimal_ ); }

sktn::Decimal32List::operator std::string( ) const {
  std::string res( size( ), ' ' );
  std::transform( decimal_.crbegin( ), decimal_.crend( ), res.begin( ), []( const value_type &ch ) { return ch + '0'; } );
  return res;
}

sktn::Decimal32List::container_type::size_type sktn::Decimal32List::size( ) const { return decimal_.size( ); }

void sktn::Decimal32List::trimZero( ) {
  while ( decimal_.back( ) == 0 && decimal_.size( ) > 1 ) decimal_.pop_back( );
}

std::ostream &sktn::operator<<( std::ostream &out, const Decimal32List &dcm ) {
  std::copy( dcm.decimal_.crbegin( ), dcm.decimal_.crend( ), std::ostream_iterator< int >( out ) );
  return out;
}
bool sktn::operator<( const Decimal32List &a, const Decimal32List &b ) {
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
bool sktn::operator<=( const Decimal32List &a, const Decimal32List &b ) { return a < b || a == b; }
bool sktn::operator>=( const Decimal32List &a, const Decimal32List &b ) { return a > b || a == b; }
bool sktn::operator>( const Decimal32List &a, const Decimal32List &b ) { return !( a <= b ); }
bool sktn::operator==( const Decimal32List &a, const Decimal32List &b ) { return a.decimal_ == b.decimal_; }
bool sktn::operator!=( const Decimal32List &a, const Decimal32List &b ) { return !( a == b ); }

const sktn::Decimal32List sktn::operator+( const Decimal32List &lhs, const Decimal32List &rhs ) {
  Decimal32List loc = lhs;
  loc += rhs;
  return loc;
}

const sktn::Decimal32List sktn::operator-( const Decimal32List &lhs, const Decimal32List &rhs ) {
  Decimal32List loc = lhs;
  loc -= rhs;
  return loc;
}

const sktn::Decimal32List sktn::operator*( const Decimal32List &lhs, const Decimal32List &rhs ) {
  Decimal32List loc = lhs;
  loc *= rhs;
  return loc;
}

const sktn::Decimal32List sktn::operator/( const Decimal32List &lhs, const Decimal32List &rhs ) {
  Decimal32List loc = lhs;
  loc /= rhs;
  return loc;
}

const sktn::Decimal32List sktn::operator%( const Decimal32List &lhs, const Decimal32List &rhs ) {
  Decimal32List loc = lhs;
  loc %= rhs;
  return loc;
}

void sktn::swap( Decimal32List &lhs, Decimal32List &rhs ) {
  using std::swap;
  lhs.swap( rhs );
}
