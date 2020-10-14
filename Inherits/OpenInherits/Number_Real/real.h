#ifndef REAL_H
#define REAL_H
#include "number.h"

class Real : public Number1 {
 public:
  Real( double x );
  double PowPi( int n );
  double Sqrt( double n );

  // private:
  static double Pow( double num, int n );
};

#endif // REAL_H
