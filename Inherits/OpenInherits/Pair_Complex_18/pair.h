#ifndef PAIR_H
#define PAIR_H
#include <string>

class Pair
{
 public:
  Pair( double f = 0, double s = 0 );

  Pair& operator+=( const Pair& pr );
  double MultPole( ) const;

  friend Pair operator+( const Pair& pr1, const Pair& pr2 );

  double first( ) const;
  void setFirst( double first );
  double second( ) const;
  void setSecond( double second );

  explicit operator std::string( ) const;
  void Display( ) const;

 private:
  double first_;
  double second_;
};

#endif // PAIR_H
