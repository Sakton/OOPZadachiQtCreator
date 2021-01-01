#ifndef TRIAD_H
#define TRIAD_H
#include <iostream>

class Triad
{
 public:
  Triad( int f = 0, int s = 0, int t = 0 );

  int &firstNext( );
  int &secondNext( );
  int &thirdNext( );
  std::ostream &Show( std::ostream &out ) const;
  operator std::string( ) const;

 private:
  int first;
  int second;
  int third;
};

#endif // TRIAD_H
