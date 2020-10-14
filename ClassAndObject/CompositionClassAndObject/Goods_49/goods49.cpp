#include "goods49.h"
#include <iostream>
#include <sstream>

void Goods49::Init( const std::string & name, const std::string & date, int32_t id, double price, int32_t count )
{
    name_ = name;
    date_.Init( date );
    id_nakladnoy_ = id;
    price_ = price;
    count_ = count;
}

void Goods49::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Goods49::ToString( ) const
{
    std::stringstream ss;
    ss << Cost( );
    return ss.str( );
}

double Goods49::Cost( ) const
{
    return price_ * count_;
}

double Goods49::Price( ) const
{
    return price_;
}

void Goods49::SetPrice( double price )
{
    if ( price < 0 ) {
	std::cout << "ERROR DATA PRICE";
	exit( 1 );
    }
    if ( price != price_ )
	price_ = price;
}

int32_t Goods49::GetCount( ) const
{
    return count_;
}

void Goods49::SetCount( const int32_t & value )
{
    if ( value < 0 ) {
	std::cout << "ERROR DATA COUNT";
	exit( 1 );
    }
    if ( value != count_ )
	count_ = value;
}

int Goods49::CountDays( const std::string & day ) const
{
    Date29B t;
    t.Init( day );
    return date_.Interval( t );
}

void Goods49::AddCount( int32_t count )
{
    if ( count < 0 ) {
	std::cout << "ERROR DATA COUNT ADD";
	exit( 1 );
    }
    count_ += count;
}

void Goods49::SubCount( int32_t count )
{
    if ( count < 0 || count > count_ ) {
	std::cout << "ERROR DATA COUNT ADD";
	exit( 1 );
    }
    count_ -= count;
}
