#include "triangle48.h"
#include <iostream>

using namespace std;

int main()
{
    std::cout << "******* PROGRAMMA TRIANGLE 25 A-A-A ********" << std::endl;
    //Methods demonstration
    //inits
    Triangle48 trA1;
    trA1.Init( 6, 6, 60 );
    trA1.Display( );
    std::cout << "H AB = " << trA1.HeightToAB( ) << std::endl;
    std::cout << "H BC = " << trA1.HeightToBC( ) << std::endl;
    std::cout << "H AC = " << trA1.HeightToAC( ) << std::endl;
    std::cout << "S Tringle = " << trA1.Area( ) << std::endl;
    std::cout << "S Perimeter = " << trA1.Perimeter( ) << std::endl;

    switch ( trA1.GetType( ) ) {
	case Triangle48::TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Triangle48 trA2;
    trA2.Init( 3, 4, 90 );
    trA2.Display( );
    std::cout << "H AB = " << trA2.HeightToAB( ) << std::endl;
    std::cout << "H BC = " << trA2.HeightToBC( ) << std::endl;
    std::cout << "H AC = " << trA2.HeightToAC( ) << std::endl;
    std::cout << "S Tringle = " << trA2.Area( ) << std::endl;
    std::cout << "S Perimeter = " << trA2.Perimeter( ) << std::endl;
    switch ( trA2.GetType( ) ) {
	case Triangle48::TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case Triangle48::TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //    Triangle48 trA3;
    //    Init( trA3, 10, 10, 90 );
    //    Display( trA3 );
    //    std::cout << "H AB = " << HeightToAB( trA3 ) << std::endl;
    //    std::cout << "H BC = " << HeightToBC( trA3 ) << std::endl;
    //    std::cout << "H AC = " << HeightToAC( trA3 ) << std::endl;
    //    std::cout << "S Tringle = " << Area( trA3 ) << std::endl;
    //    std::cout << "S Perimeter = " << Perimeter( trA3 ) << std::endl;
    //    switch ( GetType( trA3 ) ) {
    //	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
    //	    std::cout << "PRYAMO_UGOLNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
    //	    std::cout << "RAVNO_BEDRENNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::RAVNO_STORONNY:
    //	    std::cout << "RAVNO_STORONNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::OTHER:
    //	    std::cout << "OTHER" << std::endl;
    //	    break;
    //    }
    //    std::cout << std::endl;
    //    std::cout << std::endl;

    //    Triangle48 trA4;
    //    Init( trA4, 10, 10, 50 );
    //    Display( trA4 );
    //    std::cout << "H AB = " << HeightToAB( trA4 ) << std::endl;
    //    std::cout << "H BC = " << HeightToBC( trA4 ) << std::endl;
    //    std::cout << "H AC = " << HeightToAC( trA4 ) << std::endl;
    //    std::cout << "S Tringle = " << Area( trA4 ) << std::endl;
    //    std::cout << "S Perimeter = " << Perimeter( trA4 ) << std::endl;
    //    switch ( GetType( trA4 ) ) {
    //	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
    //	    std::cout << "PRYAMO_UGOLNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
    //	    std::cout << "RAVNO_BEDRENNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::RAVNO_STORONNY:
    //	    std::cout << "RAVNO_STORONNY" << std::endl;
    //	    break;
    //	case TYPE_TRIANGLE::OTHER:
    //	    std::cout << "OTHER" << std::endl;
    //	    break;
    //    }

    //TODO потом добавить демонстрацию на В-В-В она такая же как и на ССС
}
