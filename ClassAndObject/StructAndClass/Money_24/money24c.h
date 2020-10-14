#ifndef MONEY24C_H
#define MONEY24C_H
#include <string>

struct DataMoney {
    int32_t rub { 0 };
    uint8_t cop { 0 };

    void Init( int32_t rb, int16_t cp );
    void Display( );
    void Read( );
    std::string ToString( );
};

class Money24C {
public:
    void Init( int32_t rb, int16_t cp );
    void Display( );
    void Read( );
    std::string ToString( );

    Money24C Add( const Money24C & b );
    Money24C Sub( const Money24C & b );
    Money24C Mul( double x );
    double Div( const Money24C & b );
    Money24C Div( double x );
    bool Eq( const Money24C & b );
    bool NotEqu( const Money24C & b );
    bool Less( const Money24C & b );
    bool LessOrEq( const Money24C & b );
    bool Greater( const Money24C & b );
    bool GreaterOrEq( const Money24C & b );

private:
    DataMoney data;
};

#endif // MONEY24C_H
