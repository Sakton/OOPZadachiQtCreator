
#include <account32b.h>
#include <clocale>
#include <iostream>

int main( )
{

    setlocale( LC_ALL, "ru" );

    Account32B acc;
    acc.Init( "Петров", "1234252345", 6.9, 123598.59 );
    acc.Display( );
    std::cout << acc.ToChislitelnoe( ) << std::endl;
}
