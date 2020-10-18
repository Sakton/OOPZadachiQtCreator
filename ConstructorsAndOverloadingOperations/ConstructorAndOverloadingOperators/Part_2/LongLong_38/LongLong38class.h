#pragma once
#include <iostream>
#include <cstdint>
#include <string>

//Все операции через int64_t

class LongLong38 {
public:
	LongLong38( int64_t x = 0 );
	LongLong38( const LongLong38 & other );
	LongLong38 & operator = ( const LongLong38 & other );

	LongLong38 & operator += ( const LongLong38 & ll );
	LongLong38 & operator -= ( const LongLong38 & ll );
	LongLong38 & operator *= ( const LongLong38 & ll );
	LongLong38 & operator /= ( const LongLong38 & ll );

	friend LongLong38 operator + ( const LongLong38 & lhs, const LongLong38 & rhs );
	friend LongLong38 operator - ( const LongLong38 & lhs, const LongLong38 & rhs );
	friend LongLong38 operator * ( const LongLong38 & lhs, const LongLong38 & rhs );
	friend LongLong38 operator / ( const LongLong38 & lhs, const LongLong38 & rhs );

	friend std::ostream & operator << ( std::ostream & out, const LongLong38 & rhs );
	int64_t toInt64( )const;
	std::string ToString( )const;

private:
	std::pair<int32_t, uint32_t> toPair32bit( int64_t x )const;
	int64_t toInt64( std::pair<int32_t, uint32_t> num)const;
	int64_t toInt64( int32_t senjorPart, int32_t junuiorPart)const;
	int64_t invertNegative64int( int64_t negX )const;
	//можно сделать и одну ф-ю, но лень
	std::string printBinary64bit( int64_t num )const;
	std::string printBinary32bit( int32_t num )const;

private:
	const uint32_t MASK_JUNIOR = 0xffffffff;
	long m_seniorPart; //это знаковый инт 32
	unsigned long m_juniorRart; //это беззнаковый инт 32
	bool m_negative{ false }; //нужно для определения нужно-ли инвертировать
};

