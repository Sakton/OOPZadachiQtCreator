#ifndef ARRAY8_H
#define ARRAY8_H
#include <cstdlib>
#include <iostream>
// пусть у этого массива стратегия роста, тоесть всегда есть элементы

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
  iterator end( );
  const_iterator end( ) const;

  // modificators
  void isert( size_type idx );
  void remove( size_type idx );

 private:
  void upVolume( );

 private:
  type *elements_;
  size_type size_;
  size_type capacity_;
};

#endif  // ARRAY8_H

template < typename T >
Array8< T >::Array8( Array8::size_type n )
    : elements_ { new type[ 2 * n ] { T( ) } },
      size_ { n },
      capacity_ { 2 * n } {}

template < typename T >
Array8< T >::Array8( Array8::size_type n, Array8::type el )
    : elements_ { new type[ 2 * n ] { el } },
      size_ { n },
      capacity_ { 2 * n } {}

template < typename T >
Array8< T >::~Array8( ) {
  delete[] elements_;
}

template < typename T >
Array8< T >::Array8( const Array8 &ar ) {
  type *t = new type[ 2 * ar.size( ) ];
  std::copy( ar.cbegin( ), ar.cend( ), t );
  size_ = ar.size( );
  capacity_ = 2 * ar.size( );
  delete[] elements_;
  elements_ = t;
}

template < typename T >
Array8< T >::Array8( Array8 &&ar ) {
  delete[] elements_;
  elements_ = ar.elements_;
  ar.elements_ = nullptr;
  size_ = ar.size( );
  capacity_ = ar.capacity( );
}

template < typename T >
Array8< T > &Array8< T >::operator=( const Array8 &ar ) {
  if ( this != &ar ) {
    type *t = new type[ ar.size( ) * 2 ];
    std::copy( );
  }
}
