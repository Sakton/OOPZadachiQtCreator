#include "money24.h"

Money24B::Money24B( int32_t rb, int16_t cp )
    : MoneyBase( rb, cp )
{

}

Money24B & Money24B::operator+=( const Money24B & a )
{
    int64_t rurA = ( getRub( ) < 0 ) ? ( getRub( ) * 100 - getCop( ) ) : ( getRub( ) * 100 + getCop( ) );
    int64_t rurB = ( a.getRub( ) < 0 ) ? ( a.getRub( ) * 100 - a.getCop( ) ) : ( a.getRub( ) * 100 + a.getCop( ) );
    int64_t summ = rurA + rurB;
    setRub( summ / 100 );
    setCop( std::abs( summ % 100 ) );
    return *this;
}

Money24B & Money24B::operator-=( const Money24B & a )
{
    int64_t rurA = ( getRub( ) < 0 ) ? ( getRub( ) * 100 - getCop( ) ) : ( getRub( ) * 100 + getCop( ) );
    int64_t rurB = ( a.getRub( ) < 0 ) ? ( a.getRub( ) * 100 - a.getCop( ) ) : ( a.getRub( ) * 100 + a.getCop( ) );
    int64_t divide = rurA - rurB;
    setRub( divide / 100 );
    setCop( std::abs( divide % 100 ) );
    return *this;
}

//остальные также через методы доступа гет и сет
