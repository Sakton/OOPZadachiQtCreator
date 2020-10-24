#ifndef DATEPUBLIC_H
#define DATEPUBLIC_H
#include "basedate.h"

class DatePublic : public BaseDate {
 public:
  DatePublic( int16_t y, int16_t m, int16_t d );
  DatePublic( const std::string& dt );

  DatePublic AddDay( int days ) const;
  DatePublic SubDay( int days ) const;
  int16_t Interval( const DatePublic& other ) const;
  bool IsVisokosny( ) const;
};

#endif // DATEPUBLIC_H
