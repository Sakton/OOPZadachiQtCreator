#ifndef DATEPRIVATE_H
#define DATEPRIVATE_H
#include <string>

#include "basedate.h"

class DatePrivate : BaseDate {
 public:
  DatePrivate( int16_t y, int16_t m, int16_t d );
  DatePrivate( const std::string& dt );

  friend void Display( const DatePrivate& dp );
  friend std::string ToString( const DatePrivate& dp );

  DatePrivate AddDay( int days ) const;
  DatePrivate SubDay( int days ) const;
  int16_t Interval( const DatePrivate& other ) const;
  bool IsVisokosny( ) const;
};

#endif // DATEPRIVATE_H
