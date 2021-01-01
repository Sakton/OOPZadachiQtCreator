#ifndef PAIR10_H
#define PAIR10_H
#include <string>

class Pair10
{
 public:
  Pair10( double f = 0, double s = 0 );
  explicit operator std::string( ) const;
  double Mult( ) const;
  void Display( );

  double first( ) const;
  void setFirst( double first );
  double second( ) const;
  void setSecond( double second );

 private:
  double first_;
  double second_;
};

#endif // PAIR10_H
