#ifndef TIMEPRIVATE_H
#define TIMEPRIVATE_H
#include <string>

#include "basetime.h"

class TimePrivate : BaseTime {
 public:
  explicit TimePrivate( int16_t h = 0, int16_t m = 0, int16_t s = 0 );
  explicit TimePrivate( const std::string& dt );
  explicit TimePrivate( int32_t sec );

  // opening private interfase BaseTime
  using BaseTime::ToMinut;
  using BaseTime::ToSecond;

  friend std::string ToString( const TimePrivate& tp );
  friend void Display( const TimePrivate& tp );

  friend TimePrivate operator-( const TimePrivate& other, int32_t sec );
  friend int32_t operator-( const TimePrivate& t1, const TimePrivate& t2 );
  friend TimePrivate operator+( const TimePrivate& other, int32_t sec );
  friend TimePrivate operator+( int32_t sec, const TimePrivate& other );

  friend bool operator==( const TimePrivate& t1, const TimePrivate& t2 );
  friend bool operator<( const TimePrivate& t1, const TimePrivate& t2 );
  friend bool operator>( const TimePrivate& t1, const TimePrivate& t2 );
};

#endif // TIMEPRIVATE_H
