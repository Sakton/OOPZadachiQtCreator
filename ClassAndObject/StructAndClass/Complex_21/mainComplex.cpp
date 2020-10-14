#include "complexa.h"
#include "complexb.h"
#include "complexc.h"
#include <iostream>

int main()
{
    std::cout << "Pragma = " << sizeof( ComplexA_Tested ) << "  No Pragma = " << sizeof( ComplexA ) << std::endl;
    std::cout << "******* PROGRAMMA COMPLEX 21 A-A-A ********" << std::endl;
    //Methods demonstration
    ComplexA a, b;
    Init( a, 1.1, 2.2 );
    Init( b, 3.3, 4.4 );
    Display( a );
    std::cout << std::endl;
    Display( b );
    std::cout << std::endl;

    ComplexA c = Add( a, b );
    ComplexA d = Sub( a, b );
    ComplexA e = Div( a, b );
    ComplexA f = Mul( a, b );

    Display( c );
    std::cout << std::endl;
    Display( d );
    std::cout << std::endl;
    Display( e );
    std::cout << std::endl;
    Display( f );
    std::cout << std::endl;

    ComplexA l = Conj( a );
    ComplexA m = Conj( b );

    Display( l );
    std::cout << std::endl;
    Display( m );
    std::cout << std::endl;

    //    ComplexA aa;
    //    Read( aa );
    //    Display( aa );
    //    std::cout << std::endl;

    //arrays
    ComplexA arr[ 10 ];
    for ( int i = 0; i < 10; ++i ) {
	Init( arr[ i ], i + 1, -i - 1 );
    }
    for ( int i = 0; i < 10; ++i ) {
	Display( arr[ i ] );
	std::cout << std::endl;
    }
    //**************************************************************************************************
    std::cout << "******* PROGRAMMA COMPLEX 21 B-B-B ********" << std::endl;

    //Methods demonstration
    ComplexB aB, bB;
    aB.Init( 1.1, 2.2 );
    bB.Init( 3.3, 4.4 );
    aB.Display( );
    std::cout << std::endl;
    bB.Display( );
    std::cout << std::endl;

    ComplexB cB = aB.Add( bB );
    ComplexB dB = aB.Sub( bB );
    ComplexB eB = aB.Div( bB );
    ComplexB fB = aB.Mul( bB );

    cB.Display( );
    std::cout << std::endl;
    dB.Display( );
    std::cout << std::endl;
    eB.Display( );
    std::cout << std::endl;
    fB.Display( );
    std::cout << std::endl;

    ComplexB lB = aB.Conj( );
    ComplexB mB = bB.Conj( );

    lB.Display( );
    std::cout << std::endl;
    mB.Display( );
    std::cout << std::endl;

    ComplexB aaB;
    aaB.Read( );
    aaB.Display( );
    std::cout << std::endl;

    //arrays
    ComplexB arrB[ 10 ];
    for ( int i = 0; i < 10; ++i ) {
	arrB[ i ].Init( i + 1, -i - 1 );
    }
    for ( int i = 0; i < 10; ++i ) {
	arrB[ i ].Display( );
	std::cout << std::endl;
    }

    //**************************************************************************************************
    std::cout << "******* PROGRAMMA COMPLEX 21 C-C-C ********" << std::endl;

    //Methods demonstration
    ComplexC aC, bC;
    aC.Init( 1.1, 2.2 );
    bC.Init( 3.3, 4.4 );
    aC.Display( );
    std::cout << std::endl;
    bC.Display( );
    std::cout << std::endl;

    ComplexC cC = aC.Add( bC );
    ComplexC dC = aC.Sub( bC );
    ComplexC eC = aC.Div( bC );
    ComplexC fC = aC.Mul( bC );

    cC.Display( );
    std::cout << std::endl;
    dC.Display( );
    std::cout << std::endl;
    eC.Display( );
    std::cout << std::endl;
    fC.Display( );
    std::cout << std::endl;

    ComplexC lC = aC.Conj( );
    ComplexC mC = bC.Conj( );

    lC.Display( );
    std::cout << std::endl;
    mC.Display( );
    std::cout << std::endl;

    ComplexC aaC;
    aaC.Read( );
    aaC.Display( );
    std::cout << std::endl;

    //arrays
    ComplexC arrC[ 10 ];
    for ( int i = 0; i < 10; ++i ) {
	arrC[ i ].Init( i + 1, -i - 1 );
    }
    for ( int i = 0; i < 10; ++i ) {
	arrC[ i ].Display( );
	std::cout << std::endl;
    }

    return 0;
}
