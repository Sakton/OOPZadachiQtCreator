#include "trianglebase.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const double PIx2 = PI * 2;
const int ANG_PI = 360;

double TriangleBase::ToRadian( double angle ) { return angle * PIx2 / ANG_PI; }

double TriangleBase::ToAngle( double angle ) { return angle * ANG_PI / PIx2; }

double TriangleBase::TheoremaCos( double size1, double size2, double angle ) {
  return std::sqrt( std::pow( size1, 2 ) + std::pow( size2, 2 ) -
                    2 * size1 * size2 * std::cos( ToRadian( angle ) ) );
}

double TriangleBase::AnglePoTheoremeCos( double size1, double size2,
                                         double x_size ) {
  return ToAngle( std::acos(
      ( std::pow( size1, 2 ) + std::pow( size2, 2 ) - std::pow( x_size, 2 ) ) /
      2 / size1 / size2 ) );
}

double TriangleBase::TheoremaSinAngle( double size1, double angle1,
                                       double x_size ) {
  return ToAngle(
      std::asin( x_size * std::sin( ToRadian( angle1 ) ) / size1 ) );
}

bool TriangleBase::Posible( double a, double b, double c ) {
  return ( ( a < b + c ) && ( b < a + c ) && ( c < a + b ) );
}

//**********************************
TriangleBase::TriangleBase( double param1, double param2, double param3,
                            TYPE_INITIALISATION type ) {
  switch ( type ) {
    case TriangleBase::TYPE_INITIALISATION::SUS: {
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
    case TriangleBase::TYPE_INITIALISATION::SSS: {
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
    case TriangleBase::TYPE_INITIALISATION::USS: {
    } break;
    case TriangleBase::TYPE_INITIALISATION::USU: {
    } break;
    case TriangleBase::TYPE_INITIALISATION::UUS: {
    } break;
  }
}

TriangleBase::operator std::string( ) const {
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

void TriangleBase::Display( ) const {
  std::cout << std::string( *this ) << std::endl;
}

double TriangleBase::GetA( ) const { return sA; }

double TriangleBase::GetB( ) const { return sB; }

double TriangleBase::GetC( ) const { return sC; }

double TriangleBase::GetAngleA( ) const { return sA; }

double TriangleBase::GetAngleB( ) const { return angB; }

double TriangleBase::GetAngleC( ) const { return angC; }

void TriangleBase::SetA( double size ) {
  if ( !Posible( size, sB, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( size, sB, sC, TriangleBase::TYPE_INITIALISATION::SSS );
}

void TriangleBase::SetB( double size ) {
  if ( !Posible( sA, size, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( sA, size, sC, TriangleBase::TYPE_INITIALISATION::SSS );
}

void TriangleBase::SetC( double size ) {
  if ( !TriangleBase::Posible( sA, sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( sA, sB, size, TriangleBase::TYPE_INITIALISATION::SSS );
}

void TriangleBase::SetAngleA( double angle ) {
  double size = TheoremaCos( sB, sC, angle );
  if ( !TriangleBase::Posible( size, sB, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( size, sB, sC, TriangleBase::TYPE_INITIALISATION::SSS );
}

void TriangleBase::SetAngleB( double angle ) {
  double size = TriangleBase::TheoremaCos( sA, sC, angle );
  if ( !TriangleBase::Posible( sA, size, sC ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( sA, size, sC, TriangleBase::TYPE_INITIALISATION::SSS );
}

void TriangleBase::SetAngleC( double angle ) {
  double size = TriangleBase::TheoremaCos( sA, sB, angle );
  if ( !TriangleBase::Posible( sA, sB, size ) ) {
    std::cerr << "ERROR TRIANGLE IMPOSSIBLE";
    exit( 1 );
  }
  *this = TriangleBase( sA, sB, size, TriangleBase::TYPE_INITIALISATION::SSS );
}

TriangleBase::TYPE_TRIANGLE GetType( const TriangleBase& tr ) {
  if ( ( std::fabs( tr.sA - tr.sC ) < 1e-4 ) ||
       ( std::fabs( tr.sA - tr.sB ) < 1e-4 ) ||
       ( std::fabs( tr.sB - tr.sC ) < 1e-4 ) ) {
    return TriangleBase::TYPE_TRIANGLE::RAVNO_BEDRENNY;
  }
  if ( ( std::fabs( tr.angA - 90.000 ) < 1e-4 ) ||
       ( std::fabs( tr.angB - 90.000 ) < 1e-4 ) ||
       ( std::fabs( tr.angC - 90.000 ) < 1e-4 ) ) {
    return TriangleBase::TYPE_TRIANGLE::PRYAMO_UGOLNY;
  }
  if ( ( ( std::fabs( tr.sA - tr.sC ) < 1e-4 ) ||
         ( std::fabs( tr.sA - tr.sB ) < 1e-4 ) ||
         ( std::fabs( tr.sB - tr.sC ) < 1e-4 ) ) &&
       ( ( std::fabs( tr.angA - tr.angC ) < 1e-4 ) ||
         ( std::fabs( tr.angA - tr.angB ) < 1e-4 ) ||
         ( std::fabs( tr.angB - tr.angC ) < 1e-4 ) ) ) {
    return TriangleBase::TYPE_TRIANGLE::RAVNO_STORONNY;
  }
  return TriangleBase::TYPE_TRIANGLE::OTHER;
}
