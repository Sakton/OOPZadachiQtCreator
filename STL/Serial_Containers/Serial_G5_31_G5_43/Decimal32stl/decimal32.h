#ifndef DECIMAL32_H
#define DECIMAL32_H
#include <iostream>
#include <string>
#include <vector>

class Decimal32 {
  using value_type = uint8_t;
  using container_type = std::vector< value_type >;

 private:
  explicit Decimal32( container_type::size_type n );  //для внутренних нужд

 public:
  Decimal32( const std::string &str );

  // operators
  Decimal32 &operator+=( const Decimal32 &rhs );
  Decimal32 &operator-=( const Decimal32 &rhs );
  Decimal32 &operator*=( const Decimal32 &rhs );
  Decimal32 &operator/=( const Decimal32 &rhs );

  void swap( Decimal32 &oth );

  friend std::ostream &operator<<( std::ostream &out, const Decimal32 &dcm );
  friend bool operator<( const Decimal32 &a, const Decimal32 &b );
  friend bool operator<=( const Decimal32 &a, const Decimal32 &b );
  friend bool operator>=( const Decimal32 &a, const Decimal32 &b );
  friend bool operator>( const Decimal32 &a, const Decimal32 &b );
  friend bool operator==( const Decimal32 &a, const Decimal32 &b );
  friend bool operator!=( const Decimal32 &a, const Decimal32 &b );

  void printDebugTryth( );

  container_type::size_type size( ) const;

 private:
  void trimZero( );

 private:
  container_type decimal_;
};

#endif  // DECIMAL32_H
