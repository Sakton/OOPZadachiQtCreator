#include "account43.h"
#include <iostream>

int main( )
{
    Account43 acc;
    acc.Init( "Ptrov", "1231231313131231313", 12.5, 100000000.0, "01.01.2000" );
    acc.Display( );
    acc.AddProcentOnEveryDay( "24.09.2020" );
    acc.Display( );
}
