
#include <clocale>
#include <iostream>

#include "account32.h"
#include "account32private.h"

int main( )
{
    setlocale( LC_ALL, "ru" );

    Account32pub acc( "Petrov", "1234252345", 6.9, 123598.59 );
    acc.Display( );
    std::cout << acc.ToChislitelnoe( ) << std::endl;

    acc -= 98;
    acc.Display( );
    acc -= 0.59;
    acc.Display( );

    acc.AddProcent( );
    acc.Display( );

    Money24 *mn = new Account32pub( "Petrov", "1234252345", 6.9, 123598.59 );

    *mn -= 98;
    mn->Display( );
    *mn -= 0.59;
    mn->Display( );

    std::cout << "XXXXXXXXXXXXXXXXXXprivateXXXXXXXXXXXXXXXXXXXXX" << std::endl;

    Account32private pacc( "Petrov", "1234252345", 6.9, 123598.59 );
    pacc.Display( );
    pacc -= 98;
    pacc.Display( );
    pacc -= 0.59;
    pacc.Display( );

    pacc.AddProcent( );
    pacc.Display( );
    //    Money24 *mn1 =
    //        new Account32private( "Petrov", "1234252345", 6.9, 123598.59 );
}
