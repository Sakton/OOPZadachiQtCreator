#ifndef BASECOMPLEX_H
#define BASECOMPLEX_H
#include <string>

class BaseComplex
{
 public:
  BaseComplex( double a = 0, double b = 0 );
  explicit operator std::string( ) const;

  friend void Read( BaseComplex& bc );
  friend void Display( const BaseComplex& bc );

  double realn( ) const;
  double mnim( ) const;

  void setRealn( double realn );
  void setMnim( double mnim );

  // protected:
 private:
  double realn_;
  double mnim_;
};

#endif // BASECOMPLEX_H
