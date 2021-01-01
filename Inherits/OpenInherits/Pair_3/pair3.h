#ifndef PAIR3_H
#define PAIR3_H
#include <string>

class Pair3
{
public:
    Pair3( int32_t a = 0, int32_t b = 0 );

    void Display( );

    friend bool operator<( const Pair3 & lhs, const Pair3 & rhs );
    friend bool operator==( const Pair3 & lhs, const Pair3 & rhs );

    int32_t getFirst( ) const;
    void setFirst( const int32_t & value );

    int32_t getSecond( ) const;
    void setSecond( const int32_t & value );

    operator std::string( );

private:
    int32_t first;
    int32_t second;
};

#endif // PAIR3_H
