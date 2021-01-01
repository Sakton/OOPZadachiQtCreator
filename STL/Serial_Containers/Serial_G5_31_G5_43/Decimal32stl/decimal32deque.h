#ifndef DECIMAL32QUEUE_H
#define DECIMAL32QUEUE_H
#include <cstdint>
#include <deque>
#include <iostream>
// Decimal32Queue

namespace sktn {

class Decimal32 {
  // types
  using value_type = uint8_t;
  using container_type = std::deque< value_type >;

 private:
  explicit Decimal32( container_type::size_type n );  //для внутренних нужд

 public:
  Decimal32( const std::string &str );

  // operators
  Decimal32 &operator+=( const Decimal32 &rhs );
  Decimal32 &operator-=( const Decimal32 &rhs );
  Decimal32 &operator*=( const Decimal32 &rhs );
  Decimal32 &operator/=( const Decimal32 &rhs );
  Decimal32 &operator%=( const Decimal32 &rhs );

  // friends
  friend std::ostream &operator<<( std::ostream &out, const Decimal32 &dcm );
  friend bool operator<( const Decimal32 &a, const Decimal32 &b );
  friend bool operator==( const Decimal32 &a, const Decimal32 &b );

  // swap
  void swap( Decimal32 &oth );

  // sizes
  container_type::size_type size( ) const;

 private:
  explicit operator std::string( ) const;
  void trimZero( );

 private:
  container_type decimal_;
};

const Decimal32 operator+( const Decimal32 &lhs, const Decimal32 &rhs );
const Decimal32 operator-( const Decimal32 &lhs, const Decimal32 &rhs );
const Decimal32 operator*( const Decimal32 &lhs, const Decimal32 &rhs );
const Decimal32 operator/( const Decimal32 &lhs, const Decimal32 &rhs );
const Decimal32 operator%( const Decimal32 &lhs, const Decimal32 &rhs );

bool operator<=( const Decimal32 &a, const Decimal32 &b );
bool operator>=( const Decimal32 &a, const Decimal32 &b );
bool operator>( const Decimal32 &a, const Decimal32 &b );
bool operator!=( const Decimal32 &a, const Decimal32 &b );

void swap( Decimal32 &lhs, Decimal32 &rhs );

}  // namespace sktn

#endif  // DECIMAL32QUEUE_H
