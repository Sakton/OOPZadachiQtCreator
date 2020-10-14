#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure {
 public:
  Circle( double r = 0 );

  // Figure interface
 public:
  void Init( double r = 0 );
  double Area( ) override;
  double Perimeter( ) override;

 private:
  double r_;
};

#endif // CIRCLE_H
