#ifndef PAIR5_H
#define PAIR5_H
#include <string>

class Pair5
{
public:
    Pair5( int32_t a = 0, int32_t b = 0 );
    operator std::string( ) const;

    int32_t Mult( );
    void Display( ) const;

    int32_t first( ) const;
    void setFirst( const int32_t & first );
    int32_t second( ) const;
    void setSecond( const int32_t & second );

private:
    int32_t first_;
    int32_t second_;
};

#endif // PAIR5_H
