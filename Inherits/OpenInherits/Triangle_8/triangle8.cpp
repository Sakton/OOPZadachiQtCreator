#include "triangle8.h"
#include <iostream>

Triangle8::Triangle8( int32_t ab, int32_t bc, int32_t ac )
    : ab_ { ab }
    , bc_ { bc }
    , ac_ { ac }
{
    //проверки: 1.если отрицательные 2. Сумма 2 любых меньше или равна третьей - это выход из программы
}

void Triangle8::Display( ) const
{
    std::cout << static_cast< std::string >( *this ) << std::endl;
}

Triangle8::operator std::string( ) const
{
    return std::to_string( ab( ) ) + ", " + std::to_string( bc( ) ) + ", " + std::to_string( ac( ) ) + ", " + " perimetr = " + std::to_string( Perimetr( ) ) + " angA = " + std::to_string( angA( ) ) + " angB = " + std::to_string( angB( ) ) + " angC = " + std::to_string( angC( ) );
}

double Triangle8::Perimetr( ) const
{
    return ab_ + bc_ + ac_;
}

//TODO что то в формулах углов... уже не вижу ничего
double Triangle8::angA( ) const
{
    return std::acos( double( bc( ) * bc( ) + ac( ) * ac( ) - ab( ) * ab( ) ) / ( 2 * bc( ) * ac( ) ) ) * 180 / 3.14;
}

double Triangle8::angB( ) const
{
    return std::acos( double( ab( ) * ab( ) + bc( ) * bc( ) - ac( ) * ac( ) ) / ( 2 * ab( ) * bc( ) ) ) * 180 / 3.14;
}

double Triangle8::angC( ) const
{
    return 180 - angA( ) - angB( );
}

int32_t Triangle8::ab( ) const
{
    return ab_;
}

void Triangle8::setAb( const int32_t & ab )
{
    ab_ = ab;
}

int32_t Triangle8::bc( ) const
{
    return bc_;
}

void Triangle8::setBc( const int32_t & bc )
{
    bc_ = bc;
}

int32_t Triangle8::ac( ) const
{
    return ac_;
}

void Triangle8::setAc( const int32_t & ac )
{
    ac_ = ac;
}
