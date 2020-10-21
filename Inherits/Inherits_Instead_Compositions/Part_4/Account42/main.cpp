
#include <clocale>
#include <iostream>

#include "account32.h"
#include "account32private.h"

// WARNING ЭТО ЗАДАНИЕ 41 ОШИБОЧКА ВЫШЛА

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

    acc.AddProcent( );
    acc.Display( );

    std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;

    Account32private pacc( "Petrov", "1234252345", 6.9, 123598.59 );
    pacc.Display( );
    pacc -= 98;
    pacc.Display( );
    pacc -= 0.59;
    pacc.Display( );

    pacc.AddProcent( );
    pacc.Display( );
}
