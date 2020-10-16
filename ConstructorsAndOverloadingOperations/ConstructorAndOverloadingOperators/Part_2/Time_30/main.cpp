#include "time30b.h"
#include <iostream>

int main()
{
    Time30B tm;
    tm.Init( 1000 );
    tm.ToTime( 1000 ).Display( );
    std::cout << "min up okr = " << tm.ToMinut( ) << std::endl;
    std::cout << "sec = " << tm.ToSecond( ) << std::endl;
    std::cout << std::endl;

    Time30B tm1;
    tm1.Init( 32000 );
    tm1.Display( );
    std::cout << "sec = " << tm1.ToSecond( ) << std::endl;

    std::cout << std::boolalpha << tm.Eq( tm1 ) << std::endl;
    std::cout << std::boolalpha << tm.Less( tm1 ) << std::endl;
    std::cout << std::boolalpha << tm.Great( tm1 ) << std::endl;
}
