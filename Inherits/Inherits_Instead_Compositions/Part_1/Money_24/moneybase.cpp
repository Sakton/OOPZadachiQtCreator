#include "moneybase.h"
#include <iostream>

MoneyBase::MoneyBase( int32_t rb, int16_t cp )
    : rub { 0 }
    , cop { 0 }
{
    if ( rb < 0 || cp < 0 ) {
        std::cout << "ERROR";
        exit( 1 );
    }
    rub = rb;
    cop = cp;
}

int32_t MoneyBase::getRub( ) const
{
    return rub;
}

void MoneyBase::setRub( const int32_t & value )
{
    rub = value;
}

uint8_t MoneyBase::getCop( ) const
{
    return cop;
}

void MoneyBase::setCop( const uint8_t & value )
{
    cop = value;
}
