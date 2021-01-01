#ifndef Decimal32ListLIST_H
#define Decimal32ListLIST_H
#include <iostream>
#include <list>
#include <string>

namespace sktn {

class Decimal32List {
  // types
  using value_type = uint8_t;
  using container_type = std::list< value_type >;
  using reference = container_type::reference;
  using const_reference = container_type::const_reference;
  using size_type = container_type::size_type;
  using iterator = container_type::iterator;
  using const_iterator = container_type::const_iterator;

 private:
  explicit Decimal32List( container_type::size_type n );  //для внутренних нужд

 public:
  Decimal32List( const std::string &str );

  // operator[]
  const_reference operator[]( size_type idx ) const;
  reference operator[]( size_type idx );
  //  const_iterator iterat( size_type di ) const;
  //  iterator iterat( size_type di );

  // operators
  Decimal32List &operator+=( const Decimal32List &rhs );
  Decimal32List &operator-=( const Decimal32List &rhs );
  Decimal32List &operator*=( const Decimal32List &rhs );
  Decimal32List &operator/=( const Decimal32List &rhs );
  Decimal32List &operator%=( const Decimal32List &rhs );

  // friends
  friend std::ostream &operator<<( std::ostream &out, const Decimal32List &dcm );
  friend bool operator<( const Decimal32List &a, const Decimal32List &b );
  friend bool operator==( const Decimal32List &a, const Decimal32List &b );

  // swap
  void swap( Decimal32List &oth );

  // sizes
  container_type::size_type size( ) const;

 private:
  explicit operator std::string( ) const;
  void trimZero( );

 private:
  container_type decimal_;
};

const Decimal32List operator+( const Decimal32List &lhs, const Decimal32List &rhs );
const Decimal32List operator-( const Decimal32List &lhs, const Decimal32List &rhs );
const Decimal32List operator*( const Decimal32List &lhs, const Decimal32List &rhs );
const Decimal32List operator/( const Decimal32List &lhs, const Decimal32List &rhs );
const Decimal32List operator%( const Decimal32List &lhs, const Decimal32List &rhs );

bool operator<=( const Decimal32List &a, const Decimal32List &b );
bool operator>=( const Decimal32List &a, const Decimal32List &b );
bool operator>( const Decimal32List &a, const Decimal32List &b );
bool operator!=( const Decimal32List &a, const Decimal32List &b );

void swap( Decimal32List &lhs, Decimal32List &rhs );

}  // namespace sktn

#endif  // Decimal32ListLIST_H
