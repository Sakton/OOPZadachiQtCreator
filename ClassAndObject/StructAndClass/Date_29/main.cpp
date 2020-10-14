#include "date29b.h"
#include <iostream>
#include <string>

int main()
{
    //    Date29B dt;
    //    dt.Init( "01.02.2020" );
    //    dt.AddDay( 29 ).Display( );
    //    std::cout << std::endl;
    //    dt.AddDay( 731 ).Display( );
    //    std::cout << std::endl;
    //    dt.AddDay( 732 ).Display( );
    //    std::cout << std::endl;
    //    dt.AddDay( 733 ).Display( );
    //    std::cout << std::endl;
    //    dt.AddDay( 734 ).Display( );
    //    std::cout << std::endl;
    //    dt.AddDay( 735 ).Display( );
    //    std::cout << std::endl;
    //    std::cout << std::endl;
    //    std::cout << std::endl;

    //    Date29B dt1;
    //    dt1.Init( "30.12.2018" );
    //    dt1.AddDay( 1 ).Display( );
    //    std::cout << std::endl;
    //    dt1.AddDay( 2 ).Display( );
    //    std::cout << std::endl;
    //    dt1.AddDay( 3 ).Display( );
    //    std::cout << std::endl;
    //    dt1.AddDay( 300 ).Display( );
    //    std::cout << std::endl;
    //    dt1.AddDay( 350 ).Display( );
    //    std::cout << std::endl;
    //    std::cout << std::endl;

    Date29B dt2;
    dt2.Init( "21.10.2029" );
    dt2.SubDay( 45 ).Display( );
    //    std::cout << std::endl;
    //    dt2.SubDay( 2 ).Display( );
    //    std::cout << std::endl;
    //    std::cout << std::endl;

    //    dt2.SubDay( 58 ).Display( );
    //    std::cout << std::endl;
    //    dt2.SubDay( 59 ).Display( );
    //    std::cout << std::endl;
    //    dt2.SubDay( 60 ).Display( );
    //    std::cout << std::endl;

    //    dt2.SubDay( 3593 ).Display( );

    Date29B dt3;
    dt3.Init( "20.09.2020" );
    std::cout << dt3.Interval( dt2 ) << std::endl;

    // ПРОГРАММА ПРОТЕСТИРОВАНА СТО ТЫЩ РАЗ!!ПОКА ДЕЛАЛАСЬ
}
