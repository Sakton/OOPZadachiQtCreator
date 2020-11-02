#ifndef ARRAY_H
#define ARRAY_H
#include <cstdlib>
#include <iostream>
#include <stdexcept>

// pre-declaration class for pre declaration friendly funk
template < typename T, std::size_t First, std::size_t Second >
class Array;
// friendly function pre-declaration
template < typename T, std::size_t First, std::size_t Second >
std::ostream &operator<<( std::ostream &out,
                          const Array< T, First, Second > &ar );

template < typename T, std::size_t F, std::size_t S >
std::istream &operator>>( std::ostream &in, Array< T, F, S > );

// class
template < typename T, std::size_t First = 0, std::size_t Second = 100 >
class Array {
 public:
  // types definition
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  static const size_type l_index = First;
  static const size_type r_index = Second;
  static constexpr size_type static_size = ( Second - First );
  // iterators type definition
  using iterator = value_type *;
  using const_iterator = const value_type *;

  //*******************
  Array( );

  // sizes
  size_type leftInterval( );
  size_type rightInterval( );
  size_type size( );

  // behaviour
  reference operator[]( size_type index );
  const_reference operator[]( size_type index ) const;

  // iterator behavior
  iterator begin( );
  iterator end( );
  const_iterator begin( ) const;
  const_iterator end( ) const;
  //  iterator next( );
  //  const_iterator next( ) const;
  //  iterator prev( );
  //  const_iterator prev( ) const;
  //  reference operator*( );
  //  const_reference operator*( ) const;
  //  iterator operator++( );
  //  const_iterator operator++( ) const;
  //  iterator operator++( int );
  //  const_iterator operator++( int ) const;
  //  iterator operator--( );
  //  const_iterator operator--( ) const;
  //  iterator operator--( int );
  //  const_iterator operator--( int ) const;

  // friend
  // variant 1
  //  friend std::ostream &operator<<<>( std::ostream &out,
  //                                     const Array< T, First, Second > &ar );
  // variant 2
  friend std::ostream &operator<<< T, First, Second >( std::ostream &out,
                                                       const Array &ar );

  std::ostream &print( std::ostream &out ) const;

 private:
  bool rangeIndex( const size_type &index );

 private:
  T elements_[ static_size ];
};

// functions
template < typename T, std::size_t F, std::size_t S >
std::ostream &otherPrintFunc( std::ostream &out, Array< T, F, S > &ar ) {
  return ar.print( out );
}

template < typename T, std::size_t F, std::size_t S >
std::ostream &operator<<( std::ostream &out, const Array< T, F, S > &ar ) {
  return ar.print( out );
}

//****

template < typename T, std::size_t First, std::size_t Second >
bool Array< T, First, Second >::rangeIndex( const size_type &index ) {
  if ( !( Array< T, First, Second >::l_index <= index &&
          index <= Array< T, First, Second >::r_index ) ) {
    throw std::range_error( "ERROR_RANGE" );
  }
}

template < typename T, std::size_t First, std::size_t Second >
Array< T, First, Second >::Array( ) : elements_ { } {}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::size_type
Array< T, First, Second >::leftInterval( ) {
  return Array< T, First, Second >::l_index;
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::size_type
Array< T, First, Second >::rightInterval( ) {
  return Array< T, First, Second >::r_index;
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::size_type
Array< T, First, Second >::size( ) {
  return Array< T, First, Second >::static_size;
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::reference
Array< T, First, Second >::operator[]( Array::size_type index ) {
  rangeIndex( index );
  return elements_[ index - leftInterval( ) ];
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::const_reference
Array< T, First, Second >::operator[]( Array::size_type index ) const {
  rangeIndex( index );
  return elements_[ index - leftInterval( ) ];
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::iterator
Array< T, First, Second >::begin( ) {
  return elements_;
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::iterator Array< T, First, Second >::end( ) {
  return elements_ + size( );
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::const_iterator
Array< T, First, Second >::begin( ) const {
  return elements_;
}

template < typename T, std::size_t First, std::size_t Second >
typename Array< T, First, Second >::const_iterator
Array< T, First, Second >::end( ) const {
  return elements_ + size( );
}

template < typename T, std::size_t First, std::size_t Second >
std::ostream &Array< T, First, Second >::print( std::ostream &out ) const {
  for ( T elem : elements_ ) {
    std::cout << elem << " ";
  }
  return out;
}

#endif  // ARRAY_H
