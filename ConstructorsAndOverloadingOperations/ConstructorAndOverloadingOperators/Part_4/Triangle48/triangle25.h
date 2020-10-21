#ifndef TRIANGLE25_H
#define TRIANGLE25_H
#include <string>

#include "angle26.h"

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
  Triangle25( double param1, double param2, double param3,
              TYPE_INITIALISATION type );

  void Display( );
  // void Read( );
  std::string ToString( );
  // operator std::string( ) const;

  double GetA( );
  double GetB( );
  double GetC( );
  double GetAngleA( );
  double GetAngleB( );
  double GetAngleC( );

  void SetA( double size );
  void SetB( double size );
  void SetC( double size );
  void SetAngleA( double angle );
  void SetAngleB( double angle );
  void SetAngleC( double angle );

  double Area( );
  double Perimeter( );
  double HeightToA( );
  double HeightToB( );
  double HeightToC( );

  // private:
  static double ToRadian( double angle );
  static double ToAngle( double angle );
  //находим 3 сторону по 2 известным и углу
  static double TheoremaCos( double size1, double size2, double angle );
  //ищем угол противолежащий стороне x_size
  static double AnglePoTheoremeCos( double size1, double size2, double x_size );
  static double TheoremaSinAngle( double size1, double angle1, double x_size );
  static bool Posible( double a, double b, double c );

  TYPE_TRIANGLE GetType( );

 private:
  double sA;
  double sB;
  double sC;
  double angA;
  double angB;
  double angC;
};

#endif // TRIANGLE25_H
