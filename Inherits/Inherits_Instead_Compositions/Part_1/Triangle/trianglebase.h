#ifndef TRIANGLEBASE_H
#define TRIANGLEBASE_H
#include <string>

class TriangleBase {
 public:
  enum class TYPE_TRIANGLE {
    RAVNO_STORONNY,
    RAVNO_BEDRENNY,
    PRYAMO_UGOLNY,
    OTHER
  };

  enum class TYPE_INITIALISATION { SSS = 0, SUS, USS, USU, UUS };

  // 2 строны и угол между ними, остальное решение треугольников
  TriangleBase( double param1, double param2, double param3,
                TYPE_INITIALISATION type );

  explicit operator std::string( ) const;

  void Display( ) const;

  double GetA( ) const;
  double GetB( ) const;
  double GetC( ) const;
  double GetAngleA( ) const;
  double GetAngleB( ) const;
  double GetAngleC( ) const;

  void SetA( double size );
  void SetB( double size );
  void SetC( double size );
  void SetAngleA( double angle );
  void SetAngleB( double angle );
  void SetAngleC( double angle );

  // statiks
  static double ToRadian( double angle );
  static double ToAngle( double angle );
  //находим 3 сторону по 2 известным и углу
  static double TheoremaCos( double size1, double size2, double angle );
  //ищем угол противолежащий стороне x_size
  static double AnglePoTheoremeCos( double size1, double size2, double x_size );
  static double TheoremaSinAngle( double size1, double angle1, double x_size );
  static bool Posible( double a, double b, double c );

  friend TYPE_TRIANGLE GetType( const TriangleBase& tr );

 private:
  double sA;
  double sB;
  double sC;
  double angA;
  double angB;
  double angC;
};

#endif  // TRIANGLEBASE_H
