#include "Windows.h"
#include "money24a.h"
#include "money24b.h"
#include "money24c.h"
#include <iostream>

int main( )
{
    // setlocale( LC_ALL, "rus" );
    SetConsoleCP( 1251 ); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP( 1251 ); // установка кодовой страницы win-cp 1251 в поток вывода

    std::cout << "Pragma = " << sizeof( Money24A_T ) << "  No Pragma = " << sizeof( Money24A ) << std::endl;
    std::cout << "******* PROGRAMMA MONEY 24 A-A-A ********" << std::endl;
    //Methods demonstration
    Money24A valA1;
    Init( valA1, 10, 50 );
    Display( valA1 );
    Money24A valA2;
    Init( valA2, 21, 0 );
    Display( valA2 );
    Money24A valA3;
    Read( valA3 );
    Display( valA3 );
    Money24A valA4 = Add( valA1, valA2 );
    Display( valA4 );
    valA4 = Sub( valA2, valA1 );
    Display( valA4 );
    valA4 = Sub( valA1, valA2 );
    Display( valA4 );
    valA4 = Mul( valA1, 2 );
    Display( valA4 );
    std::cout << "Div = " << Div( valA4, valA2 ) << std::endl;
    valA4 = Div( valA1, 2 );
    Display( valA4 );

    std::cout << std::boolalpha << Eq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << NotEqu( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Less( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << LessOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Greater( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << GreaterOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::endl;

    valA1 = valA2;
    Display( valA1 );
    Display( valA2 );

    std::cout << std::boolalpha << Eq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << NotEqu( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Less( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << LessOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Greater( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << GreaterOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::endl;

    valA2 = valA4;
    Display( valA1 );
    Display( valA2 );

    std::cout << std::boolalpha << Eq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << NotEqu( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Less( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << LessOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << Greater( valA1, valA2 ) << std::endl;
    std::cout << std::boolalpha << GreaterOrEq( valA1, valA2 ) << std::endl;
    std::cout << std::endl;

    std::cout << "******* PROGRAMMA MONEY 24 B-B-B и C-C-C одинаковы ********" << std::endl;
    //Methods demonstration
    Money24B valB1;
    valB1.Init( 10, 50 );
    valB1.Display( );
    Money24B valB2;
    valB2.Init( 21, 0 );
    valB2.Display( );
    Money24B valB3;
    valB3.Read( );
    valB3.Display( );
    Money24B valB4 = valB1.Add( valB2 );
    valB4.Display( );
    valB4 = valB2.Sub( valB1 );
    valB4.Display( );
    valB4 = valB1.Sub( valB2 );
    valB4.Display( );
    valB4 = valB1.Mul( 2 );
    valB4.Display( );
    std::cout << "Div = " << valB4.Div( valB2 ) << std::endl;
    valB4 = valB1.Div( 2 );
    valB4.Display( );

    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    std::cout << std::endl;

    valB1 = valB2;
    valB1.Display( );
    valB2.Display( );

    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    std::cout << std::endl;

    valB2 = valB4;
    valB1.Display( );
    valB2.Display( );

    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    std::cout << std::endl;

    return 0;
}
