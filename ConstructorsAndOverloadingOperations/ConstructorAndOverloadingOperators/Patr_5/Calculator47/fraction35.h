//#ifndef FRACTION35_H
//#define FRACTION35_H
//#include <string>

////#include "longlong38b.h"

///*
// int16_t - 65536 - макс число для ushort
//но нам нужен переход через 1, тогда максимальное число для представления 9999,
//любой дополнительный символ приведет к переполнению
//При этом 9999 * 2 = 19998 - находится в диапазоне.
//Поэтому максимальная точность числа - 4 порядка
//*/

// class Fraction35Long {
// public:
//  class LongLong38B {
//   public:
//    explicit LongLong38B( int64_t bits_64_num = 0 );
//    void Display( ) const;
//    // std::string ToString( ) const;

//    explicit operator std::string( ) const;
//    explicit operator int64_t( ) const;

//    LongLong38B& operator+=( const LongLong38B& b );
//    LongLong38B& operator+=( int32_t b );
//    LongLong38B& operator-=( const LongLong38B& b );
//    LongLong38B& operator-=( int32_t b );
//    LongLong38B& operator*=( const LongLong38B& b );
//    LongLong38B& operator*=( int32_t b );
//    LongLong38B& operator/=( const LongLong38B& b );
//    LongLong38B& operator/=( int32_t b );

//    friend LongLong38B operator+( const LongLong38B& b1,
//                                  const LongLong38B& b2 );
//    friend LongLong38B operator+( const LongLong38B& b1, int64_t x );
//    friend LongLong38B operator+( int64_t x, const LongLong38B& b1 );
//    friend LongLong38B operator-( const LongLong38B& b1,
//                                  const LongLong38B& b2 );
//    friend LongLong38B operator-( const LongLong38B& b1, int64_t x );
//    friend LongLong38B operator-( int64_t x, const LongLong38B& b1 );
//    friend LongLong38B operator*( const LongLong38B& b1,
//                                  const LongLong38B& b2 );
//    friend LongLong38B operator*( const LongLong38B& b1, int64_t x );
//    friend LongLong38B operator*( int64_t x, const LongLong38B& b1 );
//    friend LongLong38B operator/( const LongLong38B& b1,
//                                  const LongLong38B& b2 );
//    friend LongLong38B operator/( const LongLong38B& b1, int64_t x );
//    friend LongLong38B operator/( int64_t x, const LongLong38B& b1 );

//    LongLong38B Modul( ) const;

//    friend bool operator<( const LongLong38B& b1, const LongLong38B& b2 );
//    friend bool operator<=( const LongLong38B& b1, const LongLong38B& b2 );
//    friend bool operator>=( const LongLong38B& b1, const LongLong38B& b2 );
//    friend bool operator>( const LongLong38B& b1, const LongLong38B& b2 );
//    friend bool operator==( const LongLong38B& b1, const LongLong38B& b2 );
//    friend bool operator!=( const LongLong38B& b1, const LongLong38B& b2 );

//   private:
//    static const uint32_t MASK_ = 0xffffffff;  // 32 битная маска
//    int32_t senior_;
//    uint32_t junior_;
//  };

//  explicit Fraction35Long( const LongLong38B& w = LongLong38B( ),
//                           double f = 0 );
//  void Display( ) const;
//  explicit operator std::string( ) const;

//  Fraction35Long& operator+=( const Fraction35Long& b );
//  Fraction35Long& operator-=( const Fraction35Long& b );
//  Fraction35Long& operator*=( const Fraction35Long& b );
//  Fraction35Long& operator/=( const Fraction35Long& b );
//  Fraction35Long& operator-( );

//  friend Fraction35Long operator+( const Fraction35Long& a,
//                                   const Fraction35Long& b );
//  friend Fraction35Long operator-( const Fraction35Long& a,
//                                   const Fraction35Long& b );
//  friend Fraction35Long operator*( const Fraction35Long& a,
//                                   const Fraction35Long& b );
//  friend Fraction35Long operator/( const Fraction35Long& a,
//                                   const Fraction35Long& b );

//  friend bool operator<( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool operator<=( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool operator>( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool operator>=( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool operator==( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool operator!=( const Fraction35Long& a, const Fraction35Long& b );

//  LongLong38B Whole( );
//  int16_t Fractional( );
//  bool GetNegative( );

// private:
//  Fraction35Long AddModul( const Fraction35Long& a, const Fraction35Long& b );
//  Fraction35Long SubModul( const Fraction35Long& a, const Fraction35Long& b );
//  Fraction35Long MulModul( const Fraction35Long& a, const Fraction35Long& b );
//  Fraction35Long Modul( const Fraction35Long& a );

//  friend bool LessMod( const Fraction35Long& a, const Fraction35Long& b );
//  friend bool EqModul( const Fraction35Long& a, const Fraction35Long& b );

// private:
//  LongLong38B whole_;
//  double fractional_;
//  bool negative;
//};

//#endif // FRACTION35_H
