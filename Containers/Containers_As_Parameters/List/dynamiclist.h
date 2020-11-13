#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include <cstdint>
#include <stdexcept>

//элемент tail - концевой элемент, существует всегда, как пробка у бочка всегда
//ползет, зачем он нужен? чтобы правильно работали итераторы begin() < end()
//и упростит немножко класс
//
// классы исключений добавить
class NullNodeException : public std::exception {
  // exception interface
 public:
  explicit NullNodeException( const std::string& s ) : s_ { "NULL_NODE_POINTER " + s } {}
  const char* what( ) const override { return s_.c_str( ); }

 private:
  std::string s_;
};

//Список с пустым элементом

class DynamicList {
 public:
  // определения типов
  class Iterator;

  using value_type = int;
  using size_type = size_t;
  using iterator = Iterator;
  using const_iterator = const Iterator;

  // класс узел
 private:
  struct Node {
    Node( ) : item_ { }, next_ { nullptr }, prev_ { nullptr } {}

    explicit Node( const value_type& v ) : item_ { v }, next_ { nullptr }, prev_ { nullptr } {}

    value_type item_;
    Node* next_;
    Node* prev_;
  };

 public:
  // класс итератор
  class Iterator {
    friend class DynamicList;
    explicit Iterator( Node* el ) : elem_ { el } { };  // PRIVATE CTOR + FRIEND CLASS
   public:
    // ctor
    Iterator( ) : elem_ { nullptr } {}
    Iterator( const Iterator& oit ) : elem_ { oit.elem_ } {}
    // predicates
    bool operator==( const Iterator& oit );
    bool operator!=( const Iterator& oit );
    // behavior
    Iterator& operator++( );
    Iterator& operator--( );
    value_type& operator*( );
    Node* operator->( );
    Iterator operator++( int );
    Iterator operator--( int );

   private:
    Node* elem_;
  };

  // кострукторы/деструкторы/копирование/присваивание
  DynamicList( );
  explicit DynamicList( size_type n, const value_type& v = 0 );
  DynamicList( Iterator first, Iterator last );
  ~DynamicList( );
  DynamicList( const DynamicList& dl );
  DynamicList( DynamicList&& dl );
  DynamicList& operator=( const DynamicList& dl );
  DynamicList& operator=( DynamicList&& dl );
  // итераторы
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;
  // размеры
  size_type size( ) const;
  bool empty( ) const;
  //Доступ
  value_type& front( );
  value_type& back( );
  value_type& find( const value_type& v );
  //модификаторы
  void push_front( const value_type& v );
  void pop_front( );
  void push_back( const value_type& v );
  void pop_back( );
  void insert( Iterator it, const value_type& v );
  void erase( Iterator it );
  void erase( Iterator first, Iterator second );
  void remove( const value_type& v );
  void swap( DynamicList& dl );
  void clear( );
  void splice( DynamicList& dl );
  void splice( Iterator it, DynamicList& dl );
  void sort( );
  void merge( DynamicList& dl );

 private:
  int64_t count_;
  Node* tail_;
  Node* head_;
};

#endif  // DYNAMICLIST_H
