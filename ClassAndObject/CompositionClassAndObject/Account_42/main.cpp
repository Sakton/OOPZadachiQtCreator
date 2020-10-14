#include "account42.h"
#include <iostream>

int main( )
{
    setlocale( LC_ALL, "ru" );

    Account42 acc;
    acc.Init( "Петров", "1234252345", 6.9, 1000 );
    acc.Display( );
    std::cout << acc.ToChislitelnoe( ) << std::endl;
    acc.AddSumm( 1000 );
    acc.Display( );
    acc.SubSumm( 500 );
    acc.Display( );
    acc.AddProcent( );
    acc.Display( );
    std::cout << acc.ToChislitelnoe( ) << std::endl;
}
