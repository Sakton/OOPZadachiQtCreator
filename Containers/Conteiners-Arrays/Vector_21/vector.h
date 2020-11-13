#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>
#include <stdexcept>

class Vector;
Vector operator+( const Vector &v1, const Vector &v2 );

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
  Vector &operator+=( const Vector &v );
  Vector &operator-=( const Vector &v );
  Vector &operator*=( const Vector &v );
  template < typename T >
  Vector &operator*=( const T &n );
  template < typename T >
  Vector &operator/=( const T &n );
  void swap( Vector &v );

  // size
  size_type size( ) const;
  bool empty( ) const;

  // friends
  friend Vector operator+( const Vector &v1, const Vector &v2 );

 private:
  size_type count_;
  value_type *data_;
};

}  // namespace MY

#endif  // VECTOR_H
