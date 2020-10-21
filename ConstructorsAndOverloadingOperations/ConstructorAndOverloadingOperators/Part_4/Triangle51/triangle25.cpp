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

double Triangle25::TheoremaCos( double size1, double size2, Angle26 angle ) {
  return std::sqrt( std::pow( size1, 2 ) + std::pow( size2, 2 ) -
                    2 * size1 * size2 * std::cos( angle.ToRadian( ) ) );
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

Triangle25::Triangle25( double param1, double param2, double param3,
                        Triangle25::TYPE_INITIALISATION type ) {
  switch ( type ) {
    case Triangle25::TYPE_INITIALISATION::SUS: {
      sA = param1;
      sB = param3;
      angC = Angle26( param2 );
      sC = TheoremaCos( sA, sB, angC );
      if ( !Posible( sA, sB, sC ) ) {
        std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
        exit( 1 );
      }
      angA = Angle26( AnglePoTheoremeCos( sB, sC, sA ) );
      angB = Angle26( AnglePoTheoremeCos( sA, sC, sB ) );
    } break;
    case Triangle25::TYPE_INITIALISATION::SSS: {
      if ( !Posible( param1, param2, param3 ) ) {
        std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
        exit( 1 );
      }
      sA = param1;
      sB = param2;
      sC = param3;
      angA = Angle26( AnglePoTheoremeCos( sB, sC, sA ) );
      angB = Angle26( AnglePoTheoremeCos( sA, sC, sB ) );
      angC = Angle26( AnglePoTheoremeCos( sA, sB, sC ) );
    } break;
    case Triangle25::TYPE_INITIALISATION::USS: {
    } break;
    case Triangle25::TYPE_INITIALISATION::USU: {
    } break;
    case Triangle25::TYPE_INITIALISATION::UUS: {
    } break;
  }
}

std::string Triangle25::ToString( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "storona a = " << sA << std::endl
     << "storona b = " << sB << std::endl
     << "storona c = " << sC << std::endl
     << "ang alpha = " << angA.ToString( ) << std::endl
     << "ang betta = " << angB.ToString( ) << std::endl
     << "ang gamma = " << angC.ToString( ) << std::endl;
  return ss.str( );
}

void Triangle25::Display( ) const { std::cout << ToString( ) << std::endl; }

double Triangle25::GetA( ) const { return sA; }

double Triangle25::GetB( ) const { return sB; }

double Triangle25::GetC( ) const { return sC; }

Angle26 Triangle25::GetAngleA( ) const { return angA; }

Angle26 Triangle25::GetAngleB( ) const { return angB; }

Angle26 Triangle25::GetAngleC( ) const { return angC; }

void Triangle25::SetA( double size ) {
  if ( !Posible( size, sB, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( size, sB, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetB( double size ) {
  if ( !Posible( sA, size, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, size, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetC( double size ) {
  if ( !Triangle25::Posible( sA, sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, sB, size, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetAngleA( Angle26 angle ) {
  double size = TheoremaCos( sB, sC, angle );
  if ( !Triangle25::Posible( size, sB, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( size, sB, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetAngleB( Angle26 angle ) {
  double size = Triangle25::TheoremaCos( sA, sC, angle );
  if ( !Triangle25::Posible( sA, size, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, size, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetAngleC( Angle26 angle ) {
  double size = Triangle25::TheoremaCos( sA, sB, angle );
  if ( !Triangle25::Posible( sA, sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, sB, size, Triangle25::TYPE_INITIALISATION::SSS );
}

double Triangle25::Area( ) const {
  double p = Perimeter( ) / 2;
  return std::sqrt( p * ( p - sA ) * ( p - sB ) * ( p - sC ) );
}

double Triangle25::Perimeter( ) const { return sA + sB + sC; }

double Triangle25::HeightToA( ) const { return 2 * Area( ) / sA; }

double Triangle25::HeightToB( ) const { return 2 * Area( ) / sB; }

double Triangle25::HeightToC( ) const { return 2 * Area( ) / sC; }

Triangle25::TYPE_TRIANGLE Triangle25::GetType( ) {
  if ( ( std::fabs( sA - sC ) < 1e-4 ) || ( std::fabs( sA - sB ) < 1e-4 ) ||
       ( std::fabs( sB - sC ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY;
  }
  if ( ( std::fabs( static_cast< double >( angA ) - 90.000 ) < 1e-4 ) ||
       ( std::fabs( static_cast< double >( angB ) - 90.000 ) < 1e-4 ) ||
       ( std::fabs( static_cast< double >( angC ) - 90.000 ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY;
  }
  if ( ( ( std::fabs( sA - sC ) < 1e-4 ) || ( std::fabs( sA - sB ) < 1e-4 ) ||
         ( std::fabs( sB - sC ) < 1e-4 ) ) &&
       ( ( std::fabs( static_cast< double >( angA ) -
                      static_cast< double >( angC ) ) < 1e-4 ) ||
         ( std::fabs( static_cast< double >( angA ) -
                      static_cast< double >( angB ) ) < 1e-4 ) ||
         ( std::fabs( static_cast< double >( angB ) -
                      static_cast< double >( angC ) ) < 1e-4 ) ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY;
  }
  return Triangle25::TYPE_TRIANGLE::OTHER;
}
