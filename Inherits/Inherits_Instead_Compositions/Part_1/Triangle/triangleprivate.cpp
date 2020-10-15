#include "triangleprivate.h"

#include <cmath>

TrianglePrivate::TrianglePrivate( double param1, double param2, double param3,
                                  TYPE_INITIALISATION type )
    : TriangleBase( param1, param2, param3, type ) {}

// void TrianglePrivate::Display( ) const { TriangleBase::Display( ); }

// TrianglePrivate::operator std::string( ) const {
//  return TriangleBase::operator std::string( );
//}

double TrianglePrivate::Area( ) const {
  double p = Perimeter( ) / 2;
  return std::sqrt( p * ( p - GetA( ) ) * ( p - GetB( ) ) * ( p - GetC( ) ) );
}

double TrianglePrivate::Perimeter( ) const {
  return GetA( ) + GetB( ) + GetC( );
}

double TrianglePrivate::HeightToA( ) const { return 2 * Area( ) / GetA( ); }

double TrianglePrivate::HeightToB( ) const { return 2 * Area( ) / GetB( ); }

double TrianglePrivate::HeightToC( ) const { return 2 * Area( ) / GetC( ); }
