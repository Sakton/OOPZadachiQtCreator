#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "trianglebase.h"

class Triangle : public TriangleBase {
 public:
  Triangle( double param1, double param2, double param3,
            TYPE_INITIALISATION type );

  double Area( ) const;
  double Perimeter( ) const;
  double HeightToA( ) const;
  double HeightToB( ) const;
  double HeightToC( ) const;
};

#endif // TRIANGLE_H
