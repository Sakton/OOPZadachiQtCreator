#include "triangle25a.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

void Init( Triangle25A & tr, double a, double b, double ab )
{
    if ( a < 0 || b < 0 || ab < 0 ) {
	std::cout << "ERROR INIT ARG";
	exit( 1 );
    }
    tr.sAB = a;
    tr.sBC = b;
    tr.sAC = std::sqrt( a * a + b * b - 2 * a * b * std::cos( ab * PI / ANG_PI_2 ) );
    tr.angAB_BC = ab;
    if ( ab != 90.0 ) {
	tr.angAC_AB = std::asin( tr.sAC * std::sin( tr.angAB_BC * PI / ANG_PI_2 ) / tr.sBC ) * ANG_PI_2 / PI;
	tr.angBC_AC = ANG_PI_2 - tr.angAB_BC - tr.angAC_AB;
    } else {
	tr.angAC_AB = std::asin( tr.sBC / tr.sAC ) * ANG_PI_2 / PI;
	tr.angBC_AC = std::asin( tr.sAB / tr.sAC ) * ANG_PI_2 / PI;
    }
}

void Display( const Triangle25A & tr )
{
    std::cout << ToString( tr );
}

void Read( Triangle25A & tr )
{
    double a, b, bc;
    std::cout << "Enter 2 size and 1 angle" << std::endl;
    std::cin >> a >> b >> bc;
    Init( tr, a, b, bc );
}

std::string ToString( const Triangle25A & tr )
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 3 )
       << "    sizeAB = " << tr.sAB << std::endl
       << "    sizeBC = " << tr.sBC << std::endl
       << "    sizeAC = " << tr.sAC << std::endl
       << "angleAB_BC = " << tr.angAB_BC << std::endl
       << "angleAC_AB = " << tr.angAC_AB << std::endl
       << "angleBC_AC = " << tr.angBC_AC << std::endl;
    return ss.str( );
}

double GetAB( const Triangle25A & tr )
{
    return tr.sAB;
}

double GetBC( const Triangle25A & tr )
{
    return tr.sBC;
}

double GetAC( const Triangle25A & tr )
{
    return tr.sAC;
}

double GetAngleAB_BC( const Triangle25A & tr )
{
    return tr.angAB_BC;
}

double GetAngleBC_AC( const Triangle25A & tr )
{
    return tr.angBC_AC;
}

double GetAngleAC_AB( const Triangle25A & tr )
{
    return tr.angAC_AB;
}

//void SetAngleAB_BC( Triangle25A & tr, double angle )
//{
//    if ( angle < 0 ) {
//	std::cout << "ERR ARG SetAngleAB_BC";
//	exit( 1 );
//    }
//    Init( tr, tr.sAB, tr.sAC, angle );
//}

//void SetAngleBC_AC( Triangle25A & tr, double angle )
//{
//    if ( angle < 0 ) {
//	std::cout << "ERR ARG SetAngleBC_AC";
//	exit( 1 );
//    }
//    Init( tr, tr.sBC, tr.sAC, angle );
//}

//void SetAngleAC_AB( Triangle25A & tr, double angle )
//{
//    if ( angle < 0 ) {
//	std::cout << "ERR ARG SetAngleAC_AB";
//	exit( 1 );
//    }
//    Init( tr, tr.sAC, tr.sAB, angle );
//}

//void SetAB( Triangle25A & tr, double size )
//{
//    if ( size < 0 ) {
//	std::cout << "ERR ARG SetAB";
//	exit( 1 );
//    }
//}

//void SetBC( Triangle25A & tr, double size )
//{
//    if ( size < 0 ) {
//	std::cout << "ERR ARG SetBC";
//	exit( 1 );
//    }
//    Triangle25A t;
//    Init( t, tr.sAB, size, tr.angAB_BC );
//    tr = t;
//}

//void SetAC( Triangle25A & tr, double size )
//{
//    if ( size < 0 ) {
//	std::cout << "ERR ARG SetAC";
//	exit( 1 );
//    }
//    Triangle25A t;
//    Init( t, tr.sBC, size, tr.angBC_AC );
//    tr = t;
//}

double Area( const Triangle25A & tr )
{
    return tr.sAC * HeightToAC( tr ) / 2;
}

double Perimeter( const Triangle25A & tr )
{
    return tr.sAB + tr.sAC + tr.sBC;
}

double HeightToAB( const Triangle25A & tr )
{
    return tr.sAC * std::sin( tr.angAC_AB * PI / ANG_PI_2 );
}

double HeightToBC( const Triangle25A & tr )
{
    return tr.sAC * std::sin( tr.angBC_AC * PI / ANG_PI_2 );
}

double HeightToAC( const Triangle25A & tr )
{
    return tr.sAB * std::sin( tr.angAC_AB * PI / ANG_PI_2 );
}

TYPE_TRIANGLE GetType( const Triangle25A & tr )
{
    if ( ( std::fabs( tr.sAB - tr.sAC ) < 1e-4 ) || ( std::fabs( tr.sAB - tr.sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_BEDRENNY;
    }
    if ( ( std::fabs( tr.angAB_BC - 90.000 ) < 1e-4 ) || ( std::fabs( tr.angAC_AB - 90.000 ) < 1e-4 ) || ( std::fabs( tr.angBC_AC - 90.000 ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::PRYAMO_UGOLNY;
    }
    if ( ( std::fabs( tr.sAB - tr.sAC ) < 1e-4 ) && ( std::fabs( tr.sAB - tr.sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_STORONNY;
    }
    return TYPE_TRIANGLE::OTHER;
}
