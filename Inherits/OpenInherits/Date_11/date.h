#ifndef DATE_H
#define DATE_H
#include "triad.h"

class Date : public Triad {
public:
    Date( int day = 0, int mon = 0, int year = 0 );

    friend bool operator<( const Date & d_a, const Date & d_b );
    friend bool operator<=( const Date & d_a, const Date & d_b );
    friend bool operator>=( const Date & d_a, const Date & d_b );
    friend bool operator>( const Date & d_a, const Date & d_b );
    friend bool operator==( const Date & d_a, const Date & d_b );
    friend bool operator!=( const Date & d_a, const Date & d_b );
};

#endif // DATE_H
