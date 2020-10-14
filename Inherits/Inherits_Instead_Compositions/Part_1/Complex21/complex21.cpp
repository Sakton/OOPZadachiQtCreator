#include "complex21.h"

#include <iostream>

Complex::Complex( double a, double b ) : BaseComplex( a, b ) {}

Complex &Complex::operator+=( const Complex &rhs ) {
  setRealn( realn( ) + rhs.realn( ) );
  setMnim( mnim( ) + rhs.mnim( ) );
  return *this;
}

Complex &Complex::operator-=( const Complex &rhs ) {
  setRealn( realn( ) - rhs.realn( ) );
  setMnim( mnim( ) - rhs.mnim( ) );
  return *this;
}

Complex &Complex::operator*=( const Complex &rhs ) {
  setRealn( realn( ) * rhs.realn( ) - mnim( ) * rhs.mnim( ) );
  setMnim( realn( ) * rhs.mnim( ) + mnim( ) * rhs.realn( ) );
  return *this;
}

Complex &Complex::operator/=( const Complex &rhs ) {
  setRealn( ( realn( ) * rhs.realn( ) + mnim( ) * rhs.mnim( ) ) /
            ( rhs.realn( ) * rhs.realn( ) + rhs.mnim( ) * rhs.mnim( ) ) );
  setMnim( ( mnim( ) * rhs.realn( ) - mnim( ) * rhs.mnim( ) ) /
           ( rhs.realn( ) * rhs.realn( ) + rhs.mnim( ) * rhs.mnim( ) ) );
  return *this;
}

// friend Complex operator+( const Complex &lhs, const Complex &rhs );
// friend Complex operator-( const Complex &lhs, const Complex &rhs );
// friend Complex operator*( const Complex &lhs, const Complex &rhs );
// friend Complex operator/( const Complex &lhs, const Complex &rhs );

//************************
Complex1::Complex1( double a, double b ) : BaseComplex( a, b ) {}

Complex1::operator std::string( ) const {
  return BaseComplex::operator std::string( );
}

void Display( const Complex1 &rhs ) {
  std::cout << static_cast< std::string >( rhs ) << std::endl;
}

Complex1 &Complex1::operator+=( const Complex1 &rhs ) {
  setRealn( realn( ) + rhs.realn( ) );
  setMnim( mnim( ) + rhs.mnim( ) );
  return *this;
}

Complex1 &Complex1::operator-=( const Complex1 &rhs ) {
  setRealn( realn( ) - rhs.realn( ) );
  setMnim( mnim( ) - rhs.mnim( ) );
  return *this;
}

Complex1 &Complex1::operator*=( const Complex1 &rhs ) {
  setRealn( realn( ) * rhs.realn( ) - mnim( ) * rhs.mnim( ) );
  setMnim( realn( ) * rhs.mnim( ) + mnim( ) * rhs.realn( ) );
  return *this;
}

Complex1 &Complex1::operator/=( const Complex1 &rhs ) {
  setRealn( ( realn( ) * rhs.realn( ) + mnim( ) * rhs.mnim( ) ) /
            ( rhs.realn( ) * rhs.realn( ) + rhs.mnim( ) * rhs.mnim( ) ) );
  setMnim( ( mnim( ) * rhs.realn( ) - mnim( ) * rhs.mnim( ) ) /
           ( rhs.realn( ) * rhs.realn( ) + rhs.mnim( ) * rhs.mnim( ) ) );
  return *this;
}

// friend Complex1 operator+( const Complex1 &lhs, const Complex1 &rhs );
// friend Complex1 operator-( const Complex1 &lhs, const Complex1 &rhs );
// friend Complex1 operator*( const Complex1 &lhs, const Complex1 &rhs );
// friend Complex1 operator/( const Complex1 &lhs, const Complex1 &rhs );
