#include <iostream>
#include <point27a.h>
#include <point27b.h>
#include <point27c.h>

using namespace std;

int main()
{
    std::cout << "******* PROGRAMMA POINT 27 AAA ********" << std::endl;
    Point27A pt;
    Init( pt, 0, 4 );
    Display( pt );
    Polar pol = ToPolar( pt );
    std::cout << " r =  " << pol.radius << " fi = " << pol.angleFi << std::endl;
    //проверено поштучно

    std::cout << "******* PROGRAMMA POINT 27 BBB && CCC ********" << std::endl;
    //using My = Point27B;
    using My = Point27C;

    My ptB;
    ptB.Init( 0, 4 );
    ptB.Display( );
    My::Polar polar = ptB.ToPolar( );
    std::cout << " r =  " << polar.radius << " fi = " << polar.angleFi << std::endl;
}
