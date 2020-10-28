#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cstdlib>

class DynamicArray
{
 public:
  // usings
  using value_type = double;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  // конструкторы/деструкторы/копирование
  explicit DynamicArray( size_type n = MINSIZE );
  explicit DynamicArray( iterator first, iterator last );
  DynamicArray( const DynamicArray& da );
  DynamicArray( DynamicArray&& da );
  ~DynamicArray( );
  DynamicArray& operator=( const DynamicArray& da );
  DynamicArray& operator=( DynamicArray&& da );
  // итераторы
  inline iterator begin( ) { return elem_; };
  inline const_iterator begin( ) const { return elem_; };
  inline iterator end( ) { return elem_ + count_; }
  inline const_iterator end( ) const { return elem_ + count_; };
  // размеры
  size_type size( );
  bool empty( );
  size_type capacity( );
  void resize( size_type new_size );

 private:
  static const int MINSIZE = 10;
  size_type size_;
  size_type count_;
  value_type* elem_;
};

#endif // DYNAMICARRAY_H
