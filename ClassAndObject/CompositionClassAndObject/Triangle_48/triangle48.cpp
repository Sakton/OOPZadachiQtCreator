#include "triangle48.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

void Triangle48::Init( double a, double b, double ab )
{
    if ( a < 0 || b < 0 || ab < 0 ) {
	std::cout << "ERROR INIT ARG";
	exit( 1 );
    }
    sAB = a;
    sBC = b;
    sAC = std::sqrt( a * a + b * b - 2 * a * b * std::cos( ab * PI / ANG_PI_2 ) );
    angAB_BC.Init( ab );
    if ( ab != 90.0 ) {
	angAC_AB.Init( std::asin( sAC * angAB_BC.Sinus( ) /*std::sin( angAB_BC * PI / ANG_PI_2 )*/ / sBC ) * ANG_PI_2 / PI );
	//angBC_AC = ANG_PI_2 - angAB_BC - angAC_AB;
	angBC_AC.Init( static_cast< double >( ANG_PI_2 ) - angAB_BC.Adding( angAC_AB ).Angle( ) );
    } else {
	angAC_AB.Init( std::asin( sBC / sAC ) * ANG_PI_2 / PI );
	angBC_AC.Init( std::asin( sAB / sAC ) * ANG_PI_2 / PI );
    }
}

void Triangle48::Display( ) const
{
    std::cout << ToString( );
}

void Triangle48::Read( )
{
    double a, b, bc;
    std::cout << "Enter 2 size and 1 angle" << std::endl;
    std::cin >> a >> b >> bc;
    Init( a, b, bc );
}

std::string Triangle48::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 3 )
       << "    sizeAB = " << sAB << std::endl
       << "    sizeBC = " << sBC << std::endl
       << "    sizeAC = " << sAC << std::endl
       << "angleAB_BC = " << angAB_BC.ToString( ) << std::endl
       << "angleAC_AB = " << angAC_AB.ToString( ) << std::endl
       << "angleBC_AC = " << angBC_AC.ToString( ) << std::endl;
    return ss.str( );
}

double Triangle48::GetAB( ) const
{
    return sAB;
}

double Triangle48::GetBC( ) const
{
    return sBC;
}

double Triangle48::GetAC( ) const
{
    return sAC;
}

double Triangle48::GetAngleAB_BC( ) const
{
    return angAB_BC.ToRadian( );
}

double Triangle48::GetAngleBC_AC( ) const
{
    return angBC_AC.ToRadian( );
}

double Triangle48::GetAngleAC_AB( ) const
{
    return angAC_AB.ToRadian( );
}

double Triangle48::Area( ) const
{
    return sAC * HeightToAC( ) / 2;
}

double Triangle48::Perimeter( ) const
{
    return sAB + sAC + sBC;
}

double Triangle48::HeightToAB( ) const
{
    return sAC * std::sin( angAC_AB.ToRadian( ) * PI / ANG_PI_2 );
}

double Triangle48::HeightToBC( ) const
{
    return sAC * std::sin( angBC_AC.ToRadian( ) * PI / ANG_PI_2 );
}

double Triangle48::HeightToAC( ) const
{
    return sAB * std::sin( angAC_AB.ToRadian( ) * PI / ANG_PI_2 );
}

Triangle48::TYPE_TRIANGLE Triangle48::GetType( ) const
{
    if ( ( std::fabs( sAB - sAC ) < 1e-4 ) || ( std::fabs( sAB - sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_BEDRENNY;
    }
    if ( ( std::fabs( angAB_BC.Angle( ) - 90.000 ) < 1e-4 ) || ( std::fabs( angAC_AB.Angle( ) - 90.000 ) < 1e-4 ) || ( std::fabs( angBC_AC.Angle( ) - 90.000 ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::PRYAMO_UGOLNY;
    }
    if ( ( std::fabs( sAB - sAC ) < 1e-4 ) && ( std::fabs( sAB - sBC ) < 1e-4 ) ) {
	return TYPE_TRIANGLE::RAVNO_STORONNY;
    }
    return TYPE_TRIANGLE::OTHER;
}
