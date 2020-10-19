
#include <account32.h>

#include <clocale>
#include <iostream>

int main( )
{
    setlocale( LC_ALL, "ru" );

    Account32 acc( "Petrov", "1234252345", 6.9, 123598.59 );
    acc.Display( );
    std::cout << acc.ToChislitelnoe( ) << std::endl;

    acc -= 98;
    acc.Display( );
    acc -= 0.59;
    acc.Display( );
}
