#ifndef FUZZYNUMBER31_H
#define FUZZYNUMBER31_H
#include <string>

class FuzzyNumber31 {
 public:
  FuzzyNumber31( double e1, double x, double e2 );
  // void Read(  );
  friend void Display( const FuzzyNumber31& fn );
  operator std::string( ) const;
  FuzzyNumber31& operator+=( const FuzzyNumber31& fn );
  FuzzyNumber31& operator-=( const FuzzyNumber31& fn );
  FuzzyNumber31& operator*=( const FuzzyNumber31& fn );
  FuzzyNumber31& operator/=( const FuzzyNumber31& fn );

  friend FuzzyNumber31 operator+( const FuzzyNumber31& fn1,
                                  const FuzzyNumber31& fn2 );
  friend FuzzyNumber31 operator-( const FuzzyNumber31& fn1,
                                  const FuzzyNumber31& fn2 );
  friend FuzzyNumber31 operator*( const FuzzyNumber31& fn1,
                                  const FuzzyNumber31& fn2 );
  friend FuzzyNumber31 operator/( const FuzzyNumber31& fn1,
                                  const FuzzyNumber31& fn2 );

 public:
  double e1_;
  double x_;
  double e2_;
};

#endif // FUZZYNUMBER31_H
