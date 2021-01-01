#ifndef DATE_H
#define DATE_H
#include <iostream>

#include "triad.h"

//считаем что да та в кольце вычетов 31
//месяц в кольце 12

class Date : public Triad {
 public:
  Date( int day = 1, int mon = 1, int year = 1900 );
  int &firstNext( );
  int &secondNext( );
  int &thirdNext( );
};

std::ostream &operator<<( std::ostream &out, const Date &dt );

#endif // DATE_H
