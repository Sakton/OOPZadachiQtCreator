#ifndef TRIAD_H
#define TRIAD_H
#include <string>

class Triad
{
 public:
  explicit Triad( int f = 0, int s = 0, int t = 0 );

  Triad &operator+=( int x );
  Triad &operator*=( int x );

  operator std::string( ) const;
  void Display( ) const;

  friend Triad operator+( const Triad &t1, int x );
  friend Triad operator+( int x, const Triad &t1 );
  friend Triad operator*( const Triad &t1, int x );
  friend Triad operator*( int x, const Triad &t1 );
  bool friend operator==( const Triad &t1, const Triad &t2 );

  int first( ) const;
  void setFirst( int first );
  int second( ) const;
  void setSecond( int second );
  int third( ) const;
  void setThird( int third );

 private:
  int first_;
  int second_;
  int third_;
};

#endif // TRIAD_H
