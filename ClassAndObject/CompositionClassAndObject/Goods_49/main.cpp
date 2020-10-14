#include "goods49.h"
#include <iostream>

int main( )
{
    Goods49 gd;
    gd.Init( "aaaa", "27.09.2019", 1, 100.0, 2000 );
    std::cout << gd.CountDays( "27.09.2020" );
}
