#ifndef COMPLEX_H
#define COMPLEX_H

#include "basecomplex.h"

class Complex : public BaseComplex {
 public:
  Complex( double a = 0.0, double b = 0.0 );

  Complex& operator+=( const Complex& rhs );
  Complex& operator-=( const Complex& rhs );
  Complex& operator*=( const Complex& rhs );
  Complex& operator/=( const Complex& rhs );

  friend Complex operator+( const Complex& lhs, const Complex& rhs );
  friend Complex operator-( const Complex& lhs, const Complex& rhs );
  friend Complex operator*( const Complex& lhs, const Complex& rhs );
  friend Complex operator/( const Complex& lhs, const Complex& rhs );
};

class Complex1 : BaseComplex {
 public:
  Complex1( double a = 0.0, double b = 0.0 );
  explicit operator std::string( ) const;
  friend void Display( const Complex1& rhs );
  Complex1& operator+=( const Complex1& rhs );
  Complex1& operator-=( const Complex1& rhs );
  Complex1& operator*=( const Complex1& rhs );
  Complex1& operator/=( const Complex1& rhs );

  friend Complex1 operator+( const Complex1& lhs, const Complex1& rhs );
  friend Complex1 operator-( const Complex1& lhs, const Complex1& rhs );
  friend Complex1 operator*( const Complex1& lhs, const Complex1& rhs );
  friend Complex1 operator/( const Complex1& lhs, const Complex1& rhs );
};

#endif  // COMPLEX_H
