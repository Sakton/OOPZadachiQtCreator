#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H
#include "figure.h"

class Trapezium : public Figure {
 public:
  Trapezium( double a = 0, double b = 0, double c = 0, double d = 0,
             double h = 0 );

  // Figure interface
 public:
  double Area( ) override;
  double Perimeter( ) override;

 private:
  double a_;
  double b_;
  double c_;
  double d_;
  double h_;
};

#endif // TRAPEZIUM_H
