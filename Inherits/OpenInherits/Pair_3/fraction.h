#ifndef FRACTION_H
#define FRACTION_H
#include "pair3.h"

class Fraction : public Pair3 {
 public:
  Fraction( int32_t a = 0, int32_t b = 0 );
  friend bool operator<( const Fraction& a, const Fraction& b );
  friend bool operator<=( const Fraction& a, const Fraction& b );
  friend bool operator>( const Fraction& a, const Fraction& b );
  friend bool operator>=( const Fraction& a, const Fraction& b );
  friend bool operator==( const Fraction& a, const Fraction& b );
  friend bool operator!=( const Fraction& a, const Fraction& b );

  //что имеется ввиду: с своими полями или те что есть у
  //базового класса???
  // private:
  //  double cel;
  //  double drob;
};

#endif // FRACTION_H
