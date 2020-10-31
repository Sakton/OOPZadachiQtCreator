#ifndef LISTITERATORASMETHOD_H
#define LISTITERATORASMETHOD_H
//элемент tail - концевой элемент, существует всегда, как поплавок

class ListIteratorAsMethod
{
 public:
  // определения типов
  using value_type = double;
  using size_type = size_t;
  using reference = value_type &;
  using const_reference = const value_type &;

 private:
  struct Node {
    Node( ) : item_ { }, next_ { nullptr }, prev_ { nullptr } {}
    Node( const value_type &v )
        : item_ { v }, next_ { nullptr }, prev_ { nullptr } {}
    value_type item_;
    Node *next_;
    Node *prev_;
  };

 public:
  // определения типов
  using iterator = Node *;
  using const_iterator = const Node *;

  ListIteratorAsMethod( );
  ~ListIteratorAsMethod( );

  //итераторы
  iterator begin( );
  const_iterator begin( ) const;
  iterator end( );
  const_iterator end( ) const;
  iterator operator++( );
  const_iterator operator++( ) const;
  iterator operator++( int );
  const_iterator operator++( int ) const;
  iterator operator--( );
  const_iterator operator--( ) const;
  iterator operator--( int );
  const_iterator operator--( int ) const;
  reference operator*( );
  const_reference operator*( ) const;
  //размер
  size_type size( ) const;
  bool empty( ) const;

  //модификаторы
  void push_back( const value_type &v );
  void pop_back( );

 private:
  Node *head_;
  Node *tail_;
  //переменная указатель для итерирования
  mutable Node *
      curIteration_;  //ВАЖНО!!! переменная инкремента не может (не должна) быть
                      // const в константном обьекте, при реализации итератора
                      // через методы класса
  size_type count_;
};

#endif // LISTITERATORASMETHOD_H
