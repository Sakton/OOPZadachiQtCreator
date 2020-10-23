#ifndef FRACTION35_H
#define FRACTION35_H
#include <string>

#include "longlong38b.h"

/*
int16_t - 65536 - макс число для ushort
но нам нужен переход через 1, тогда максимальное число для представления 9999,
любой дополнительный символ приведет к переполнению
При этом 9999 * 2 = 19998 - находится в диапазоне.
Поэтому максимальная точность числа - 4 порядка
*/

class Fraction35B {
 public:
  explicit Fraction35B( const LongLong38B& w = LongLong38B( ), double f = 0 );
  void Display( ) const;
  explicit operator std::string( ) const;

  Fraction35B& operator+=( const Fraction35B& b );
  Fraction35B& operator-=( const Fraction35B& b );
  Fraction35B& operator*=( const Fraction35B& b );
  Fraction35B& operator/=( const Fraction35B& b );

  friend Fraction35B operator+( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator-( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator*( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator/( const Fraction35B& a, const Fraction35B& b );

  friend bool operator<( const Fraction35B& a, const Fraction35B& b );
  friend bool operator<=( const Fraction35B& a, const Fraction35B& b );
  friend bool operator>( const Fraction35B& a, const Fraction35B& b );
  friend bool operator>=( const Fraction35B& a, const Fraction35B& b );
  friend bool operator==( const Fraction35B& a, const Fraction35B& b );
  friend bool operator!=( const Fraction35B& a, const Fraction35B& b );

  LongLong38B Whole( );
  int16_t Fractional( );
  bool GetNegative( );

 private:
  Fraction35B AddModul( const Fraction35B& a, const Fraction35B& b );
  Fraction35B SubModul( const Fraction35B& a, const Fraction35B& b );
  Fraction35B MulModul( const Fraction35B& a, const Fraction35B& b );
  Fraction35B Modul( const Fraction35B& a );

  friend bool LessMod( const Fraction35B& a, const Fraction35B& b );
  friend bool EqModul( const Fraction35B& a, const Fraction35B& b );

 private:
  LongLong38B whole_;
  double fractional_;
  bool negative;
};

#endif // FRACTION35_H
