#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include <cstdint>

// классы исключений добавить

class Iterator;

class DynamicList {
 public:
  // определения типов
  using value_type = double;
  using size_type = size_t;

  // класс узел
 private:
  struct Node {
    Node( const value_type& v )
        : item_ { v }, next_ { nullptr }, prev_ { nullptr } {}
    Node( ) : item_ { }, next_ { nullptr }, prev_ { nullptr } {}

    value_type item_;
    Node* next_;
    Node* prev_;
  };

 public:
  // класс итератор
  class Iterator {
   public:
    friend class DynamicList;
    // ctor
    Iterator( ) : elem_ { nullptr } { };
    Iterator( const Iterator& oit ) : elem_ { oit.elem_ } {}
    // predicates
    bool operator==( const Iterator& oit );
    bool operator!=( const Iterator& oit );
    // behavior
    Iterator& operator++( );
    Iterator& operator--( );
    value_type& operator*( );
    Node* operator->( );
    Iterator& operator++( int );
    Iterator& operator--( int );

   private:
    Node* elem_;
  };
  // кострукторы/деструкторы/копирование/присваивание
  DynamicList( );
  DynamicList( const value_type& v, size_type n = 1 );
  DynamicList( Iterator first, Iterator last );
  ~DynamicList( );
  DynamicList( const DynamicList& dl );
  DynamicList( DynamicList&& dl );
  DynamicList& operator=( const DynamicList& dl );
  DynamicList& operator=( DynamicList&& dl );
  //итераторы
  // Iterator

 private:
  int64_t count_;
  Node* head_;
  Node* tail_;
  Iterator head_iterator_;
  Iterator tail_iterator_;
};

#endif  // DYNAMICLIST_H
