#ifndef FRACTION35_H
#define FRACTION35_H
#include <string>

/*
int16_t - 65536 - макс число для ushort
но нам нужен переход через 1, тогда максимальное число для представления 9999,
любой дополнительный символ приведет к переполнению
При этом 9999 * 2 = 19998 - находится в диапазоне.
Поэтому максимальная точность числа - 4 порядка
*/

class Fraction35B {
 public:
  Fraction35B( int64_t w = 0, int16_t f = 0 );
  friend void Display( const Fraction35B& b );
  friend std::string ToString( const Fraction35B& b );
  // void Read(  );

  friend Fraction35B operator+( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator-( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator*( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B operator/( const Fraction35B& a, const Fraction35B& b );

  //  Fraction35B Add( const Fraction35B& b ) const;
  //  Fraction35B Sub( const Fraction35B& b ) const;
  //  Fraction35B Mul( const Fraction35B& b ) const;
  //  Fraction35B Div( const Fraction35B& b ) const;

  bool Less( const Fraction35B& b ) const;

  friend bool operator<( const Fraction35B& a, const Fraction35B& b );
  friend bool operator<=( const Fraction35B& a, const Fraction35B& b );
  friend bool operator>( const Fraction35B& a, const Fraction35B& b );
  friend bool operator>=( const Fraction35B& a, const Fraction35B& b );
  friend bool operator==( const Fraction35B& a, const Fraction35B& b );
  friend bool operator!=( const Fraction35B& a, const Fraction35B& b );

  friend int64_t Whole( const Fraction35B& a );
  friend int16_t Fractional( const Fraction35B& a );
  friend bool GetNegative( const Fraction35B& a );

  // private:
  friend Fraction35B AddModul( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B SubModul( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B MulModul( const Fraction35B& a, const Fraction35B& b );
  friend Fraction35B MulDesyatki( const Fraction35B& a, int mul );
  friend Fraction35B MulOneNumber( const Fraction35B& a, int num );
  friend Fraction35B Modul( const Fraction35B& a );
  friend Fraction35B OneDivFrac( const Fraction35B& a, const Fraction35B& b );
  friend bool LessMod( const Fraction35B& a, const Fraction35B& b );
  friend bool EqModul( const Fraction35B& a, const Fraction35B& b );

 private:
  int64_t whole_;
  int16_t fractional_;
  //при whole == 0 знак числа теряется
  bool negative;
};

#endif // FRACTION35_H
