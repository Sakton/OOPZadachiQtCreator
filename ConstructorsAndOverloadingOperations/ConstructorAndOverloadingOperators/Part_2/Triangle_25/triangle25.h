#ifndef TRIANGLE25_H
#define TRIANGLE25_H
#include <string>

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

  friend void Display( const Triangle25& tr );
  // void Read( );
  friend std::string ToString( const Triangle25& tr );

  friend double GetA( const Triangle25& tr );
  friend double GetB( const Triangle25& tr );
  friend double GetC( const Triangle25& tr );
  friend double GetAngleA( const Triangle25& tr );
  friend double GetAngleB( const Triangle25& tr );
  friend double GetAngleC( const Triangle25& tr );

  friend void SetA( Triangle25& tr, double size );
  friend void SetB( Triangle25& tr, double size );
  friend void SetC( Triangle25& tr, double size );
  friend void SetAngleA( Triangle25& tr, double angle );
  friend void SetAngleB( Triangle25& tr, double angle );
  friend void SetAngleC( Triangle25& tr, double angle );

  friend double Area( const Triangle25& tr );
  friend double Perimeter( const Triangle25& tr );
  friend double HeightToA( const Triangle25& tr );
  friend double HeightToB( const Triangle25& tr );
  friend double HeightToC( const Triangle25& tr );

  // private:
  static double ToRadian( double angle );
  static double ToAngle( double angle );
  //находим 3 сторону по 2 известным и углу
  static double TheoremaCos( double size1, double size2, double angle );
  //ищем угол противолежащий стороне x_size
  static double AnglePoTheoremeCos( double size1, double size2, double x_size );
  static double TheoremaSinAngle( double size1, double angle1, double x_size );
  static bool Posible( double a, double b, double c );

  friend TYPE_TRIANGLE GetType( const Triangle25& tr );

 private:
  double sA;
  double sB;
  double sC;
  double angA;
  double angB;
  double angC;
};

#endif // TRIANGLE25_H
