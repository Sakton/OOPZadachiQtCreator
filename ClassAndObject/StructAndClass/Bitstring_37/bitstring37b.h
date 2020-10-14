#ifndef BITSTRING37B_H
#define BITSTRING37B_H
#include <cstdint>
#include <string>

class Bitstring37B
{
public:
    void Init( uint32_t h = 0, uint32_t t = 0 );
    void Display( );
    std::string ToString( );
    //void Read( );

    Bitstring37B And( const Bitstring37B & other );
    Bitstring37B Or( const Bitstring37B & other );
    Bitstring37B Xor( const Bitstring37B & other );
    Bitstring37B Not( );

    Bitstring37B ShiftLeft( int n );
    Bitstring37B ShiftRight( int n );

    //private:
    uint32_t head_;
    uint32_t tail_;
};

#endif // BITSTRING37B_H
