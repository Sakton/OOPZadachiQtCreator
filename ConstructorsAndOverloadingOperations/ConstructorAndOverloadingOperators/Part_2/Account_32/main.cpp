
#include <account32.h>

#include <clocale>
#include <iostream>

int main( )
{
    setlocale( LC_ALL, "ru" );

    Account32 acc( "Петров", "1234252345", 6.9, 123598.59 );
    Display( acc );
    std::cout << ToChislitelnoe( acc ) << std::endl;
}
