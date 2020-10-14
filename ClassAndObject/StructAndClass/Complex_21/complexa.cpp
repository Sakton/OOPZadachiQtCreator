#include "complexa.h"
#include <iomanip>
#include <sstream>

void Init( ComplexA & dt, double a, double b )
{
    //a,b = проверять не надо, вся числовая прямая рациональных чисел
    dt.first = a;
    dt.second = b;
}

void Read( ComplexA & dt )
{
    std::cout << "Enter a b" << std::endl;
    //т.к. проверять не требуется читаем сразу
    std::cin >> dt.first >> dt.second;
}

void Display( const ComplexA & dt )
{
    std::cout << ToString( dt );
}

std::string ToString( const ComplexA & dt )
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 2 ) << "( " << dt.first << " + " << dt.second << "i )";
    return ss.str( );
}

ComplexA Add( const ComplexA & a, const ComplexA & b )
{
    ComplexA res;
    res.first = a.first + b.first;
    res.second = a.second + b.second;
    return res;
}

ComplexA Sub( const ComplexA & a, const ComplexA & b )
{
    ComplexA res;
    res.first = a.first - b.first;
    res.second = a.second - b.second;
    return res;
}

ComplexA Mul( const ComplexA & a, const ComplexA & b )
{
    ComplexA res;
    res.first = a.first * b.first - a.second * b.second;
    res.second = a.first * b.second + a.second * b.first;
    return res;
}

ComplexA Div( const ComplexA & a, const ComplexA & b )
{
    ComplexA res;
    res.first = ( a.first * b.first + a.second * b.second ) / ( b.first * b.first + b.second * b.second );
    res.second = ( a.second * b.first - a.first * b.second ) / ( b.first * b.first + b.second * b.second );
    return res;
}

bool Equ( const ComplexA & a, const ComplexA & b )
{
    return ( a.first == b.first ) && ( a.second == b.second );
}

ComplexA Conj( const ComplexA & a )
{
    ComplexA res = a;
    res.second *= -1;
    return res;
}
