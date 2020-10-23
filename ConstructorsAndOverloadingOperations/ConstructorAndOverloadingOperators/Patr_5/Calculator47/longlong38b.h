#ifndef LONGLONG38B_H
#define LONGLONG38B_H
#include <string>

class LongLong38B {
 public:
  explicit LongLong38B( int64_t bits_64_num = 0 );
  void Display( ) const;
  // std::string ToString( ) const;

  explicit operator std::string( ) const;
  explicit operator int64_t( ) const;

  LongLong38B &operator+=( const LongLong38B &b );
  LongLong38B &operator+=( int32_t b );
  LongLong38B &operator-=( const LongLong38B &b );
  LongLong38B &operator-=( int32_t b );
  LongLong38B &operator*=( const LongLong38B &b );
  LongLong38B &operator*=( int32_t b );
  LongLong38B &operator/=( const LongLong38B &b );
  LongLong38B &operator/=( int32_t b );

  friend LongLong38B operator+( const LongLong38B &b1, const LongLong38B &b2 );
  friend LongLong38B operator+( const LongLong38B &b1, int64_t x );
  friend LongLong38B operator+( int64_t x, const LongLong38B &b1 );
  friend LongLong38B operator-( const LongLong38B &b1, const LongLong38B &b2 );
  friend LongLong38B operator-( const LongLong38B &b1, int64_t x );
  friend LongLong38B operator-( int64_t x, const LongLong38B &b1 );
  friend LongLong38B operator*( const LongLong38B &b1, const LongLong38B &b2 );
  friend LongLong38B operator*( const LongLong38B &b1, int64_t x );
  friend LongLong38B operator*( int64_t x, const LongLong38B &b1 );
  friend LongLong38B operator/( const LongLong38B &b1, const LongLong38B &b2 );
  friend LongLong38B operator/( const LongLong38B &b1, int64_t x );
  friend LongLong38B operator/( int64_t x, const LongLong38B &b1 );

  LongLong38B Modul( ) const;

  friend bool operator<( const LongLong38B &b1, const LongLong38B &b2 );
  friend bool operator<=( const LongLong38B &b1, const LongLong38B &b2 );
  friend bool operator>=( const LongLong38B &b1, const LongLong38B &b2 );
  friend bool operator>( const LongLong38B &b1, const LongLong38B &b2 );
  friend bool operator==( const LongLong38B &b1, const LongLong38B &b2 );
  friend bool operator!=( const LongLong38B &b1, const LongLong38B &b2 );

 private:
  static const uint32_t MASK_ = 0xffffffff;  // 32 битная маска
  int32_t senior_;
  uint32_t junior_;
};

#endif // LONGLONG38B_H
