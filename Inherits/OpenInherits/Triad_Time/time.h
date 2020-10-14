#ifndef TIME_H
#define TIME_H
#include <iostream>

#include "triad.h"

class Time : public Triad {
 public:
  Time( int h, int m, int s );
  int HourNext( );
  int MinutNext( );
  int SecundNext( );
  void AddSecund( int n );
  void AddMinut( int n );

  std::ostream& show( std::ostream& out );

  int GetHour( );
  int GetMinut( );
  int GetSecund( );
};

#endif // TIME_H
