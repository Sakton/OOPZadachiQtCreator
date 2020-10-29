#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

class DynamicList {
 public:
  // определения типов
  using value_type = double;
  using size_type = size_t;
  //итераторы
  class Iterator;

  // кострукторы/деструкторы/копирование/присваивание
  DynamicList( );
  DynamicList( const value_type& v, size_type n = 1 );
  DynamicList( Iterator first, Iterator last );
  ~DynamicList( );
  DynamicList( const DynamicList& dl );
  DynamicList( DynamicList&& dl );
  DynamicList& operator=( const DynamicList& dl );
  DynamicList& operator=( DynamicList&& dl );
  //
};

class Iterator {};

#endif // DYNAMICLIST_H
