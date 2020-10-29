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
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;
  // размеры
  size_type size( ) const;
  bool empty( ) const;
  size_type capacity( ) const;
  void resize( size_type new_size );
  void reserve( size_type new_size );
  // доступ к элементам
  reference operator[]( size_type idx );
  const_reference operator[]( size_type idx ) const;
  reference front( );
  const_reference front( ) const;
  // reference back( ) { return elem_[ size( ) - 1 ]; }
  reference back( );
  // const_reference back( ) const { return elem_[ size( ) - 1 ]; }
  const_reference back( ) const;
  // методы-модификаторы
  void push_back( const value_type& v );
  void pop_back( );
  void clear( );
  void swap( DynamicArray& da );
  void assign( const value_type& v );  // заполнить массив

 private:
  static const int MINSIZE = 10;
  size_type size_;    // отвечает за текущий размер
  size_type count_;   // отвечает за весь размер
  value_type* elem_;  // сами данные
};

#endif // DYNAMICARRAY_H
