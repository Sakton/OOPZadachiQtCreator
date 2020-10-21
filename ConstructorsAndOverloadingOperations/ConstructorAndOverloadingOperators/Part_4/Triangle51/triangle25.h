#ifndef TRIANGLE25_H
#define TRIANGLE25_H
#include <string>

#include "angle26.h"
#include "point27.h"

// TODO HERE

class Triangle25 {
 public:
  enum class TYPE_TRIANGLE {
    RAVNO_STORONNY,
    RAVNO_BEDRENNY,
    PRYAMO_UGOLNY,
    OTHER
  };

  enum class TYPE_INITIALISATION { SSS = 0, SUS, USS, USU, UUS };

  // 2 строны и угол между ними, остальное решение треугольников
  //  Triangle25( double param1, double param2, double param3,
  //              TYPE_INITIALISATION type );

  Triangle25( const Point27& A, const Point27& B, const Point27& C );

  void Display( ) const;
  // void Read( );
  std::string ToString( ) const;
  // operator std::string( ) const;

  double GetA( ) const;
  double GetB( ) const;
  double GetC( ) const;
  Angle26 GetAngleA( ) const;
  Angle26 GetAngleB( ) const;
  Angle26 GetAngleC( ) const;

  void SetA( double size );
  void SetB( double size );
  void SetC( double size );
  void SetAngleA( Angle26 angle );
  void SetAngleB( Angle26 angle );
  void SetAngleC( Angle26 angle );

  double Area( ) const;
  double Perimeter( ) const;
  double HeightToA( ) const;
  double HeightToB( ) const;
  double HeightToC( ) const;

  // private:
  static double ToRadian( double angle );  //преобразования величин углов
  static double ToAngle( double radian );  // углы - радианы
  //находим 3 сторону по 2 известным и углу
  static double TheoremaCos( double size1, double size2, Angle26 angle );
  //ищем угол противолежащий стороне x_size
  static double AnglePoTheoremeCos( double size1, double size2, double x_size );
  static double TheoremaSinAngle( double size1, double angle1, double x_size );
  static bool Posible( double a, double b, double c );

  TYPE_TRIANGLE GetType( );

 private:
  Point27 A_;
  Point27 B_;
  Point27 C_;

  //  Angle26 angA;
  //  Angle26 angB;
  //  Angle26 angC;
};

#endif // TRIANGLE25_H
