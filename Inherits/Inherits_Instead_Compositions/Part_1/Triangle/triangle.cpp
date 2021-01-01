#include "triangle.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

Triangle::Triangle( double param1, double param2, double param3,
                    TYPE_INITIALISATION type )
    : TriangleBase( param1, param2, param3, type ) {}

double Triangle::Area( ) const {
  double p = Perimeter( ) / 2;
  return std::sqrt( p * ( p - GetA( ) ) * ( p - GetB( ) ) * ( p - GetC( ) ) );
}

double Triangle::Perimeter( ) const { return GetA( ) + GetB( ) + GetC( ); }

double Triangle::HeightToA( ) const { return 2 * Area( ) / GetA( ); }

double Triangle::HeightToB( ) const { return 2 * Area( ) / GetB( ); }

double Triangle::HeightToC( ) const { return 2 * Area( ) / GetC( ); }
