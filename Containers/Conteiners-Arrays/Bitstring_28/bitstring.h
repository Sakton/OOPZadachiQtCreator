#ifndef BITSTRING_H
#define BITSTRING_H
#include <memory>

class Bitstring {
 public:
  // type define
  using value_type = unsigned char;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  // sz
  using size_type = size_t;

  Bitstring( size_type n );
  Bitstring( const Bitstring& rhs );
  Bitstring( Bitstring&& rhs );
  Bitstring& operator=( const Bitstring& rhs );
  Bitstring& operator=( Bitstring&& rhs );

  // iterations
  const_iterator begin( ) const;
  const_iterator end( ) const;
  iterator begin( );
  iterator end( );

  // indexes
  const_reference operator[]( size_type idx ) const;
  reference operator[]( size_type idx );

  // operators
  Bitstring& operator&=( const Bitstring& rhs );
  Bitstring& operator|=( const Bitstring& rhs );
  Bitstring& operator^=( const Bitstring& rhs );
  Bitstring& operator~( );
  Bitstring& operator<<=( size_type n );
  Bitstring& operator>>=( size_type n );

  // friends
  friend const Bitstring operator&( const Bitstring& lhs, const Bitstring& rhs );
  friend const Bitstring operator|( const Bitstring& lhs, const Bitstring& rhs );
  friend const Bitstring operator^( const Bitstring& lhs, const Bitstring& rhs );
  friend const Bitstring operator~( const Bitstring& rhs );  // ?
  friend const Bitstring operator>>( const Bitstring& lhs, size_type n );
  friend const Bitstring operator<<( const Bitstring& lhs, size_type n );

  // cycle Shift
  Bitstring& cycleShiftLeft( size_type n );
  Bitstring& cycleShiftRight( size_type n );

  // size
  size_type size( ) const;

 private:
  void reverse( );
  void swap( Bitstring& oth );
  void validIndex( size_type idx ) const;
  void valiLenth( const Bitstring& oth ) const;
  void clear( );
  size_type index( size_type idx ) const;
  void validValue( const value_type v );

 private:
  size_type sz_;
  std::unique_ptr< value_type[] > data_;
};

#endif // BITSTRING_H
