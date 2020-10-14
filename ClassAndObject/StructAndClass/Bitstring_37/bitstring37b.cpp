#include "bitstring37b.h"
#include <iostream>
#include <sstream>

void Bitstring37B::Init( uint32_t h, uint32_t t )
{
    head_ = h;
    tail_ = t;
}

void Bitstring37B::Display( )
{
    std::cout << ToString( ) << std::endl;
}

std::string Bitstring37B::ToString( )
{
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

Bitstring37B Bitstring37B::And( const Bitstring37B & other )
{
    Bitstring37B loc;
    loc.head_ = head_ & other.head_;
    loc.tail_ = tail_ & other.tail_;
    return loc;
}

Bitstring37B Bitstring37B::Or( const Bitstring37B & other )
{
    Bitstring37B loc;
    loc.head_ = head_ | other.head_;
    loc.tail_ = tail_ | other.tail_;
    return loc;
}

Bitstring37B Bitstring37B::Xor( const Bitstring37B & other )
{
    Bitstring37B loc;
    loc.head_ = head_ ^ other.head_;
    loc.tail_ = tail_ ^ other.tail_;
    return loc;
}

Bitstring37B Bitstring37B::Not( )
{
    Bitstring37B loc;
    loc.head_ = ~head_;
    loc.tail_ = ~tail_;
    return loc;
}

Bitstring37B Bitstring37B::ShiftLeft( int n )
{
    //1. Сдвинуть head на 1 поз. - подготтовить место под вставку
    //2. Сдвигать пока в встаршем разряде не появится 1 в tail
    //3. Перетащить 1 цу в head на младшую позицию
    //4. Сдвинуть tail влево

    Bitstring37B loc = *this;

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

Bitstring37B Bitstring37B::ShiftRight( int n )
{
    Bitstring37B loc = *this;

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
