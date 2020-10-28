#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "body.h"

class Parallelepiped : public Body {
 public:
  Parallelepiped( double a = 0, double b = 0, double h = 0 );

  // Body interface
 public:
  double Area( ) const override;
  double Volume( ) const override;

 private:
  double a_;
  double b_;
  double h_;
};

#endif // PARALLELEPIPED_H
