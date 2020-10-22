#include "triangle25.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const double PIx2 = PI * 2;
const int ANG_PI = 360;

double Triangle25::ToRadian( double angle ) { return angle * PIx2 / ANG_PI; }

double Triangle25::ToAngle( double radian ) { return radian * ANG_PI / PIx2; }

double Triangle25::TheoremaCos( double size1, double size2, double angle ) {
  return std::sqrt( std::pow( size1, 2 ) + std::pow( size2, 2 ) -
                    2 * size1 * size2 * std::cos( angle ) );
}

double Triangle25::AnglePoTheoremeCos( double size1, double size2,
                                       double x_size ) {
  return ToAngle( std::acos(
      ( std::pow( size1, 2 ) + std::pow( size2, 2 ) - std::pow( x_size, 2 ) ) /
      2 / size1 / size2 ) );
}

double Triangle25::TheoremaSinAngle( double size1, double angle1,
                                     double x_size ) {
  return ToAngle(
      std::asin( x_size * std::sin( ToRadian( angle1 ) ) / size1 ) );
}

bool Triangle25::Posible( double a, double b, double c ) {
  return ( ( a < b + c ) && ( b < a + c ) && ( c < a + b ) );
}

Triangle25::Triangle25( const Point27 &A, const Point27 &B, const Point27 &C )
    : A_( A ), B_( B ), C_( C ) {}

std::string Triangle25::ToString( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "storona a = " << GetA( ) << std::endl
     << "storona b = " << GetB( ) << std::endl
     << "storona c = " << GetC( ) << std::endl
     << "ang alpha = " << static_cast< double >( GetAngleA( ) ) << std::endl
     << "ang betta = " << static_cast< double >( GetAngleB( ) ) << std::endl
     << "ang gamma = " << static_cast< double >( GetAngleC( ) ) << std::endl;
  return ss.str( );
}

void Triangle25::Display( ) const { std::cout << ToString( ) << std::endl; }

double Triangle25::GetA( ) const { return B_.Distance( C_ ); }

double Triangle25::GetB( ) const { return A_.Distance( C_ ); }

double Triangle25::GetC( ) const { return A_.Distance( B_ ); }

double Triangle25::GetAngleA( ) const {
  return AnglePoTheoremeCos( A_.Distance( B_ ), A_.Distance( C_ ),
                             B_.Distance( C_ ) );
}

double Triangle25::GetAngleB( ) const {
  return AnglePoTheoremeCos( A_.Distance( B_ ), B_.Distance( C_ ),
                             C_.Distance( A_ ) );
}

double Triangle25::GetAngleC( ) const {
  return AnglePoTheoremeCos( A_.Distance( C_ ), B_.Distance( C_ ),
                             A_.Distance( B_ ) );
}

double Triangle25::Area( ) const {
  double p = Perimeter( ) / 2;
  return std::sqrt( p * ( p - GetA( ) ) * ( p - GetB( ) ) * ( p - GetC( ) ) );
}

double Triangle25::Perimeter( ) const { return GetA( ) + GetB( ) + GetC( ); }

double Triangle25::HeightToA( ) const { return 2 * Area( ) / GetA( ); }

double Triangle25::HeightToB( ) const { return 2 * Area( ) / GetB( ); }

double Triangle25::HeightToC( ) const { return 2 * Area( ) / GetC( ); }

Triangle25::TYPE_TRIANGLE Triangle25::GetType( ) {
  if ( ( std::fabs( GetA( ) - GetC( ) ) < 1e-4 ) ||
       ( std::fabs( GetA( ) - GetB( ) ) < 1e-4 ) ||
       ( std::fabs( GetB( ) - GetC( ) ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY;
  }
  if ( ( std::fabs( static_cast< double >( GetAngleA( ) ) - 90.000 ) < 1e-4 ) ||
       ( std::fabs( static_cast< double >( GetAngleB( ) ) - 90.000 ) < 1e-4 ) ||
       ( std::fabs( static_cast< double >( GetAngleC( ) ) - 90.000 ) <
         1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY;
  }
  if ( ( ( std::fabs( GetA( ) - GetC( ) ) < 1e-4 ) ||
         ( std::fabs( GetA( ) - GetB( ) ) < 1e-4 ) ||
         ( std::fabs( GetB( ) - GetC( ) ) < 1e-4 ) ) &&
       ( ( std::fabs( static_cast< double >( GetAngleA( ) ) -
                      static_cast< double >( GetAngleB( ) ) ) < 1e-4 ) ||
         ( std::fabs( static_cast< double >( GetAngleA( ) ) -
                          static_cast< double >( GetAngleB( ) ) <
                      1e-4 ) ||
           ( std::fabs( static_cast< double >( GetAngleB( ) ) -
                        static_cast< double >( GetAngleC( ) ) ) < 1e-4 ) ) ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY;
  }
  return Triangle25::TYPE_TRIANGLE::OTHER;
}

Point27 Triangle25::C( ) const { return C_; }

void Triangle25::setC( const Point27 &C ) { *this = Triangle25( A_, B_, C ); }

Point27 Triangle25::B( ) const { return B_; }

void Triangle25::setB( const Point27 &B ) { *this = Triangle25( A_, B, C_ ); }

Point27 Triangle25::A( ) const { return A_; }

void Triangle25::setA( const Point27 &A ) { *this = Triangle25( A, B_, C_ ); }
