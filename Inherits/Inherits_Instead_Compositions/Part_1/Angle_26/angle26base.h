#ifndef ANGLE26BASE_H
#define ANGLE26BASE_H
#include <string>

class Angle26Base
{
 public:
  constexpr static double PI = 3.14159265358979323846;
  constexpr static const int ANG_PI_2 = 180;

  explicit Angle26Base( int16_t g = 0, int16_t m = 0 );
  explicit Angle26Base( double angl );

  friend void Display( const Angle26Base& ang );
  friend std::string ToString( const Angle26Base& ang );

  double ToRadian( ) const;
  Angle26Base Normalise( ) const;
  void Normalise( );
  double Sinus( ) const;
  double Angle( ) const;

  int16_t getGrad( ) const;
  void setGrad( const int16_t& value );

  int16_t getMin( ) const;
  void setMin( const int16_t& value );

 private:
  int16_t grad;
  int16_t min;
};

#endif // ANGLE26BASE_H
