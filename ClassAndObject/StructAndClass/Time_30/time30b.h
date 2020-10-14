#ifndef TIME30B_H
#define TIME30B_H
#include <string>

//В ПРЕДЕЛАХ 1 СУТОК

class Time30B
{
public:
    void Init( int16_t h, int16_t m, int16_t s );
    void Init( const std::string & dt );
    void Init( int32_t sec );
    void Init( const Time30B & dt );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    int32_t DeltaMoment( const Time30B & other ) const;
    Time30B AddSec( int32_t sec ) const;
    Time30B SubSec( int32_t sec ) const;

    bool Eq( const Time30B & other );
    bool Less( const Time30B & other );
    bool Great( const Time30B & other );

    int32_t ToSecond( ) const;
    int32_t ToMinut( ) const;

    Time30B ToTime( int32_t sec ) const;

private:
    static constexpr int SEC_IN_DAY = 86400;
    int16_t h_;
    int16_t m_;
    int16_t s_;
};

#endif // TIME30B_H
