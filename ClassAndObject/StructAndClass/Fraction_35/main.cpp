#include "fraction35b.h"
#include <iostream>

using namespace std;

int main()
{
    std::cout << "***********fraction35 *************\n";
    //    Fraction35B fr1;
    //    fr1.Init( -1, 0 );
    //    fr1.Display( );

    //    Fraction35B fr2;
    //    fr2.Init( 1, 9998 );

    //    //std::cout << std::boolalpha << fr1.Less( fr2 );

    //    Fraction35B fr3;
    //    fr3.Init( );
    //    fr3 = fr1.Add( fr2 );
    //    fr3.Display( );

    //    Fraction35B fr4;
    //    fr4.Init( );
    //    fr4 = fr1.Sub( fr2 );
    //    fr4.Display( );

    //    Fraction35B fr5;
    //    fr5.Init( 1, 2345 );
    //    fr5.Display( );
    //    fr5.MulDesyatki( 10 ).Display( );
    //    fr5.MulDesyatki( 100 ).Display( );
    //    fr5.MulDesyatki( 1000 ).Display( );
    //    fr5.MulDesyatki( 10000 ).Display( );
    //    fr5.MulDesyatki( 100000 ).Display( );
    //    fr5.MulDesyatki( 1000000 ).Display( );

    //    Fraction35B fr6;
    //    fr6.Init( 1, 1111 );
    //    fr6.Display( );
    //    fr6.MulOneNumber( 0 ).Display( );
    //    fr6.MulOneNumber( 1 ).Display( );
    //    fr6.MulOneNumber( 2 ).Display( );
    //    fr6.MulOneNumber( 3 ).Display( );
    //    fr6.MulOneNumber( 4 ).Display( );
    //    fr6.MulOneNumber( 5 ).Display( );
    //    fr6.MulOneNumber( 6 ).Display( );
    //    fr6.MulOneNumber( 7 ).Display( );
    //    fr6.MulOneNumber( 8 ).Display( );
    //    fr6.MulOneNumber( 9 ).Display( );

    Fraction35B fr7;
    fr7.Init( 5555, 5555 );
    Fraction35B fr8;
    fr8.Init( 2222, 2222 );

    //fr7.OneDivFrac( fr8 ).Display( );

    //std::cout << ( 1 / 2222.2222 );

    fr7.Div( fr8 ).Display( );
}
