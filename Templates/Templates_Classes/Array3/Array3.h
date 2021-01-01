#ifndef ARRAY3_H
#define ARRAY3_H
#include <cstdint>
#include <iostream>
#include <iterator>

// pre-definition
template < typename T, std::int32_t F, std::int32_t S >
class Array3;
// pre-difinition friend
template < typename T, std::int32_t F, std::int32_t S >
std::ostream &operator<<( std::ostream &out, const Array3< T, F, S > &ar );

template < typename T, std::int32_t F, std::int32_t S >
std::istream &operator>>( std::istream &in, Array3< T, F, S > &ar );

template < typename T, std::int32_t F, std::int32_t S >
class Array3 {
 public:
  // type definitions
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  // size type definition
  using size_type = std::int32_t;

  // static size
  static constexpr size_type SIZE = S - F;
  static constexpr size_type LEFT = F;
  static constexpr size_type RIGHT = S;

  Array3( );
  ~Array3( );

  // iterators
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;

  // operators
  reference operator[]( size_type ind );
  const_reference operator[]( size_type ind ) const;

  // methods
  std::ostream &print( std::ostream &out ) const;

  // friends
  friend std::ostream &operator<<< T, F, S >( std::ostream &out,
                                              const Array3< T, F, S > &ar );
  friend std::istream &operator>>
      < T, F, S >( std::istream &in, Array3< T, F, S > &ar );

 private:
  void rangeChek( size_type ind );

 private:
  T *elem_;
};

#endif // ARRAY3_H

template < typename T, std::int32_t F, std::int32_t S >
Array3< T, F, S >::Array3( ) : elem_ { new T[ SIZE ] { T( ) } } {}

template < typename T, std::int32_t F, std::int32_t S >
Array3< T, F, S >::~Array3( ) {
  delete[] elem_;
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::iterator Array3< T, F, S >::begin( ) {
  return elem_;
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::const_iterator Array3< T, F, S >::begin( ) const {
  return elem_;
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::iterator Array3< T, F, S >::end( ) {
  return elem_ + SIZE;
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::const_iterator Array3< T, F, S >::end( ) const {
  return elem_ + SIZE;
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::reference Array3< T, F, S >::operator[](
    Array3::size_type ind ) {
  rangeChek( ind );
  return elem_[ ind - LEFT ];
}

template < typename T, std::int32_t F, std::int32_t S >
typename Array3< T, F, S >::const_reference Array3< T, F, S >::operator[](
    Array3::size_type ind ) const {
  rangeChek( ind );
  return elem_[ ind = LEFT ];
}

template < typename T, std::int32_t F, std::int32_t S >
std::ostream &Array3< T, F, S >::print( std::ostream &out ) const {
  std::copy( begin( ), end( ), std::ostream_iterator< T >( out, " " ) );
  return out;
}

template < typename T, std::int32_t F, std::int32_t S >
void Array3< T, F, S >::rangeChek( Array3::size_type ind ) {
  if ( !( LEFT <= ind && ind < RIGHT ) ) throw std::range_error( "range err" );
}

// friend
template < typename T, std::int32_t F, std::int32_t S >
std::ostream &operator<<( std::ostream &out, const Array3< T, F, S > &ar ) {
  return ar.print( out );
}

// TODO снова
template < typename T, std::int32_t F, std::int32_t S >
std::istream &operator>>( std::istream &in, Array3< T, F, S > &ar ) {
  for ( auto i = ar.begin( ); i != ar.end( ); ++i ) {
    in >> *i;
  }
  return in;
}
