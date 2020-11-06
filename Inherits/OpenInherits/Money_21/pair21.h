#ifndef PAIR21_H
#define PAIR21_H
#include <string>

class Pair21
{
 public:
  Pair21( int a = 0, int b = 0 );

  std::string toString( );
  void display( );

  Pair21& operator*=( int n );
  Pair21& operator+=( const Pair21& p );

  friend Pair21 operator*( int n, const Pair21& p );
  friend Pair21 operator*( const Pair21& p, int n );
  friend Pair21 operator+( const Pair21& p1, const Pair21& p2 );

  int getA( ) const;
  void setA( int a );

  int getB( ) const;
  void setB( int b );

 private:
  int a_;
  int b_;
};

#endif // PAIR21_H
