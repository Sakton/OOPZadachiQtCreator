#ifndef MONEY24_H
#define MONEY24_H
#include "moneybase.h"
#include <string>

class Money24B : public MoneyBase {
public:
    Money24B( int32_t rb = 0, int16_t cp = 0 );

    Money24B & operator+=( const Money24B & a );
    Money24B & operator-=( const Money24B & a );
    Money24B & operator*=( const Money24B & a );
    Money24B & operator/=( const Money24B & a );
};

#endif // MONEY24_H
