#include <iostream>
#include "Money4.h"

int main( )
{
	try {
		Money4 a( "1123456" );
		Money4 b( "9" );
		std::cout << a << "     " << b << std::endl;
 		//std::cout << a.MultOneNumber( a, 2 );
		//std::cout << a.MiltTo_10x( a, 3 );
		//std::cout << ( a * b );
		//std::cout << a.Size( ) << std::endl;
		//for ( int i = 0; i < a.Size( ); ++i )
		//	std::cout << a[ i ] << " ";
		a.DivideModules( a, b );
	}
	catch ( const std::exception & e ) {
		std::cout << e.what( );
	}

}
