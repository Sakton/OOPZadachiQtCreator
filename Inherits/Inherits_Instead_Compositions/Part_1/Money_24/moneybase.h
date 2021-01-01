#ifndef MONEYBASE_H
#define MONEYBASE_H
#include <string>

class MoneyBase
{
public:
    MoneyBase( int32_t rb = 0, int16_t cp = 0 );

    int32_t getRub( ) const;
    void setRub( const int32_t & value );
    uint8_t getCop( ) const;
    void setCop( const uint8_t & value );

    void Display( );
    operator std::string( ) const;

private:
    int32_t rub { 0 };
    uint16_t cop { 0 };
};

#endif // MONEYBASE_H
