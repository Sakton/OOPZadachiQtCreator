
#pragma once
#include <array.h>
#include <iostream>
#include <string>

using Type = unsigned char;

class BitString : public Array< Type > {
public:
    explicit BitString( int n = 0 );
    explicit BitString( const std::string & str );
    BitString( const BitString & other );
    BitString & operator=( const BitString & other );
    BitString & operator=( Array && other );
    size_t Count( ) const;

    static size_t Size( );

    BitString & operator<<=( int n );
    BitString & operator>>=( int n );
    BitString & operator~( );
    BitString & operator|=( const BitString & other );
    BitString & operator&=( const BitString & other );
    BitString & operator^=( const BitString & other );

    friend BitString operator>>( const BitString & other, int n );
    friend BitString operator<<( const BitString & other, int n );
    friend BitString operator|( const BitString & first, const BitString & second );
    friend BitString operator&( const BitString & first, const BitString & second );
    friend BitString operator^( const BitString & first, const BitString & second );

    operator std::string( ) const;
    void Display( );

    friend std::ostream & operator<<( std::ostream & out, const BitString & other );
    friend std::istream & operator>>( std::istream & in, BitString & other );

private:
    bool IsOkString( const std::string & str );
};
