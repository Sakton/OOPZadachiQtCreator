#include "polinom.h"
#include <iostream>

int main( )
{
    //    Polinom5 polinom( 3 );
    //    polinom.Read( );
    //    polinom.Display( );

    //    double arr[ 10 ] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    double arr[] { 3, 2, 1 };
    double arr1[] { 3, 2, 1 };
    std::vector< double > vec { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    Polinom pol( arr, 3 );
    //pol.Display( );

    Polinom pol1( arr1, 3 );
    pol *= pol1;

    pol.Display( );

    //    std::cout << std::endl
    //              << "estimation = " << pol.Estimation( 2 );
    //    std::cout << std::endl;
    //    std::cout << std::endl;
    //    Polinom5 dif = pol.Differentiation( );
    //    dif.Display( );
    //    std::cout << std::endl;
    //    std::cout << std::endl;
    //    Polinom5 integr = dif.Integration( );
    //    integr.Display( );

    //    std::cout << std::endl
    //              << pol.Estimation( 3 ) << std::endl;

    //    Polinom5 pol2( vec );

    //    std::cout << std::fixed << std::endl
    //              << pol2.Estimation( 1 ) << std::endl;
    //    //pol2.Display( );
    //    Polinom5 diff = pol2.Differentiation( );
    //    std::cout << std::fixed << std::endl
    //              << diff.Estimation( 1 ) << std::endl;

    //std::cout << std::fixed << pol2.FastPow( 2, 30 ) << std::endl;
    //    std::cout << std::fixed << std::endl
    //              << pol2.Estimation( 1 ) << std::endl;
}
