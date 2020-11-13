#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <stdexcept>

namespace MY {

class Vector {
 public:
  // type defines
  using value_type = int;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;

  using size_type = std::size_t;

  // ctor/dtor/op=
  explicit Vector( size_type n, value_type k = 0 );
  Vector( const_iterator beg, const_iterator end );
  ~Vector( );
  Vector( const Vector &vec );
  Vector( Vector &&vec );

  Vector &operator=( const Vector &vec );
  Vector &operator=( Vector &&vec );

  reference operator[]( size_type idx );
  const_reference operator[]( size_type idx ) const;

  // iteration
  iterator begin( );
  iterator end( );
  const_iterator begin( ) const;
  const_iterator end( ) const;

  // modify operations
  const Vector &operator+=( const Vector &rhs );
  const Vector &operator-=( const Vector &rhs );
  const Vector &operator*=( const Vector &rhs );
  template < typename T >
  const Vector &operator*=( const T &n );
  template < typename T >
  const Vector &operator/=( const T &n );
  void swap( Vector &v );
  // size
  size_type size( ) const;
  bool empty( ) const;

  // friends
  friend const Vector operator+( const Vector &lhs, const Vector &rhs );
  friend const Vector operator-( const Vector &lhs, const Vector &rhs );

  template < typename T >
  friend const Vector operator*( const T &n, const Vector &rhs );

  template < typename T >
  friend const Vector operator*( const Vector &lhs, const T &n );

  double euclidNorm( ) const;

  friend bool eqEuclidNorn( const Vector &lhs, const Vector &rhs );

 private:
  void lessCount( const Vector &rhs );

 private:
  size_type count_;
  value_type *data_;
};

template < typename T >
const Vector &Vector::operator/=( const T &n ) {
  Vector tmp( size( ) );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::divides< MY::Vector::value_type >( ), std::placeholders::_1, n ) );
  swap( tmp );
  return *this;
}

template < typename T >
const Vector &Vector::operator*=( const T &n ) {
  Vector tmp( size( ) );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::multiplies< MY::Vector::value_type >( ), std::placeholders::_1, n ) );
  swap( tmp );
  return *this;
}

template < typename T >
const Vector operator*( const T &n, const Vector &rhs ) {
  Vector loc = rhs;
  loc *= n;
  return loc;
}

template < typename T >
const Vector operator*( const Vector &lhs, const T &n ) {
  return n * lhs;
}

}  // namespace MY

#endif  // VECTOR_H
