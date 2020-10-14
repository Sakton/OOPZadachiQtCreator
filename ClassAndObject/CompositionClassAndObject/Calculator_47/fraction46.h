#ifndef FRACTION46_H
#define FRACTION46_H
#include "longlong38b.h"
#include <string>

class Fraction46 {
public:
    void Init( int64_t w = 0, double f = 0 );
    void Init( const Fraction46 & fr );
    void Display( ) const;
    std::string ToString( ) const;
    //void Read(  );

    //    Fraction46 & AddSelf( const Fraction46 & b );
    //    Fraction46 & SubSelf( const Fraction46 & b );
    //    Fraction46 & MulSelf( const Fraction46 & b );
    //    Fraction46 & DivSelf( const Fraction46 & b );

    Fraction46 Add( const Fraction46 & b ) const;
    Fraction46 Sub( const Fraction46 & b ) const;
    Fraction46 Mul( const Fraction46 & b ) const;
    Fraction46 Div( const Fraction46 & b ) const;

    //    bool Less( const Fraction46 & b ) const;

    int64_t Whole( ) const;
    int16_t Fractional( ) const;

    //private:
    Fraction46 AddModul( const Fraction46 & a, const Fraction46 & b ) const;
    Fraction46 SubModul( const Fraction46 & a, const Fraction46 & b ) const;	    //|a| >= |b|
    //    Fraction46 MulModul( const Fraction46 & a, const Fraction46 & b ) const;
    //    Fraction46 MulDesyatki( int mul ) const;
    //    Fraction46 MulOneNumber( int num ) const;
    //    Fraction46 Modul( const Fraction46 & a ) const;
    //    Fraction46 OneDivFrac( const Fraction46 & a ) const;
    bool LessMod( const Fraction46 & b ) const;
    bool EqModul( const Fraction46 & b ) const;
    bool LessEqModul( const Fraction46 & b ) const;
    Fraction46 Revert( ) const;
    Fraction46 OneDivFrac( ) const;
    bool IsZero( ) const;

private:
    //при whole [-1; 1] знак числа теряется, т.к. 0 он и есть 0
    static constexpr int ACCURACY = 10000;
    LongLong38B whole_;
    double fractional_;
    bool negative_;
};

#endif // FRACTION46_H
