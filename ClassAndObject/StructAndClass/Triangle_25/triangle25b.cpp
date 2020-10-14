#include "triangle25b.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

void Triangle25B::Init( double a, double b, double ab )
{
    if ( a < 0 || b < 0 || ab < 0 ) {
	std::cout << "ERROR INIT ARG";
	exit( 1 );
    }
    sAB = a;
    sBC = b;
    sAC = std::sqrt( a * a + b * b - 2 * a * b * std::cos( ab * PI / ANG_PI_2 ) );
    angAB_BC = ab;
    if ( ab != 90.0 ) {
	angAC_AB = std::asin( sAC * std::sin( angAB_BC * PI / ANG_PI_2 ) / sBC ) * ANG_PI_2 / PI;
	angBC_AC = ANG_PI_2 - angAB_BC - angAC_AB;
    } else {
	angAC_AB = std::asin( sBC / sAC ) * ANG_PI_2 / PI;
	angBC_AC = std::asin( sAB / sAC ) * ANG_PI_2 / PI;
    }
}

void Triangle25B::Display( ) const
{
    std::cout << ToString( );
}

void Triangle25B::Read( )
{
    double a, b, bc;
    std::cout << "Enter 2 size and 1 angle" << std::endl;
    std::cin >> a >> b >> bc;
    Init( a, b, bc );
}

std::string Triangle25B::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 3 )
       << "    sizeAB = " << sAB << std::endl
       << "    sizeBC = " << sBC << std::endl
       << "    sizeAC = " << sAC << std::endl
       << "angleAB_BC = " << angAB_BC << std::endl
       << "angleAC_AB = " << angAC_AB << std::endl
       << "angleBC_AC = " << angBC_AC << std::endl;
    return ss.str( );
}

double Triangle25B::GetAB( ) const
{
    return sAB;
}

double Triangle25B::GetBC( ) const
{
    return sBC;
}

double Triangle25B::GetAC( ) const
{
    return sAC;
}

double Triangle25B::GetAngleAB_BC( ) const
{
    return angAB_BC;
}

double Triangle25B::GetAngleBC_AC( ) const
{
    return angBC_AC;
}

double Triangle25B::GetAngleAC_AB( ) const
{
    return angAC_AB;
}

double Triangle25B::Area( ) const
{
    return sAC * HeightToAC( ) / 2;
}

double Triangle25B::Perimeter( ) const
{
    return sAB + sAC + sBC;
}

double Triangle25B::HeightToAB( ) const
{
    return sAC * std::sin( angAC_AB * PI / ANG_PI_2 );
}

double Triangle25B::HeightToBC( ) const
{
    return sAC * std::sin( angBC_AC * PI / ANG_PI_2 );
}

double Triangle25B::HeightToAC( ) const
{
    return sAB * std::sin( angAC_AB * PI / ANG_PI_2 );
}

Triangle25B::TYPE_TRIANGLE Triangle25B::GetType( ) const
{
    if ( ( std::fabs( sAB - sAC ) < 1e-4 ) || ( std::fabs( sAB - sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_BEDRENNY;
    }
    if ( ( std::fabs( angAB_BC - 90.000 ) < 1e-4 ) || ( std::fabs( angAC_AB - 90.000 ) < 1e-4 ) || ( std::fabs( angBC_AC - 90.000 ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::PRYAMO_UGOLNY;
    }
    if ( ( std::fabs( sAB - sAC ) < 1e-4 ) && ( std::fabs( sAB - sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_STORONNY;
    }
    return TYPE_TRIANGLE::OTHER;
}
