#ifndef MONEY24_H
#define MONEY24_H
#include <string>
// 1. Приведено к нормальному классу

class Money24 {
 public:
  explicit Money24( int32_t rb = 0, int16_t cp = 0 );
  explicit Money24( double sum );  //Добавлено

  Money24& operator+=( const Money24& b );
  Money24& operator-=( const Money24& b );
  Money24& operator*=( double x );
  Money24& operator/=( double x );
  double operator/=( const Money24& b );

  void Display( );
  void Read( );
  explicit operator std::string( ) const;
  explicit operator double( ) const;  //Добавлено

  friend Money24 operator+( const Money24& a, const Money24& b );
  friend Money24 operator-( const Money24& a, const Money24& b );
  friend Money24 operator*( const Money24& a, double x );
  friend double operator/( const Money24& a, const Money24& b );
  friend Money24 operator/( const Money24& a, double x );

  friend bool operator==( const Money24& a, const Money24& b );
  friend bool operator!=( const Money24& a, const Money24& b );
  friend bool operator<=( const Money24& a, const Money24& b );
  friend bool operator>=( const Money24& a, const Money24& b );
  friend bool operator<( const Money24& a, const Money24& b );
  friend bool operator>( const Money24& a, const Money24& b );

  int32_t GetRub( ) const;
  uint8_t GetCop( ) const;

 private:
  int32_t rub { 0 };
  uint8_t cop { 0 };
};

#endif // MONEY24_H
