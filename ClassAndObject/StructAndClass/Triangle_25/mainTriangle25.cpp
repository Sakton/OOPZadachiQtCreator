#include "triangle25a.h"
#include <iostream>

int main()
{
    std::cout << "******* PROGRAMMA TRIANGLE 25 A-A-A ********" << std::endl;
    //Methods demonstration
    //inits
    Triangle25A trA1;
    Init( trA1, 6, 6, 60 );
    Display( trA1 );
    std::cout << "H AB = " << HeightToAB( trA1 ) << std::endl;
    std::cout << "H BC = " << HeightToBC( trA1 ) << std::endl;
    std::cout << "H AC = " << HeightToAC( trA1 ) << std::endl;
    std::cout << "S Tringle = " << Area( trA1 ) << std::endl;
    std::cout << "S Perimeter = " << Perimeter( trA1 ) << std::endl;

    switch ( GetType( trA1 ) ) {
	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Triangle25A trA2;
    Init( trA2, 3, 4, 90 );
    Display( trA2 );
    std::cout << "H AB = " << HeightToAB( trA2 ) << std::endl;
    std::cout << "H BC = " << HeightToBC( trA2 ) << std::endl;
    std::cout << "H AC = " << HeightToAC( trA2 ) << std::endl;
    std::cout << "S Tringle = " << Area( trA2 ) << std::endl;
    std::cout << "S Perimeter = " << Perimeter( trA2 ) << std::endl;
    switch ( GetType( trA2 ) ) {
	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Triangle25A trA3;
    Init( trA3, 10, 10, 90 );
    Display( trA3 );
    std::cout << "H AB = " << HeightToAB( trA3 ) << std::endl;
    std::cout << "H BC = " << HeightToBC( trA3 ) << std::endl;
    std::cout << "H AC = " << HeightToAC( trA3 ) << std::endl;
    std::cout << "S Tringle = " << Area( trA3 ) << std::endl;
    std::cout << "S Perimeter = " << Perimeter( trA3 ) << std::endl;
    switch ( GetType( trA3 ) ) {
	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Triangle25A trA4;
    Init( trA4, 10, 10, 50 );
    Display( trA4 );
    std::cout << "H AB = " << HeightToAB( trA4 ) << std::endl;
    std::cout << "H BC = " << HeightToBC( trA4 ) << std::endl;
    std::cout << "H AC = " << HeightToAC( trA4 ) << std::endl;
    std::cout << "S Tringle = " << Area( trA4 ) << std::endl;
    std::cout << "S Perimeter = " << Perimeter( trA4 ) << std::endl;
    switch ( GetType( trA4 ) ) {
	case TYPE_TRIANGLE::PRYAMO_UGOLNY:
	    std::cout << "PRYAMO_UGOLNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_BEDRENNY:
	    std::cout << "RAVNO_BEDRENNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::RAVNO_STORONNY:
	    std::cout << "RAVNO_STORONNY" << std::endl;
	    break;
	case TYPE_TRIANGLE::OTHER:
	    std::cout << "OTHER" << std::endl;
	    break;
    }

    //TODO потом добавить демонстрацию на В-В-В она такая же как и на ССС

    return 0;
}
