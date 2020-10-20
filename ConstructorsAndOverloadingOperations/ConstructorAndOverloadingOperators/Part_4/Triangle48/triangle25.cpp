#include "triangle25.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const double PIx2 = PI * 2;
const int ANG_PI = 360;

double Triangle25::ToRadian( double angle ) { return angle * PIx2 / ANG_PI; }

double Triangle25::ToAngle( double angle ) { return angle * ANG_PI / PIx2; }

double Triangle25::TheoremaCos( double size1, double size2, double angle ) {
  return std::sqrt( std::pow( size1, 2 ) + std::pow( size2, 2 ) -
                    2 * size1 * size2 * std::cos( ToRadian( angle ) ) );
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
      angC = param2;
      sC = TheoremaCos( sA, sB, angC );
      if ( !Posible( sA, sB, sC ) ) {
        std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
        exit( 1 );
      }
      angA = AnglePoTheoremeCos( sB, sC, sA );
      angB = AnglePoTheoremeCos( sA, sC, sB );
    } break;
    case Triangle25::TYPE_INITIALISATION::SSS: {
      if ( !Posible( param1, param2, param3 ) ) {
        std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
        exit( 1 );
      }
      sA = param1;
      sB = param2;
      sC = param3;
      angA = AnglePoTheoremeCos( sB, sC, sA );
      angB = AnglePoTheoremeCos( sA, sC, sB );
      angC = AnglePoTheoremeCos( sA, sB, sC );
    } break;
    case Triangle25::TYPE_INITIALISATION::USS: {
    } break;
    case Triangle25::TYPE_INITIALISATION::USU: {
    } break;
    case Triangle25::TYPE_INITIALISATION::UUS: {
    } break;
  }
}

std::string Triangle25::ToString( ) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "storona a = " << sA << std::endl
     << "storona b = " << sB << std::endl
     << "storona c = " << sC << std::endl
     << "ang alpha = " << angA << std::endl
     << "ang betta = " << angB << std::endl
     << "ang gamma = " << angC << std::endl;
  return ss.str( );
}

void Triangle25::Display( ) { std::cout << ToString( ) << std::endl; }

double Triangle25::GetA( ) { return sA; }

double Triangle25::GetB( ) { return sB; }

double Triangle25::GetC( ) { return sC; }

double Triangle25::GetAngleA( ) { return sA; }

double Triangle25::GetAngleB( ) { return angB; }

double Triangle25::GetAngleC( ) { return angC; }

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

void Triangle25::SetAngleA( double angle ) {
  double size = TheoremaCos( sB, sC, angle );
  if ( !Triangle25::Posible( size, sB, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( size, sB, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetAngleB( double angle ) {
  double size = Triangle25::TheoremaCos( sA, sC, angle );
  if ( !Triangle25::Posible( sA, size, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, size, sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void Triangle25::SetAngleC( double angle ) {
  double size = Triangle25::TheoremaCos( sA, sB, angle );
  if ( !Triangle25::Posible( sA, sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = Triangle25( sA, sB, size, Triangle25::TYPE_INITIALISATION::SSS );
}

double Triangle25::Area( ) {
  double p = Perimeter( ) / 2;
  return std::sqrt( p * ( p - sA ) * ( p - sB ) * ( p - sC ) );
}

double Triangle25::Perimeter( ) { return sA + sB + sC; }

double Triangle25::HeightToA( ) { return 2 * Area( ) / sA; }

double Triangle25::HeightToB( ) { return 2 * Area( ) / sB; }

double Triangle25::HeightToC( ) { return 2 * Area( ) / sC; }

Triangle25::TYPE_TRIANGLE Triangle25::GetType( ) {
  if ( ( std::fabs( sA - sC ) < 1e-4 ) || ( std::fabs( sA - sB ) < 1e-4 ) ||
       ( std::fabs( sB - sC ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY;
  }
  if ( ( std::fabs( angA - 90.000 ) < 1e-4 ) ||
       ( std::fabs( angB - 90.000 ) < 1e-4 ) ||
       ( std::fabs( angC - 90.000 ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY;
  }
  if ( ( ( std::fabs( sA - sC ) < 1e-4 ) || ( std::fabs( sA - sB ) < 1e-4 ) ||
         ( std::fabs( sB - sC ) < 1e-4 ) ) &&
       ( ( std::fabs( angA - angC ) < 1e-4 ) ||
         ( std::fabs( angA - angB ) < 1e-4 ) ||
         ( std::fabs( angB - angC ) < 1e-4 ) ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY;
  }
  return Triangle25::TYPE_TRIANGLE::OTHER;
}
