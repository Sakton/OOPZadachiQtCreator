#ifndef ARRAY_H
#define ARRAY_H
#include <cstdint>
#include <iostream>
#include <stdexcept>

// WARNING Оператор чтения из потока не сделано. Не ясно как

// forvard rpe-definition
template < typename T, std::int32_t N >
class Array2;

template < typename T, std::int32_t N >
std::ostream &operator<<( std::ostream &out, const Array2< T, N > &ar );
template < typename T, std::int32_t N >
std::istream &operator>>( std::istream &in, Array2< T, N > &ar );

template < typename T, std::int32_t N >
Array2< T, N > operator+( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );
template < typename T, std::int32_t N >
Array2< T, N > operator-( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );
template < typename T, std::int32_t N >
Array2< T, N > operator*( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );
template < typename T, std::int32_t N >
Array2< T, N > operator/( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );

template < typename T, std::int32_t N >
bool operator==( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );
template < typename T, std::int32_t N >
bool operator!=( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );

// class
template < typename T, std::int32_t N = 10 >
class Array2 {
 public:
  // types definition
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::int32_t;
  static constexpr size_type SIZE = N;
  // iterator definition
  using iterator = T *;
  using const_iterator = const T *;

  Array2( );
  Array2( iterator first, iterator second );
  Array2( const Array2 &ar );
  Array2( Array2 &&ar );
  ~Array2( );

  Array2 &operator=( const Array2 &ar );
  Array2 &operator=( Array2 &&ar );

  // size definition
  size_type size( ) const;

  // overloaded operator
  reference operator[]( size_type ind );
  const_reference operator[]( size_type ind ) const;

  Array2 &operator+=( const Array2 &ar );
  Array2 &operator-=( const Array2 &ar );
  Array2 &operator*=( const Array2 &ar );
  Array2 &operator/=( const Array2 &ar );

  // iterators
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;

  // frienads
  friend std::ostream &operator<<< T, N >( std::ostream &out,
                                           const Array2< T, N > &ar );

  // WARNING Array2< T, N > &ar NON CONST OBJECT!!!!!!!!!!!!!!
  friend std::istream &operator>>
      < T, N >( std::istream &in, Array2< T, N > &ar );

  friend Array2< T, N > operator+
      < T, N >( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );
  friend Array2< T, N > operator-
      < T, N >( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );
  friend Array2< T, N > operator*
      < T, N >( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );
  friend Array2< T, N > operator/
      < T, N >( const Array2< T, N > &ar1, const Array2< T, N > &ar2 );

  friend bool operator==( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );
  friend bool operator!=( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 );

 private:
  void rangeCheck( size_type ind ) const;

 private:
  T *elements_;
};

//************realization
template < typename T, std::int32_t N >
Array2< T, N >::Array2( ) : elements_ { new T[ SIZE ] { T( ) } } {}

template < typename T, std::int32_t N >
Array2< T, N >::Array2( Array2::iterator first, Array2::iterator second )
    : elements_ { new T[ SIZE ] { T( ) } } {
  std::copy( first, second, elements_ );
}

template < typename T, std::int32_t N >
Array2< T, N >::Array2( const Array2< T, N > &ar )
    : elements_ { new T[ SIZE ] { T( ) } } {
  std::copy( ar.begin( ), ar.end( ), elements_ );
}

template < typename T, std::int32_t N >
Array2< T, N >::Array2( Array2< T, N > &&ar ) : elements_ { nullptr } {
  elements_ = std::move( ar.elements_ );
  ar.elements_ = nullptr;
}

template < typename T, std::int32_t N >
Array2< T, N >::~Array2( ) {
  delete[] elements_;
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator=( const Array2 &ar ) {
  if ( this != &ar ) {
    std::copy( ar.begin( ), ar.end( ), elements_ );
  }
  return *this;
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator=( Array2< T, N > &&ar ) {
  if ( this != &ar ) {
    delete[] elements_;
    elements_ = ar.elements_;
    ar.elements_ = nullptr;
  }
  return *this;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::size_type Array2< T, N >::size( ) const {
  return SIZE;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::reference Array2< T, N >::operator[]( size_type ind ) {
  rangeCheck( ind );
  return elements_[ ind ];
}

template < typename T, std::int32_t N >
typename Array2< T, N >::const_reference Array2< T, N >::operator[](
    size_type ind ) const {
  rangeCheck( ind );
  return elements_[ ind ];
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator+=( const Array2< T, N > &ar ) {
  for ( int i = 0; i < SIZE; ++i ) {
    ( *this )[ i ] += ar[ i ];
  }
  return *this;
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator-=( const Array2< T, N > &ar ) {
  for ( int i = 0; i < SIZE; ++i ) {
    ( *this )[ i ] -= ar[ i ];
  }
  return *this;
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator*=( const Array2< T, N > &ar ) {
  for ( int i = 0; i < SIZE; ++i ) {
    ( *this )[ i ] *= ar[ i ];
  }
  return *this;
}

template < typename T, std::int32_t N >
Array2< T, N > &Array2< T, N >::operator/=( const Array2< T, N > &ar ) {
  for ( int i = 0; i < SIZE; ++i ) {
    ( *this )[ i ] /= ar[ i ];
  }
  return *this;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::iterator Array2< T, N >::begin( ) {
  return elements_;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::const_iterator Array2< T, N >::begin( ) const {
  return elements_;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::iterator Array2< T, N >::end( ) {
  return elements_ + SIZE;
}

template < typename T, std::int32_t N >
typename Array2< T, N >::const_iterator Array2< T, N >::end( ) const {
  return elements_ + SIZE;
}

template < typename T, std::int32_t N >
void Array2< T, N >::rangeCheck( Array2::size_type ind ) const {
  if ( !( 0 <= ind && ind < SIZE ) ) throw std::range_error( "OUT OF RANGE " );
}

// friends
template < typename T, std::int32_t N >
std::ostream &operator<<( std::ostream &out, const Array2< T, N > &ar ) {
  std::copy( ar.begin( ), ar.end( ), std::ostream_iterator< T >( out, " " ) );
  return out;
}

// WARNING доделать как будет решение
template < typename T, std::int32_t N >
std::istream &operator>>( std::istream &in, Array2< T, N > &ar ) {
  //  std::copy(
  //      std::istream_iterator< T >( in ), std::istream_iterator< T >( ),
  //      std::back_insert_iterator< typename Array2< T, N >::value_type >( ar )
  //      );
  std::cout << "enter i = " << N << " ;" << std::endl;
  for ( int i = 0; i < N; ++i ) {
    in >> ar[ i ];
    std::cout << "enter i = " << N - i << " ;" << std::endl;
  }
  //  std::copy( ar.begin( ), ar.end( ), std::istream_iterator< T >( in ) );
  return in;
}

template < typename T, std::int32_t N >
Array2< T, N > operator+( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 ) {
  Array2< T, N > loc = ar1;
  loc += ar2;
  return loc;
}

template < typename T, std::int32_t N >
Array2< T, N > operator-( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 ) {
  Array2< T, N > loc = ar1;
  loc -= ar2;
  return loc;
}

template < typename T, std::int32_t N >
Array2< T, N > operator*( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 ) {
  Array2< T, N > loc = ar1;
  loc *= ar2;
  return loc;
}
template < typename T, std::int32_t N >
Array2< T, N > operator/( const Array2< T, N > &ar1,
                          const Array2< T, N > &ar2 ) {
  Array2< T, N > loc = ar1;
  loc /= ar2;
  return loc;
}

template < typename T, std::int32_t N >
bool operator==( const Array2< T, N > ar1, const Array2< T, N > ar2 ) {
  for ( int i = 0; i < N; ++i ) {
    if ( ar1[ i ] != ar2[ i ] ) return false;
  }
  return true;
}

template < typename T, std::int32_t N >
bool operator!=( const Array2< T, N > ar1, const Array2< T, N > ar2 ) {
  return !( ar1 == ar2 );
}

#endif  // ARRAY_H
