#ifndef RATIONAL28_H
#define RATIONAL28_H
#include <string>

class Rational28 {
 public:
  Rational28( int32_t x = 1, int16_t y = 1 );

  operator std::string( ) const;
  Rational28& operator+=( const Rational28& rt );
  Rational28& operator-=( const Rational28& rt );
  Rational28& operator*=( const Rational28& rt );
  Rational28& operator/=( const Rational28& rt );

  friend void Display( const Rational28& rt );

  friend Rational28 operator+( const Rational28& rt1, const Rational28& rt2 );
  friend Rational28 operator-( const Rational28& rt1, const Rational28& rt2 );
  friend Rational28 operator*( const Rational28& rt1, const Rational28& rt2 );
  friend Rational28 operator/( const Rational28& rt1, const Rational28& rt2 );

  friend bool operator<( const Rational28& rt1, const Rational28& rt2 );
  friend bool operator<=( const Rational28& rt1, const Rational28& rt2 );
  friend bool operator>( const Rational28& rt1, const Rational28& rt2 );
  friend bool operator>=( const Rational28& rt1, const Rational28& rt2 );
  friend bool operator==( const Rational28& rt1, const Rational28& rt2 );
  friend bool operator!=( const Rational28& rt1, const Rational28& rt2 );

  //  Rational28 Add( const Rational28& b ) const;
  //  Rational28 Sub( const Rational28& b ) const;
  //  Rational28 Mul( const Rational28& b ) const;
  //  Rational28 Div( const Rational28& b ) const;

  //  bool Eq( const Rational28& b ) const;
  //  bool Great( const Rational28& b ) const;
  //  bool Less( const Rational28& b ) const;

 private:
  friend void reduce( Rational28& rt );

 public:
  int32_t chis_;
  int32_t znam_;
};

#endif // RATIONAL28_H
