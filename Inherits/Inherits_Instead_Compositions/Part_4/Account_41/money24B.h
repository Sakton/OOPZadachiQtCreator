#ifndef MONEY24B_H
#define MONEY24B_H
#include <string>

/*
TODO Money24 - добавлены методы получения значений полей
исправлена константность методов Display, ToString
*/

class Money24B {
public:
    void Init( int32_t rb, int16_t cp );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;

    Money24B Add( const Money24B & b );
    Money24B Sub( const Money24B & b );
    Money24B Mul( double x );
    double Div( const Money24B & b );
    Money24B Div( double x );
    bool Eq( const Money24B & b );
    bool NotEqu( const Money24B & b );
    bool Less( const Money24B & b );
    bool LessOrEq( const Money24B & b );
    bool Greater( const Money24B & b );
    bool GreaterOrEq( const Money24B & b );

    int32_t GetRub( ) const;
    uint8_t GetCop( ) const;

    void setRub( const int32_t & value );
    void setCop( const uint8_t & value );

private:
    int32_t rub { 0 };
    uint8_t cop { 0 };
};

#endif	      // MONEY24B_H
