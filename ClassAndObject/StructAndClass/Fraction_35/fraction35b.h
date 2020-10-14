#ifndef FRACTION25B_H
#define FRACTION25B_H
#include <string>

/*
int16_t - 65536 - макс число для ushort
но нам нужен переход через 1, тогда максимальное число для представления 9999,
любой дополнительный символ приведет к переполнению
При этом 9999 * 2 = 19998 - находится в диапазоне.
Поэтому максимальная точность числа - 4 порядка
*/

//TODO этот класс можно переработать после введения знака
//много лишнего
//потом

class Fraction35B {
public:
    void Init( int64_t w = 0, int16_t f = 0 );
    void Display( ) const;
    std::string ToString( ) const;
    //void Read(  );

    Fraction35B Add( const Fraction35B & b ) const;
    Fraction35B Sub( const Fraction35B & b ) const;
    Fraction35B Mul( const Fraction35B & b ) const;
    Fraction35B Div( const Fraction35B & b ) const;

    bool Less( const Fraction35B & b ) const;

    int64_t Whole( ) const;
    int16_t Fractional( ) const;
    bool GetNegative( ) const;

private:
    Fraction35B AddModul( const Fraction35B & a, const Fraction35B & b ) const;
    Fraction35B SubModul( const Fraction35B & a, const Fraction35B & b ) const;
    Fraction35B MulModul( const Fraction35B & a, const Fraction35B & b ) const;
    Fraction35B MulDesyatki( int mul ) const;
    Fraction35B MulOneNumber( int num ) const;
    Fraction35B Modul( const Fraction35B & a ) const;
    Fraction35B OneDivFrac( const Fraction35B & a ) const;
    bool LessMod( const Fraction35B & b ) const;
    bool EqModul( const Fraction35B & b ) const;

private:
    int64_t whole_;
    int16_t fractional_;
    //при whole == 0 знак числа теряется
    bool negative;
};

#endif // FRACTION25B_H
