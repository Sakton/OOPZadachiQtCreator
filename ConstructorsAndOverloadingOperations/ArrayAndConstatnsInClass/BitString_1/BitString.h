/*
Описание:
1. битовая строка - не число, а массив битов!!!

2. TODO сделать тесты
*/

#pragma once
#include <string>
#include <iostream>

using Type = unsigned char;

class BitString {
public:
	explicit BitString( size_t n = 100 );
	//	explicit BitString( const char * str );
	explicit BitString( const std::string & str );
	~BitString( );
	BitString( const BitString & other );
	BitString & operator=( const BitString & other );
	size_t Count( ) const;

	static size_t Size( );

	const BitString & operator <<=( int n ); //запрет цепочек (const в типе возврата)
	const BitString & operator >>=( int n );
	const BitString & operator ~( );
	const BitString & operator |=( const BitString & other );
	const BitString & operator &=( const BitString & other );
	const BitString & operator ^=( const BitString & other );

	unsigned char & operator[]( size_t ind );
	const unsigned char & operator[]( size_t ind ) const;

	//friend BitString 
	friend BitString operator >>( const BitString & other, int n );
	friend BitString operator <<( const BitString & other, int n );
	friend BitString operator | ( const BitString & first, const BitString & second );
	friend BitString operator & ( const BitString & first, const BitString & second );
	friend BitString operator ^ ( const BitString & first, const BitString & second );

	std::string ToString( );

	friend std::ostream & operator << ( std::ostream & out, const BitString & other );
	friend std::istream & operator >> ( std::istream & in, BitString & other );

	//std::string DecimalPresentation( ); //ничего не выйдет, для преобразвания нужен класс Decimal для огромных чисел, иниче 
	//будет ограничено встроенными типами

private:
	bool IsOkString( const std::string & str );


private:
	static const size_t MAX = 100;
	Type * bitStr;
	size_t count;
};

