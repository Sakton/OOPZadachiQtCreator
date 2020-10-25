#ifndef TIMEPUBLIC_H
#define TIMEPUBLIC_H
#include "basetime.h"

class TimePublic : public BaseTime {
 public:
  explicit TimePublic( int16_t h = 0, int16_t m = 0, int16_t s = 0 );
  explicit TimePublic( const std::string& dt );
  explicit TimePublic( int32_t sec );

  friend TimePublic operator-( const TimePublic& other, int32_t sec );
  friend int32_t operator-( const TimePublic& t1, const TimePublic& t2 );
  friend TimePublic operator+( const TimePublic& other, int32_t sec );
  friend TimePublic operator+( int32_t sec, const TimePublic& other );

  friend bool operator==( const TimePublic& t1, const TimePublic& t2 );
  friend bool operator<( const TimePublic& t1, const TimePublic& t2 );
  friend bool operator>( const TimePublic& t1, const TimePublic& t2 );
};

#endif // TIMEPUBLIC_H
