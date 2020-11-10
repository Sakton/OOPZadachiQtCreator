#ifndef ARRAY8_H
#define ARRAY8_H
#include <cstdlib>
#include <iostream>
// pre-definition

template < typename T >
class Array8 {
  // type definition
  using type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  using size_type = std::size_t;

  // ctor/operator/move/dtor
  Array8( size_type n );
  Array8( size_type n, type el );
  //  Array8( const_iterator beg, const_iterator end );
  ~Array8( );
  Array8( const Array8 &ar );
  Array8( Array8 &&ar );

  Array8 &operator=( const Array8 &ar );
  Array8 &operator=( Array8 &&ar );

  // size
  size_type size( ) const;
  size_type capacity( ) const;
  bool isEmpty( );

  // operators
  reference operator[]( size_type idx );
  const_reference operator[]( size_type idx ) const;

  // iterator
  iterator begin( );
  const_iterator begin( ) const;

 private:
  type *elements_;
  size_type size_;
  size_type capacity_;
};

#endif  // ARRAY8_H
