#include "bitstring37b.h"
#include <iostream>
#include <sstream>

Bitstring37B::Bitstring37B( uint32_t h, uint32_t t )
    : head_ { h }, tail_ { t } {}

Bitstring37B::Bitstring37B( uint64_t num ) : head_ { 0 }, tail_ { 0 } {
  tail_ = num;
  head_ = ( num >> 32 );
}

void Bitstring37B::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Bitstring37B::ToString( ) const {
  std::stringstream ss;
  uint32_t mask = 1;
  mask <<= 31;
  for ( int i = 0; i <= 31; ++i ) {
    ss << ( ( head_ & mask ) ? '1' : '0' );
    mask >>= 1;
  }
  mask = 1;
  mask <<= 31;
  for ( int i = 0; i <= 31; ++i ) {
    ss << ( ( tail_ & mask ) ? '1' : '0' );
    mask >>= 1;
  }
  return ss.str( );
}

Bitstring37B operator&( const Bitstring37B& b1, const Bitstring37B& b2 ) {
  Bitstring37B loc = b1;
  loc.head_ &= b2.head_;
  loc.tail_ &= b2.tail_;
  return loc;
}

Bitstring37B operator|( const Bitstring37B& b1, const Bitstring37B& b2 ) {
  Bitstring37B loc = b1;
  loc.head_ |= b2.head_;
  loc.tail_ |= b2.tail_;
  return loc;
}

Bitstring37B operator^( const Bitstring37B& b1, const Bitstring37B& b2 ) {
  Bitstring37B loc = b1;
  loc.head_ ^= b2.head_;
  loc.tail_ ^= b2.tail_;
  return loc;
}

Bitstring37B operator~( const Bitstring37B& b1 ) {
  Bitstring37B loc = b1;
  loc.head_ = ~loc.head_;
  loc.tail_ = ~loc.tail_;
  return loc;
}

Bitstring37B operator<<( const Bitstring37B& b1, int n ) {
  // 1. Сдвинуть head на 1 поз. - подготтовить место под вставку
  // 2. Сдвигать пока в встаршем разряде не появится 1 в tail
  // 3. Перетащить 1 цу в head на младшую позицию
  // 4. Сдвинуть tail влево

  Bitstring37B loc = b1;

  uint32_t mask_tail = std::pow( 2, 31 );
  uint32_t mask_head = 1;

  for ( int i = 0; i < n; ++i ) {
    loc.head_ <<= 1;
    if ( mask_tail & loc.tail_ ) {
      loc.head_ |= mask_head;
    }
    loc.tail_ <<= 1;
  }
  return loc;
}

Bitstring37B operator>>( const Bitstring37B& b1, int n ) {
  Bitstring37B loc = b1;

  uint32_t mask_tail = std::pow( 2, 31 );
  uint32_t mask_head = 1;

  for ( int i = 0; i < n; ++i ) {
    loc.tail_ >>= 1;
    if ( mask_head & loc.head_ ) {
      loc.tail_ |= mask_tail;
    }
    loc.head_ >>= 1;
  }
  return loc;
}
