#ifndef COMPLEX21_H
#define COMPLEX21_H
#include <string>

class PairCmplx {
 public:
  PairCmplx( double a = 0, double b = 0 );
  operator std::string( ) const;
  // /*friend */ void Display( /*const PairCmplx& pc*/ ) const;
  friend void Display( const PairCmplx& pc );

  double a( ) const;
  void setA( double a );
  double b( ) const;
  void setB( double b );

 private:
  double a_;
  double b_;
};

class Complex21 {
 public:
  Complex21( double a = 0, double b = 0 );

  void Display( ) const;
  operator std::string( );

  Complex21& operator+=( const Complex21& oth );
  Complex21& operator-=( const Complex21& oth );
  Complex21& operator*=( const Complex21& oth );
  Complex21& operator/=( const Complex21& oth );
  Complex21& operator-( );

  friend Complex21 operator+( const Complex21& lhs, const Complex21& rhs );
  friend Complex21 operator-( const Complex21& lhs, const Complex21& rhs );
  friend Complex21 operator/( const Complex21& lhs, const Complex21& rhs );
  friend Complex21 operator*( const Complex21& lhs, const Complex21& rhs );

 private:
  PairCmplx data_;
};

#endif  // COMPLEX21_H
