#ifndef INTEGRAL_H
#define INTEGRAL_H
#include <cstdint>

class Integral
{
 public:
  // type define
  using value_type = int32_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using size_type = size_t;

  // ctor/dtor/cpy
  Integral( const value_type arr[], size_type n );
  Integral( const_iterator beg, const_iterator end );
  ~Integral( );
  Integral( const Integral& other );
  Integral( Integral&& other );
  const Integral& operator=( const Integral& other );
  const Integral& operator=( Integral&& other );

  // iterators
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;

  // indexes
  reference operator[]( size_type idx );
  const_reference operator[]( size_type idx ) const;

  // size
  size_type size( ) const;

  // modify
  void swap( Integral& other );

  // tasks
  double methodRectangle( ) const;
  double methodTrapecy( ) const;
  double methodSimpson( ) const;

 private:
  value_type* data_;
  size_type sz_;
};

#endif // INTEGRAL_H
