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

std::string ToString( const Triangle25& tr ) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "storona a = " << tr.sA << std::endl
     << "storona b = " << tr.sB << std::endl
     << "storona c = " << tr.sC << std::endl
     << "ang alpha = " << tr.angA << std::endl
     << "ang betta = " << tr.angB << std::endl
     << "ang gamma = " << tr.angC << std::endl;
  return ss.str( );
}

void Display( const Triangle25& tr ) {
  std::cout << ToString( tr ) << std::endl;
}

double GetA( const Triangle25& tr ) { return tr.sA; }

double GetB( const Triangle25& tr ) { return tr.sB; }

double GetC( const Triangle25& tr ) { return tr.sC; }

double GetAngleA( const Triangle25& tr ) { return tr.sA; }

double GetAngleB( const Triangle25& tr ) { return tr.angB; }

double GetAngleC( const Triangle25& tr ) { return tr.angC; }

void SetA( Triangle25& tr, double size ) {
  if ( !tr.Posible( size, tr.sB, tr.sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( size, tr.sB, tr.sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void SetB( Triangle25& tr, double size ) {
  if ( !tr.Posible( tr.sA, size, tr.sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( tr.sA, size, tr.sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void SetC( Triangle25& tr, double size ) {
  if ( !Triangle25::Posible( tr.sA, tr.sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( tr.sA, tr.sB, size, Triangle25::TYPE_INITIALISATION::SSS );
}

void SetAngleA( Triangle25& tr, double angle ) {
  double size = tr.TheoremaCos( tr.sB, tr.sC, angle );
  if ( !Triangle25::Posible( size, tr.sB, tr.sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( size, tr.sB, tr.sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void SetAngleB( Triangle25& tr, double angle ) {
  double size = Triangle25::TheoremaCos( tr.sA, tr.sC, angle );
  if ( !Triangle25::Posible( tr.sA, size, tr.sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( tr.sA, size, tr.sC, Triangle25::TYPE_INITIALISATION::SSS );
}

void SetAngleC( Triangle25& tr, double angle ) {
  double size = Triangle25::TheoremaCos( tr.sA, tr.sB, angle );
  if ( !Triangle25::Posible( tr.sA, tr.sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  tr = Triangle25( tr.sA, tr.sB, size, Triangle25::TYPE_INITIALISATION::SSS );
}

double Area( const Triangle25& tr ) {
  double p = Perimeter( tr ) / 2;
  return std::sqrt( p * ( p - tr.sA ) * ( p - tr.sB ) * ( p - tr.sC ) );
}

double Perimeter( const Triangle25& tr ) { return tr.sA + tr.sB + tr.sC; }

double HeightToA( const Triangle25& tr ) { return 2 * Area( tr ) / tr.sA; }

double HeightToB( const Triangle25& tr ) { return 2 * Area( tr ) / tr.sB; }

double HeightToC( const Triangle25& tr ) { return 2 * Area( tr ) / tr.sC; }

Triangle25::TYPE_TRIANGLE GetType( const Triangle25& tr ) {
  if ( ( std::fabs( tr.sA - tr.sC ) < 1e-4 ) ||
       ( std::fabs( tr.sA - tr.sB ) < 1e-4 ) ||
       ( std::fabs( tr.sB - tr.sC ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY;
  }
  if ( ( std::fabs( tr.angA - 90.000 ) < 1e-4 ) ||
       ( std::fabs( tr.angB - 90.000 ) < 1e-4 ) ||
       ( std::fabs( tr.angC - 90.000 ) < 1e-4 ) ) {
    return Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY;
  }
  if ( ( ( std::fabs( tr.sA - tr.sC ) < 1e-4 ) ||
         ( std::fabs( tr.sA - tr.sB ) < 1e-4 ) ||
         ( std::fabs( tr.sB - tr.sC ) < 1e-4 ) ) &&
       ( ( std::fabs( tr.angA - tr.angC ) < 1e-4 ) ||
         ( std::fabs( tr.angA - tr.angB ) < 1e-4 ) ||
         ( std::fabs( tr.angB - tr.angC ) < 1e-4 ) ) ) {
    return Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY;
  }
  return Triangle25::TYPE_TRIANGLE::OTHER;
}
