#include "triangle25c.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

void DataTringle::Init( double a, double b, double ab )
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
    }
    else {
	angAC_AB = std::asin( sBC / sAC ) * ANG_PI_2 / PI;
	angBC_AC = std::asin( sAB / sAC ) * ANG_PI_2 / PI;
    }
}

void DataTringle::Display( ) const
{
    std::cout << ToString( );
}

void DataTringle::Read( )
{
    double a, b, bc;
    std::cout << "Enter 2 size and 1 angle" << std::endl;
    std::cin >> a >> b >> bc;
    Init( a, b, bc );
}

std::string DataTringle::ToString( ) const
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

void Triangle25C::Init( double a, double b, double ab )
{
    data_.Init( a, b, ab );
}

void Triangle25C::Display( ) const
{
    data_.Display( );
}

void Triangle25C::Read( )
{
    data_.Read( );
}

std::string Triangle25C::ToString( ) const
{
    return data_.ToString( );
}

double Triangle25C::GetAB( ) const
{
    return data_.sAB;
}

double Triangle25C::GetBC( ) const
{
    return data_.sBC;
}

double Triangle25C::GetAC( ) const
{
    return data_.sAC;
}

double Triangle25C::GetAngleAB_BC( ) const
{
    return data_.angAB_BC;
}

double Triangle25C::GetAngleBC_AC( ) const
{
    return data_.angBC_AC;
}

double Triangle25C::GetAngleAC_AB( ) const
{
    return data_.angAC_AB;
}

double Triangle25C::Area( ) const
{
    return data_.sAC * HeightToAC( ) / 2;
}

double Triangle25C::Perimeter( ) const
{
    return data_.sAB + data_.sAC + data_.sBC;
}

double Triangle25C::HeightToAB( ) const
{
    return data_.sAC * std::sin( data_.angAC_AB * DataTringle::PI / DataTringle::ANG_PI_2 );
}

double Triangle25C::HeightToBC( ) const
{
    return data_.sAC * std::sin( data_.angBC_AC * DataTringle::PI / DataTringle::ANG_PI_2 );
}

double Triangle25C::HeightToAC( ) const
{
    return data_.sAB * std::sin( data_.angAC_AB * DataTringle::PI / DataTringle::ANG_PI_2 );
}

DataTringle::TYPE_TRIANGLE Triangle25C::GetType( ) const
{
    if ( ( std::fabs( data_.sAB - data_.sAC ) < 1e-4 ) || ( std::fabs( data_.sAB - data_.sBC ) < 1e-4 ) ) {
	return DataTringle::TYPE_TRIANGLE::RAVNO_BEDRENNY;
    }
    if ( ( std::fabs( data_.angAB_BC - 90.000 ) < 1e-4 ) || ( std::fabs( data_.angAC_AB - 90.000 ) < 1e-4 ) || ( std::fabs( data_.angBC_AC - 90.000 ) < 1e-4 ) ) {
	return DataTringle::TYPE_TRIANGLE::PRYAMO_UGOLNY;
    }
    if ( ( std::fabs( data_.sAB - data_.sAC ) < 1e-4 ) && ( std::fabs( data_.sAB - data_.sBC ) < 1e-4 ) ) {
	return DataTringle::TYPE_TRIANGLE::RAVNO_STORONNY;
    }
    return DataTringle::TYPE_TRIANGLE::OTHER;
}
