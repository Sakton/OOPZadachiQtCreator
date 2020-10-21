#ifndef FRACTION46PRIVATE_H
#define FRACTION46PRIVATE_H
#include "longlong38b.h"

class Fraction46private
{
 public:
  explicit Fraction46private( const LongLong38B& w = LongLong38B( ),
                              double f = 0 );
  void Display( ) const;
  explicit operator std::string( ) const;

  Fraction46private& operator+=( const Fraction46private& b );
  Fraction46private& operator-=( const Fraction46private& b );
  Fraction46private& operator*=( const Fraction46private& b );
  Fraction46private& operator/=( const Fraction46private& b );

  friend Fraction46private operator+( const Fraction46private& a,
                                      const Fraction46private& b );
  friend Fraction46private operator-( const Fraction46private& a,
                                      const Fraction46private& b );
  friend Fraction46private operator*( const Fraction46private& a,
                                      const Fraction46private& b );
  friend Fraction46private operator/( const Fraction46private& a,
                                      const Fraction46private& b );

  friend bool operator<( const Fraction46private& a,
                         const Fraction46private& b );
  friend bool operator<=( const Fraction46private& a,
                          const Fraction46private& b );
  friend bool operator>( const Fraction46private& a,
                         const Fraction46private& b );
  friend bool operator>=( const Fraction46private& a,
                          const Fraction46private& b );
  friend bool operator==( const Fraction46private& a,
                          const Fraction46private& b );
  friend bool operator!=( const Fraction46private& a,
                          const Fraction46private& b );

  LongLong38B Whole( );
  int16_t Fractional( );
  bool GetNegative( );

 private:
  Fraction46private AddModul( const Fraction46private& a,
                              const Fraction46private& b );
  Fraction46private SubModul( const Fraction46private& a,
                              const Fraction46private& b );
  Fraction46private MulModul( const Fraction46private& a,
                              const Fraction46private& b );
  Fraction46private Modul( const Fraction46private& a );

  friend bool LessMod( const Fraction46private& a, const Fraction46private& b );
  friend bool EqModul( const Fraction46private& a, const Fraction46private& b );

 private:
  LongLong38B whole_;
  double fractional_;
  bool negative;
};

#endif // FRACTION46PRIVATE_H
