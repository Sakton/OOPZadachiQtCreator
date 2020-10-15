#ifndef ANGLE26_H
#define ANGLE26_H
#include <string>

class Angle26 {
 public:
  explicit Angle26( int16_t g = 0, int16_t m = 0 );
  explicit Angle26( double angl );

  void Read( );
  void Display( ) const;
  std::string ToString( ) const;

  double ToRadian( ) const;
  Angle26 Normalise( ) const;
  void Normalise( );
  double Sinus( ) const;
  double Angle( ) const;

  friend Angle26 operator+( const Angle26& an1, const Angle26& an2 );
  friend Angle26 operator-( const Angle26& an1, const Angle26& an2 );

  friend bool operator<( const Angle26& an1, const Angle26& an2 );
  friend bool operator<=( const Angle26& an1, const Angle26& an2 );
  friend bool operator>( const Angle26& an1, const Angle26& an2 );
  friend bool operator>=( const Angle26& an1, const Angle26& an2 );
  friend bool operator==( const Angle26& an1, const Angle26& an2 );
  friend bool operator!=( const Angle26& an1, const Angle26& an2 );

  int16_t getGrad( ) const;
  void setGrad( const int16_t& value );
  int16_t getMin( ) const;
  void setMin( const int16_t& value );

 private:
  int16_t grad;
  int16_t min;
};

#endif  // ANGLE26_H
