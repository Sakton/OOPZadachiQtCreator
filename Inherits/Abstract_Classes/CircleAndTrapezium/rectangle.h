#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure {
 public:
  Rectangle( double a = 0, double b = 0 );

  // Figure interface
 public:
  double Area( ) override;
  double Perimeter( ) override;

 private:
  double a_;
  double b_;
};

#endif  // RECTANGLE_H
