#ifndef ARRAY_H
#define ARRAY_H

namespace MY {

class Array {
 public:
  // type defines
  using value_type = double;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  // sz
  using size_type = size_t;

  enum { SIZE = 10 };

  // ctor/dtor/cpu
  explicit Array( size_type n = SIZE, const value_type &d = 0 );
  Array( const_iterator beg, const_iterator end );
  ~Array( );
  Array( const Array &oth );
  Array( Array &&oth );
  const Array &operator=( const Array &oth );
  const Array &operator=( Array &&oth );

  // iterators
  const_iterator begin( ) const;
  const_iterator end( ) const;
  iterator begin( );
  iterator end( );

  // sizes
  size_type size( ) const;

  // indexes
  const_reference operator[]( size_type idx ) const;
  reference operator[]( size_type idx );

  // this operations
  const Array &operator+=( const Array &oth );
  const Array &operator-=( const Array &oth );
  const Array &operator*=( const Array &oth );
  const Array &operator/=( const Array &oth );

  // firends
  friend const Array operator+( const Array &lhs, const Array &rhs );
  friend const Array operator-( const Array &lhs, const Array &rhs );
  friend const Array operator*( const Array &lhs, const Array &rhs );
  friend const Array operator/( const Array &lhs, const Array &rhs );

  friend bool operator==( const Array &lhs, const Array &rhs );
  friend bool operator!=( const Array &lhs, const Array &rhs );

  // modify
  void swap( Array &oth );

 private:
  size_type sz_;
  value_type *data_;
};

}  // namespace MY

#endif  // ARRAY_H
