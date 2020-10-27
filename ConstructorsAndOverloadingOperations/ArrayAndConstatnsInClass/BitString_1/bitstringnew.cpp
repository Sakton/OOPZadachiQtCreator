#include "bitstringnew.h"

#include <iostream>
#include <iterator>

BitstringNew::BitstringNew( int sz ) : bitstr_ { nullptr }, count_ { 0 } {
  if ( sz < 0 || sz > SIZE ) {
    std::cout << "ERROR SIZE";
    exit( 1 );
  }
  bitstr_ = new Uch[ sz ] { 0 };
  count_ = sz;
}

BitstringNew::BitstringNew( const std::string& bitStr )
    : bitstr_ { nullptr }, count_ { 0 } {
  if ( bitStr.size( ) > SIZE ) {
    std::cerr << "ERROR LENTH STR CTOR";
    exit( 1 );
  }
  count_ = bitStr.size( );
  bitstr_ = new Uch[ bitStr.size( ) ] { 0 };
  int i = 0;
  for ( char el : bitStr ) {
    bitstr_[ i++ ] = el - '0';
  }
}

BitstringNew::BitstringNew( int64_t num, bool )
    : BitstringNew( parseStringToBit( num ) ) {}

BitstringNew::~BitstringNew( ) { delete[] bitstr_; }

BitstringNew::Uch& BitstringNew::operator[]( int index ) {
  if ( index < 0 || index >= count_ ) {
    std::cerr << "ERROR INDEX []";
    exit( 1 );
  }
  if ( bitstr_ == nullptr ) {
    std::cerr << "NULLPTR";
    exit( 1 );
  }
  return bitstr_[ index ];
}

BitstringNew& BitstringNew::operator<<( int n ) {
  if ( n > count_ ) *this = BitstringNew( count_ );
  for ( int i = n; i < count_; ++i ) {
    ( *this )[ i - n ] = ( *this )[ i ];
  }
  for ( int i = count_ - n; i < count_; ++i ) {
    ( *this )[ i ] = 0;
  }
  return *this;
}

BitstringNew& BitstringNew::operator>>( int n ) {
  if ( n > count_ ) *this = BitstringNew( count_ );
  for ( int i = count_ - 1; i >= n; --i ) {
    ( *this )[ i ] = ( *this )[ i - n ];
  }
  for ( int i = 0; i < n; ++i ) {
    ( *this )[ i ] = 0;
  }
  return *this;
}

int BitstringNew::getSIZE( ) { return SIZE; }

std::string BitstringNew::parseStringToBit( int64_t num ) {
  int64_t mask = 1;
  mask <<= 63;
  std::string res;
  res.reserve( 64 );
  for ( int i = 0; i < 64; ++i ) {
    if ( num & mask ) {
      res.push_back( '1' );
    } else {
      res.push_back( '0' );
    }
    mask >>= 1;
  }
  return res;
}

int BitstringNew::getCount( ) const { return count_; }

std::ostream& operator<<( std::ostream& out, const BitstringNew& bs ) {
  std::copy( bs.bitstr_, bs.bitstr_ + bs.count_,
             std::ostream_iterator< int >( out ) );
  return out;
}
