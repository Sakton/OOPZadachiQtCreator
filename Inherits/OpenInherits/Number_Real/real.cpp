#include "real.h"

const double PI = 3.14;

Real::Real( double x ) : Number1( x ) {}

double Real::PowPi( int n ) {
  double pi = PI;
  double res = 1.0;
  while ( n > 0 ) {
    if ( n % 2 == 0 ) {
      pi *= pi;
      n /= 2;
    } else {
      res *= pi;
      --n;
    }
  }
  return res;
}

double Real::Sqrt( double n ) {
  double root = X( ) / 2;  //первичное предположение о корне
  double e = 1e-4;
  double root1 = ( ( ( n - 1 ) * root + X( ) / std::pow( root, n - 1 ) ) / n );
  while ( std::fabs( root - root1 ) > e ) {
    root = root1;
    root1 = ( ( ( n - 1 ) * root + X( ) / std::pow( root, n - 1 ) ) / n );
  }
  return root;
}

double Real::Pow( double num, int n ) {
  double res = 1.0;
  while ( n ) {
    if ( !( n % 2 ) ) {
      num *= num;
      n /= 2;
    } else {
      res *= num;
      --n;
    }
  }
  return res;
}
