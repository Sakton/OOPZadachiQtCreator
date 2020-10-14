#include "vector3da.h"
#include "vector3db.h"
#include "vector3dc.h"
#include <iostream>

int main( )
{
    std::cout << "Pragma = " << sizeof( Vector3Da_Test ) << "  No Pragma = " << sizeof( Vector3Da ) << std::endl;
    std::cout << "******* PROGRAMMA VECTOR3D 22 A-A-A ********" << std::endl;

    //Init
    Vector3Da xA, yA;
    Init( xA, 2, 2, 2 );
    Init( yA, 10, 10, 10 );

    Display( xA );
    Display( yA );

    std::cout << ToString( xA ) << std::endl;
    std::cout << ToString( yA ) << std::endl;

    std::cout << "Scalar x, y = " << Scalar( xA, yA ) << std::endl;

    Vector3Da mA = Add( xA, yA );
    Vector3Da nA = Sub( xA, yA );
    Vector3Da oA = Mul( xA, yA );
    Vector3Da pA = Mul( xA, 10 );

    Display( mA );
    Display( nA );
    Display( oA );
    Display( pA );

    std::cout << "Len xA = " << Lenth( xA ) << std::endl;
    std::cout << "Len yA = " << Lenth( yA ) << std::endl;

    std::cout << std::boolalpha << ( VecLen( xA, yA ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xA, yA ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xA, yA ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( xA, xA ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xA, xA ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xA, xA ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( yA, xA ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yA, xA ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yA, xA ) > 0 ) << std::endl;
    std::cout << "EQ:" << std::endl;
    std::cout << std::boolalpha << Equ( xA, yA ) << std::endl;
    std::cout << std::boolalpha << Equ( xA, xA ) << std::endl;

    //Read
    Vector3Da zA;
    Read( zA );
    Display( zA );

    std::cout << "******* PROGRAMMA VECTOR3D 22 B-B-B ********" << std::endl;

    //Init
    Vector3Da xB, yB;
    Init( xB, 2, 2, 2 );
    Init( yB, 10, 10, 10 );

    Display( xB );
    Display( yB );

    std::cout << ToString( xB ) << std::endl;
    std::cout << ToString( yB ) << std::endl;

    std::cout << "Scalar x, y = " << Scalar( xB, yB ) << std::endl;

    Vector3Da mB = Add( xB, yB );
    Vector3Da nB = Sub( xB, yB );
    Vector3Da oB = Mul( xB, yB );
    Vector3Da pB = Mul( xB, 10 );

    Display( mB );
    Display( nB );
    Display( oB );
    Display( pB );

    std::cout << "Len xA = " << Lenth( xB ) << std::endl;
    std::cout << "Len yA = " << Lenth( yB ) << std::endl;

    std::cout << std::boolalpha << ( VecLen( xB, yB ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xB, yB ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xB, yB ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( xB, xB ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xB, xB ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xB, xB ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( yB, xB ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yB, xB ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yB, xB ) > 0 ) << std::endl;
    std::cout << "EQ:" << std::endl;
    std::cout << std::boolalpha << Equ( xB, yB ) << std::endl;
    std::cout << std::boolalpha << Equ( xB, xB ) << std::endl;

    //Read
    Vector3Da zB;
    Read( zB );
    Display( zB );

    std::cout << "******* PROGRAMMA VECTOR3D 22 C-C-C ********" << std::endl;

    //Init
    Vector3Da xC, yC;
    Init( xC, 2, 2, 2 );
    Init( yC, 10, 10, 10 );

    Display( xC );
    Display( yC );

    std::cout << ToString( xC ) << std::endl;
    std::cout << ToString( yC ) << std::endl;

    std::cout << "Scalar x, y = " << Scalar( xC, yC ) << std::endl;

    Vector3Da mC = Add( xC, yC );
    Vector3Da nC = Sub( xC, yC );
    Vector3Da oC = Mul( xC, yC );
    Vector3Da pC = Mul( xC, 10 );

    Display( mC );
    Display( nC );
    Display( oC );
    Display( pC );

    std::cout << "Len xA = " << Lenth( xC ) << std::endl;
    std::cout << "Len yA = " << Lenth( yC ) << std::endl;

    std::cout << std::boolalpha << ( VecLen( xC, yC ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xC, yC ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xC, yC ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( xC, xC ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xC, xC ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( xC, xC ) > 0 ) << std::endl;
    std::cout << std::endl;
    std::cout << std::boolalpha << ( VecLen( yC, xC ) < 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yC, xC ) == 0 ) << std::endl;
    std::cout << std::boolalpha << ( VecLen( yC, xC ) > 0 ) << std::endl;
    std::cout << "EQ:" << std::endl;
    std::cout << std::boolalpha << Equ( xC, yC ) << std::endl;
    std::cout << std::boolalpha << Equ( xC, xC ) << std::endl;

    //Read
    Vector3Da zC;
    Read( zC );
    Display( zC );

    return 0;
}
