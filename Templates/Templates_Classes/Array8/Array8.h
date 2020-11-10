#ifndef ARRAY8_H
#define ARRAY8_H
#include <algorithm>
#include <cstdlib>
#include <iostream>
// пусть у этого массива стратегия роста, тоесть всегда есть элементы

template < typename T >
class Array8 {
 public:
  // type definition
  using type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  using size_type = std::size_t;

  // ctor/operator/move/dtor
  explicit Array8( size_type n = 5 );
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
  const_iterator cbegin( ) const;
  iterator end( );
  const_iterator cend( ) const;

  // modificators
  void insert( size_type idx, const type &v );
  void remove( size_type idx );

 private:
  void upVolume( );
  size_type newSize( size_type n );
  void indexValid( size_type idx );

 private:
  type *elements_;
  size_type size_;
  size_type capacity_;
};

template < typename T >
Array8< T >::Array8( Array8::size_type n )
    : elements_ { new type[ newSize( n ) ] { T( ) } },
      size_ { n },
      capacity_ { newSize( n ) } {}

template < typename T >
Array8< T >::Array8( Array8::size_type n, Array8::type el )
    : elements_ { new type[ newSize( n ) ] { el } },
      size_ { n },
      capacity_ { newSize( n ) } {
  std::fill( begin( ), end( ), el );
}

template < typename T >
Array8< T >::~Array8( ) {
  delete[] elements_;
}

template < typename T >
Array8< T >::Array8( const Array8 &ar ) {
  type *t = new type[ newSize( ar.size( ) ) ];
  std::copy( ar.cbegin( ), ar.cend( ), t );
  size_ = ar.size( );
  capacity_ = ar.capacity( );
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
    type *t = new type[ newSize( ar.size( ) ) ];
    std::copy( ar.begin( ), ar.end( ), t );
    delete[] elements_;
    elements_ = t;
    size_ = ar.size_;
    capacity_ = newSize( ar.size( ) );
  }
  return *this;
}

template < typename T >
Array8< T > &Array8< T >::operator=( Array8 &&ar ) {
  if ( this != &ar ) {
    delete[] elements_;
    elements_ = ar.elements_;
    ar.elements_ = nullptr;
    size_ = ar.size_;
    capacity_ = ar.capacity_;
  }
  return *this;
}

template < typename T >
typename Array8< T >::size_type Array8< T >::size( ) const {
  return size_;
}

template < typename T >
typename Array8< T >::size_type Array8< T >::capacity( ) const {
  return capacity_;
}

template < typename T >
bool Array8< T >::isEmpty( ) {
  return size_ == 0;
}

template < typename T >
typename Array8< T >::reference Array8< T >::operator[](
    Array8::size_type idx ) {
  indexValid( idx );
  return elements_[ idx ];
}

template < typename T >
typename Array8< T >::const_reference Array8< T >::operator[](
    Array8::size_type idx ) const {
  indexValid( idx );
  return elements_[ idx ];
}

template < typename T >
typename Array8< T >::iterator Array8< T >::begin( ) {
  return elements_;
}

template < typename T >
typename Array8< T >::const_iterator Array8< T >::cbegin( ) const {
  return elements_;
}

template < typename T >
typename Array8< T >::iterator Array8< T >::end( ) {
  return elements_ + size( );
}

template < typename T >
typename Array8< T >::const_iterator Array8< T >::cend( ) const {
  return elements_ + size( );
}

template < typename T >  // TODO requires testing
void Array8< T >::insert( Array8::size_type idx, const type &v ) {
  indexValid( idx );
  if ( size( ) + 1 >= capacity( ) ) upVolume( );
  if ( idx == size( ) ) {
    ( *this )[ idx ] = v;
  } else {
    int i = size( ) - 1;
    for ( ; i >= idx && i >= 0; --i ) {
      ( *this )[ i + 1 ] = ( *this )[ i ];
    }
    ( *this )[ i + 1 ] = v;
  }
  ++size_;
}

template < typename T >  // TODO requires testing
void Array8< T >::remove( Array8::size_type idx ) {
  indexValid( idx );
  for ( size_type i = idx; i < size( ) - 1; ++i ) {
    ( *this )[ i ] = ( *this )[ i + 1 ];
  }
  --size_;
}

template < typename T >
void Array8< T >::upVolume( ) {
  type *t = new type[ newSize( size_ ) ];
  std::copy( begin( ), end( ), t );
  delete[] elements_;
  elements_ = t;
  capacity_ = newSize( size_ );
}

template < typename T >
typename Array8< T >::size_type Array8< T >::newSize( Array8::size_type n ) {
  return 2 * n;
}

template < typename T >
void Array8< T >::indexValid( Array8::size_type idx ) {
  if ( idx < 0 || size( ) < idx ) throw std::runtime_error( "OUT OF RANGE" );
}

#endif  // ARRAY8_H
