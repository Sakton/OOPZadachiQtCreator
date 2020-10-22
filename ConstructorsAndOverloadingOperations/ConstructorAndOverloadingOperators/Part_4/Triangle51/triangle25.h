#ifndef TRIANGLE25_H
#define TRIANGLE25_H
#include <string>

#include "point27.h"

class Triangle25 {
  enum class TYPE_INITIALISATION { SSS = 0, SUS, USS, USU, UUS };
  // 2 строны и угол между ними, остальное решение треугольников
  Triangle25( double param1, double param2, double param3,
              TYPE_INITIALISATION
                  type );  //написанный уже конструктор, просто его прячем

 public:
  enum class TYPE_TRIANGLE {
    RAVNO_STORONNY,
    RAVNO_BEDRENNY,
    PRYAMO_UGOLNY,
    OTHER

  };

  Triangle25( const Point27& A, const Point27& B, const Point27& C );

  void Display( ) const;
  // void Read( );
  std::string ToString( ) const;
  // operator std::string( ) const;

  double GetA( ) const;
  double GetB( ) const;
  double GetC( ) const;

  double GetAngleA( ) const;
  double GetAngleB( ) const;
  double GetAngleC( ) const;

  double Area( ) const;
  double Perimeter( ) const;
  double HeightToA( ) const;
  double HeightToB( ) const;
  double HeightToC( ) const;

  Point27 A( ) const;
  void setA( const Point27& A );
  Point27 B( ) const;
  void setB( const Point27& B );
  Point27 C( ) const;
  void setC( const Point27& C );

 private:
  static double ToRadian( double angle );  //преобразования величин углов
  static double ToAngle( double radian );  // углы - радианы
  //находим 3 сторону по 2 известным и углу
  static double TheoremaCos( double size1, double size2, double angle );
  //ищем угол противолежащий стороне x_size
  static double AnglePoTheoremeCos( double size1, double size2, double x_size );
  static double TheoremaSinAngle( double size1, double angle1, double x_size );
  static bool Posible( double a, double b, double c );

  TYPE_TRIANGLE GetType( );

 private:
  Point27 A_;
  Point27 B_;
  Point27 C_;
};

#endif // TRIANGLE25_H
