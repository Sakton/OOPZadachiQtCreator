#ifndef ARRAY25_H
#define ARRAY25_H
#include <memory>

// TODO tasks 25, 27, 29

class ArrayGeneral {
 public:
  // type define
  using value_type = int32_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  // sz
  using size_type = int16_t;
  // ctor/dtor/cpu
  ArrayGeneral( size_type begInd, size_type endInd, const value_type &dt = 0 );
  ArrayGeneral( const_iterator beg, const_iterator end, size_type startInd );
  //~ArrayGeneral( ); не нужен так как unique_ptr
  ArrayGeneral( const ArrayGeneral &oth );
  ArrayGeneral( ArrayGeneral &&oth );
  ArrayGeneral &operator=( const ArrayGeneral &oth );
  ArrayGeneral &operator=( ArrayGeneral &&oth );

  // iterators
  const_iterator begin( ) const;
  const_iterator end( ) const;
  iterator begin( );
  iterator end( );

  // indexes
  const_reference operator[]( size_type idx ) const;
  reference operator[]( size_type idx );

  // modify
  void swap( ArrayGeneral &oth );

  // non modific
  value_type min( );
  value_type max( );
  value_type midleArifvetic( );
  const_iterator findElem( const value_type &el );
  void sort( );
  void permutation( );

  // sizes
  size_type size( ) const;

  // operations this
  ArrayGeneral &operator+=( const ArrayGeneral &oth );
  ArrayGeneral &operator-=( const ArrayGeneral &oth );
  ArrayGeneral &operator*=( const ArrayGeneral &oth );
  ArrayGeneral &operator/=( const ArrayGeneral &oth );
  // num /const value_type &num - заготовка под шаблон
  ArrayGeneral &operator+=( const value_type &num );
  ArrayGeneral &operator-=( const value_type &num );
  ArrayGeneral &operator*=( const value_type &num );
  ArrayGeneral &operator/=( const value_type &num );

  // friend
  friend const ArrayGeneral operator+( const ArrayGeneral &lhs, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator-( const ArrayGeneral &lhs, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator*( const ArrayGeneral &lhs, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator/( const ArrayGeneral &lhs, const ArrayGeneral &rhs );

  friend const ArrayGeneral operator+( const ArrayGeneral &lhs, const value_type &num );
  friend const ArrayGeneral operator-( const ArrayGeneral &lhs, const value_type &num );
  friend const ArrayGeneral operator*( const ArrayGeneral &lhs, const value_type &num );
  friend const ArrayGeneral operator/( const ArrayGeneral &lhs, const value_type &num );

  friend const ArrayGeneral operator+( const value_type &num, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator-( const value_type &num, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator*( const value_type &num, const ArrayGeneral &rhs );
  friend const ArrayGeneral operator/( const value_type &num, const ArrayGeneral &rhs );

 private:
  size_type index( size_type ind ) const;
  size_type begIndex( ) const;
  size_type endIndex( ) const;
  void validIndex( size_type ind ) const;
  void validSize( const ArrayGeneral &oth ) const;

 private:
  size_type begIndex_;
  size_type endIndex_;
  size_type count_;
  std::unique_ptr< value_type[] > date_;
};

#endif // ARRAY25_H
