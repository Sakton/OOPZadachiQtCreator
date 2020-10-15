#ifndef PAIR_H
#define PAIR_H
#include <iostream>
#include <string>

class Pair
{
 public:
  Pair( int f = 0, int s = 0 );

  Pair &operator-=( const Pair &oth );
  friend Pair operator-( const Pair &p1, const Pair &p2 );
  friend bool operator==( const Pair &p1, const Pair &p2 );

  explicit operator std::string( ) const;
  void Display( ) const;

  int first( ) const;
  void setFirst( int first );
  int second( ) const;
  void setSecond( int second );

 private:
  int first_;
  int second_;
};

#endif // PAIR_H
