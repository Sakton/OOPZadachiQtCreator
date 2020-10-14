#ifndef TRIAD_H
#define TRIAD_H
#include <iostream>

class Triad
{
 public:
  Triad( int f = 0, int s = 0, int t = 0 );

  int FirstNext( );
  int SecondNext( );
  int ThirdNext( );

  int First( ) const;
  int Second( ) const;
  int Third( ) const;

  std::ostream& show( std::ostream& out );
  operator std::string( );

  void setFirst( int first );
  void setSecond( int second );
  void setThird( int third );

 private:
  int first_;
  int second_;
  int third_;
};

#endif // TRIAD_H
