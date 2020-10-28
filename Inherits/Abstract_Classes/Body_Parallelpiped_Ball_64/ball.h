#ifndef BALL_H
#define BALL_H
#include "body.h"

class Ball : public Body {
 public:
  Ball( double r = 0 );

  // Body interface
 public:
  double Area( ) const override;
  double Volume( ) const override;

 private:
  double r_;
};

#endif // BALL_H
