#ifndef LONGLONG38B_H
#define LONGLONG38B_H
#include <string>

class LongLong38B {
public:
    void Init( int64_t bits_64_num = 0 );
    void Init( const LongLong38B & l );
    //Read();
    void Display( ) const;
    std::string ToString( ) const;

    LongLong38B & AddSelf( const LongLong38B & b );
    LongLong38B & AddSelf( int32_t b );
    LongLong38B & SubSelf( const LongLong38B & b );
    LongLong38B & SubSelf( int32_t b );
    LongLong38B & MidSelf( const LongLong38B & b );
    LongLong38B & MidSelf( int32_t b );
    LongLong38B & DivSelf( const LongLong38B & b );
    LongLong38B & DivSelf( int32_t b );

    LongLong38B Add( const LongLong38B & b ) const;
    LongLong38B Add( int32_t b ) const;
    LongLong38B Sub( const LongLong38B & b ) const;
    LongLong38B Sub( int32_t b ) const;
    LongLong38B Mid( const LongLong38B & b ) const;
    LongLong38B Mid( int32_t b ) const;
    LongLong38B Div( const LongLong38B & b ) const;
    LongLong38B Div( int32_t b ) const;

    int64_t ToInt64( ) const;

    bool Eq( const LongLong38B & b ) const;
    bool Less( const LongLong38B & b ) const;
    bool Great( const LongLong38B & b ) const;
    bool NotEq( const LongLong38B & b ) const;
    bool LessEq( const LongLong38B & b ) const;
    bool GreatEq( const LongLong38B & b ) const;

private:
    const uint32_t MASK_ = 0xffffffff;	      //32 битная маска
    int32_t senior_;
    uint32_t junior_;
};

#endif // LONGLONG38B_H
