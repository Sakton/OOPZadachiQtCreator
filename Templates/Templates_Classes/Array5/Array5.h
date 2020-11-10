#ifndef ARRAY5_H
#define ARRAY5_H
#include <cstdlib>
#include <iostream>
// FIXME 5 and 6
// pre-definition
template < typename T >
class Array5;
// pre-definition friend
template < typename T >
std::ostream &operator<<( std::ostream &out, const Array5< T > &ar );

template < typename T >
std::istream &operator>>( std::istream &in, Array5< T > &ar );

template < typename T >
Array5< T > operator+( const Array5< T > &ar1, const Array5< T > &ar2 );

template < typename T >
Array5< T > operator-( const Array5< T > &ar1, const Array5< T > &ar2 );

template < typename T >
Array5< T > operator*( const Array5< T > &ar1, const Array5< T > &ar2 );

template < typename T >
Array5< T > operator/( const Array5< T > &ar1, const Array5< T > &ar2 );

template < typename T >
bool operator==( const Array5< T > &ar1, const Array5< T > &ar2 );

template < typename T >
bool operator!=( const Array5< T > &ar1, const Array5< T > &ar2 );

// class
template < typename T >
class Array5 {
 public:
  // type definition
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // ctor
  Array5( size_type sz = 10 );
  Array5( const_iterator f, const_iterator s );
  ~Array5( );
  Array5( const Array5 &ar );
  Array5( Array5 &&ar );

  Array5 &operator=( const Array5 &ar );
  Array5 &operator=( Array5 &&ar );

  // iterators
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;

  // sizes
  size_type size( ) const;
  size_type capacity( ) const;
  void resize( );
  bool empty( ) const;

  // access elements
  reference operator[]( size_type ind );
  const_reference operator[]( size_type ind ) const;
  reference back( );
  const_reference back( ) const;

  // modificators
  void push_back( const value_type &v );
  void pop_back( );
  void clear( );
  void swap( Array5 &oth );

  // operators this
  Array5 &operator+=( const Array5 &ar );
  Array5 &operator-=( const Array5 &ar );
  Array5 &operator*=( const Array5 &ar );
  Array5 &operator/=( const Array5 &ar );

  // friends
  friend Array5 operator+
      < T >( const Array5< T > &ar1, const Array5< T > &ar2 );
  friend Array5 operator-< T >( const Array5 &ar1, const Array5 &ar2 );
  friend Array5 operator*< T >( const Array5 &ar1, const Array5 &ar2 );
  friend Array5 operator/< T >( const Array5 &ar1, const Array5 &ar2 );

  // predicates
  friend bool operator==< T >( const Array5 &ar1, const Array5 &ar2 );
  friend bool operator!=< T >( const Array5 &ar1, const Array5 &ar2 );

  // input/output
  friend std::ostream &operator<<< T >( std::ostream &out, const Array5 &ar );
  friend std::istream &operator>>< T >( std::istream &in, Array5 &ar );

 private:
  void rangecheck( size_type idx ) const;

 private:
  value_type *elem_;
  size_type count_;
  size_type capacity_;
};

template < typename T >
Array5< T >::Array5( Array5::size_type sz )
    : elem_ { new value_type[ sz ] { T( ) } }, count_ { 0 }, capacity_ { sz } {}

template < typename T >
Array5< T >::Array5( Array5::const_iterator f, Array5::const_iterator s )
/*: elem_ { nullptr }, count_ { 0 }, capacity_ { 0 }*/ {
  int sz = s - f;
  elem_ = new value_type[ sz ];
  count_ = sz;
  capacity_ = sz;
  std::copy( f, s, elem_ );
}

template < typename T >
Array5< T >::~Array5( ) {
  delete[] elem_;
}

template < typename T >
Array5< T >::Array5( const Array5 &ar )
    : elem_ { nullptr }, count_ { 0 }, capacity_ { 0 } {
  Array5 tmp( ar.begin( ), ar.end( ) );
  swap( tmp );
}

template < typename T >
Array5< T >::Array5( Array5 &&ar ) {
  swap( ar );
  ar.elem_ = nullptr;
}

template < typename T >
Array5< T > &Array5< T >::operator=( const Array5 &ar ) {
  if ( static_cast< void * >( this ) != static_cast< void * >( ar ) ) {
    Array5< T > tmp( ar );
    swap( tmp );
  }
  return *this;
}

template < typename T >
Array5< T > &Array5< T >::operator=( Array5 &&ar ) {
  if ( static_cast< void * >( this ) != static_cast< void * >( ar ) ) {
    swap( ar );
    delete[] ar.elem_;
    ar.elem_ = nullptr;
  }
}

template < typename T >
typename Array5< T >::iterator Array5< T >::begin( ) {
  return elem_;
}

template < typename T >
typename Array5< T >::const_iterator Array5< T >::begin( ) const {
  return elem_;
}

template < typename T >
typename Array5< T >::iterator Array5< T >::end( ) {
  return elem_ + count_;
}

template < typename T >
typename Array5< T >::const_iterator Array5< T >::end( ) const {
  return elem_ + count_;
}

template < typename T >
typename Array5< T >::size_type Array5< T >::size( ) const {
  return count_;
}

template < typename T >
typename Array5< T >::size_type Array5< T >::capacity( ) const {
  return capacity_;
}

template < typename T >
void Array5< T >::resize( ) {
  value_type *t = new value_type[ capacity_ * 2 ] { T( ) };
  std::copy( begin( ), end( ), t );
  std::swap( elem_, t );
  capacity_ *= 2;
}

template < typename T >
bool Array5< T >::empty( ) const {
  return count_ == 0;
}

template < typename T >
typename Array5< T >::reference Array5< T >::operator[](
    Array5::size_type ind ) {
  rangecheck( ind );
  return elem_[ ind ];
}

template < typename T >
typename Array5< T >::const_reference Array5< T >::operator[](
    Array5::size_type ind ) const {
  rangecheck( ind );
  return elem_[ ind ];
}

template < typename T >
typename Array5< T >::reference Array5< T >::back( ) {
  rangecheck( count_ - 1 );
  return *( elem_ + count_ - 1 );
}

template < typename T >
typename Array5< T >::const_reference Array5< T >::back( ) const {
  rangecheck( count_ - 1 );
  return *( elem_ + count_ - 1 );
}

template < typename T >
void Array5< T >::push_back( const Array5::value_type &v ) {
  if ( count_ + 1 == capacity_ ) resize( );
  elem_[ count_++ ] = v;
}

template < typename T >
void Array5< T >::pop_back( ) {
  if ( !empty( ) ) --count_;
}

template < typename T >
void Array5< T >::clear( ) {
  count_ = 0;
}

template < typename T >
void Array5< T >::swap( Array5 &oth ) {
  std::swap( elem_, oth.elem_ );
  std::swap( capacity_, oth.capacity_ );
  std::swap( count_, oth.count_ );
}

template < typename T >
Array5< T > &Array5< T >::operator+=( const Array5 &ar ) {
  for ( int i = 0; i < std::min( count_, ar.count_ ); ++i ) {
    ( *this )[ i ] += ar[ i ];
  }
  return *this;
}

template < typename T >
Array5< T > &Array5< T >::operator-=( const Array5 &ar ) {
  for ( int i = 0; i < std::min( count_, ar.count_ ); ++i ) {
    ( *this )[ i ] -= ar[ i ];
  }
  return *this;
}

template < typename T >
Array5< T > &Array5< T >::operator*=( const Array5 &ar ) {
  for ( int i = 0; i < std::min( count_, ar.count_ ); ++i ) {
    ( *this )[ i ] *= ar[ i ];
  }
  return *this;
}

template < typename T >
Array5< T > &Array5< T >::operator/=( const Array5 &ar ) {
  for ( int i = 0; i < std::min( count_, ar.count_ ); ++i ) {
    ( *this )[ i ] /= ar[ i ];
  }
  return *this;
}

template < typename T >
void Array5< T >::rangecheck( Array5::size_type idx ) const {
  if ( !( 0 <= idx && idx < count_ ) )
    throw std::out_of_range( "OUT OF RANGE" );
}

// friend
template < typename T >
std::ostream &operator<<( std::ostream &out, const Array5< T > &ar ) {
  std::copy( ar.begin( ), ar.end( ), std::ostream_iterator< T >( out, " " ) );
  return out;
}

template < typename T >
Array5< T > operator+( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  Array5< T > loc = ar1;
  loc += ar2;
  return loc;
}
template < typename T >
Array5< T > operator-( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  Array5< T > loc = ar1;
  loc -= ar2;
  return loc;
}
template < typename T >
Array5< T > operator*( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  Array5< T > loc = ar1;
  loc *= ar2;
  return loc;
}
template < typename T >
Array5< T > operator/( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  Array5< T > loc = ar1;
  loc /= ar2;
  return loc;
}

template < typename T >
std::istream &operator>>( std::istream &in, Array5< T > &ar ) {
  T t;
  in >> t;
  ar.push_back( t );
  return in;
}

template < typename T >
bool operator==( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  if ( ar1.count_ != ar2.count_ )
    return false;
  else {
    for ( int i = 0; i < ar1.count_; ++i ) {
      if ( ar1[ i ] != ar2[ i ] ) return false;
    }
  }
  return true;
}

template < typename T >
bool operator!=( const Array5< T > &ar1, const Array5< T > &ar2 ) {
  return !( ar1 == ar2 );
}

#endif  // ARRAY5_H
