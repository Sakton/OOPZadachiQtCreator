#ifndef ARRAY4_H
#define ARRAY4_H
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
// predifinition
template < typename T, int L, int R >
class Array4;
// friend predefinition
template < typename T, int L, int R >
std::ostream &operator<<( std::ostream &out, const Array4< T, L, R > &ar );
template < typename T, int L, int R >
std::istream &operator>>( std::istream &in, Array4< T, L, R > &ar );

template < typename T, int L, int R >
class Array4 {
 public:
  // type definition
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = int32_t;
  // static const
  static constexpr size_type SIZE = R - L;

  // ctor
  Array4( );

  // iterators
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;

  // operators
  reference operator[]( int ind );
  const_reference operator[]( int ind ) const;

  // friends
  friend std::ostream &operator<<< T, L, R >( std::ostream &out,
                                              const Array4< T, L, R > &ar );
  friend std::istream &operator>>
      < T, L, R >( std::istream &in, Array4< T, L, R > &ar );

 private:
  value_type *elements_;
};

#endif // ARRAY4_H

template < typename T, int L, int R >
Array4< T, L, R >::Array4( ) : elements_ { new value_type[ SIZE ] { T {} } } {}

template < typename T, int L, int R >
typename Array4< T, L, R >::iterator Array4< T, L, R >::begin( ) {
  return elements_;
}

template < typename T, int L, int R >
typename Array4< T, L, R >::const_iterator Array4< T, L, R >::begin( ) const {
  return elements_;
}

template < typename T, int L, int R >
typename Array4< T, L, R >::iterator Array4< T, L, R >::end( ) {
  return elements_ + SIZE;
}

template < typename T, int L, int R >
typename Array4< T, L, R >::const_iterator Array4< T, L, R >::end( ) const {
  return elements_ + SIZE;
}

template < typename T, int L, int R >
typename Array4< T, L, R >::reference Array4< T, L, R >::operator[]( int ind ) {
  return elements_[ ind - L ];
}

template < typename T, int L, int R >
typename Array4< T, L, R >::const_reference Array4< T, L, R >::operator[](
    int ind ) const {
  return elements_[ ind - L ];
}

template < typename T, int L, int R >
std::ostream &operator<<( std::ostream &out, const Array4< T, L, R > &ar ) {
  std::copy( ar.begin( ), ar.end( ), std::ostream_iterator< T >( out, " " ) );
  return out;
}

template < typename T, int L, int R >
std::istream &operator>>( std::istream &in, Array4< T, L, R > &ar ) {
  for ( int i = L; i < R; ++i ) {
    in >> ar[ i ];
  }
  return in;
}
