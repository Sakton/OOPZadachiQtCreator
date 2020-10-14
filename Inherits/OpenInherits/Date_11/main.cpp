#include "date.h"
#include <iostream>

int main( )
{
    Date dt1( 2019, 10, 20 );
    Date dt2( 2020, 10, 19 );

    std::cout << std::boolalpha << ( dt1 < dt2 ) << std::endl;
    std::cout << std::boolalpha << ( dt1 > dt2 ) << std::endl;
    std::cout << std::boolalpha << ( dt1 <= dt2 ) << std::endl;
    std::cout << std::boolalpha << ( dt1 >= dt2 ) << std::endl;
    std::cout << std::boolalpha << ( dt1 == dt2 ) << std::endl;
    std::cout << std::boolalpha << ( dt1 != dt2 ) << std::endl;
}
