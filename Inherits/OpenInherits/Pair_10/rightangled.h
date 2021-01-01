#ifndef RIGHTANGLED_H
#define RIGHTANGLED_H
#include "pair10.h"

class RightAngled : public Pair10 {
 public:
  RightAngled( double c1, double c2 );
  explicit operator std::string( );
  void Display( );
  double Hypotenuse( );
  double Area( );
};

#endif // RIGHTANGLED_H
