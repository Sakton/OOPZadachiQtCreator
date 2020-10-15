#ifndef TRIANGLEPRIVATE_H
#define TRIANGLEPRIVATE_H
#include "trianglebase.h"

class TrianglePrivate : private TriangleBase {
 public:
  TrianglePrivate( double param1, double param2, double param3,
                   TYPE_INITIALISATION type );
  //делаем доступным интерфейс закрытого унаследованного класса

  using TriangleBase::Display;

  using TriangleBase::SetA;
  using TriangleBase::SetAngleA;
  using TriangleBase::SetAngleB;
  using TriangleBase::SetAngleC;
  using TriangleBase::SetB;
  using TriangleBase::SetC;

  using TriangleBase::GetA;
  using TriangleBase::GetAngleA;
  using TriangleBase::GetAngleB;
  using TriangleBase::GetAngleC;
  using TriangleBase::GetB;
  using TriangleBase::GetC;

  //  explicit operator std::string( ) const;
  //  void Display( ) const;

  double Area( ) const;
  double Perimeter( ) const;
  double HeightToA( ) const;
  double HeightToB( ) const;
  double HeightToC( ) const;
};

#endif // TRIANGLEPRIVATE_H
