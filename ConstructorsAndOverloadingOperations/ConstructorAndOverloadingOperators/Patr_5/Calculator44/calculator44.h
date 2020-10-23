#ifndef CALCULATOR44_H
#define CALCULATOR44_H
//#include "fraction35.h"
#include "string"

class Calculator44 {
 public:
  class Fraction35B {
   public:
    explicit Fraction35B( int64_t w = 0, int16_t f = 0 );
    explicit Fraction35B( const std::string& s_num );
    explicit Fraction35B( double num );

    void Display( ) const;
    explicit operator std::string( ) const;
    // void Read(  );
    Fraction35B& operator-( );  // Adding

    //  Fraction35B& operator+=( const Fraction35B& b );
    //  Fraction35B& operator-=( const Fraction35B& b );
    //  Fraction35B& operator*=( const Fraction35B& b );
    //  Fraction35B& operator/=( const Fraction35B& b );

    friend Fraction35B operator+( const Fraction35B& a, const Fraction35B& b );
    friend Fraction35B operator-( const Fraction35B& a, const Fraction35B& b );
    friend Fraction35B operator*( const Fraction35B& a, const Fraction35B& b );
    friend Fraction35B operator/( const Fraction35B& a, const Fraction35B& b );

    friend bool operator<( const Fraction35B& a, const Fraction35B& b );
    friend bool operator<=( const Fraction35B& a, const Fraction35B& b );
    friend bool operator>( const Fraction35B& a, const Fraction35B& b );
    friend bool operator>=( const Fraction35B& a, const Fraction35B& b );
    friend bool operator==( const Fraction35B& a, const Fraction35B& b );
    friend bool operator!=( const Fraction35B& a, const Fraction35B& b );

    int64_t Whole( ) const;
    int16_t Fractional( ) const;
    bool GetNegative( ) const;

   private:
    Fraction35B AddModul( const Fraction35B& b ) const;  //складывает по модулю
    Fraction35B SubModul( const Fraction35B& b ) const;  //вычитает модули
    Fraction35B MulModul( const Fraction35B& b ) const;  //уменожает модули
    Fraction35B MulDesyatki(
        int mul ) const;  //умножить на порядок (10,100,1000)
    Fraction35B MulOneNumber( int num ) const;  //умножить на 1 число
    Fraction35B Modul( ) const;                 //взять модуль
    Fraction35B OneDivFrac( ) const;  // 1/x - единица деленная на

    bool LessMod( const Fraction35B& b ) const;  //меньше по млдулю
    bool EqModul( const Fraction35B& b ) const;  //равно по модулю

   private:
    int64_t whole_;
    int16_t fractional_;
    //при whole == 0 знак числа теряется
    //если рассматривать whole как число зо знаком и тащить его
    bool negative;
  };

  Fraction35B operator( )( const std::string& expr );

 private:
  std::string Postfix( const std::string& expr );
  // double Raschet( const std::string& expr );
  Fraction35B Raschet( const std::string& expr );
};
#endif // CALCULATOR44_H
