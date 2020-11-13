#ifndef LISTITERATORASMETHOD_H
#define LISTITERATORASMETHOD_H
//элемент tail - концевой элемент, существует всегда, как поплавок

class ListIteratorAsMethod {
 public:
  // определения типов
  using value_type = int;
  using size_type = size_t;
  using reference = value_type &;
  using const_reference = const value_type &;

 private:
  struct Node {
    friend class ListIteratorAsMethod;
    Node( ) : item_ { 0 }, next_ { nullptr }, prev_ { nullptr } {}
    Node( const value_type &v ) : item_ { v }, next_ { nullptr }, prev_ { nullptr } {}

    //    const_reference operator*( ) const { return item_; };
    //    reference operator*( ) { return item_; };

    value_type item_;
    Node *next_;
    Node *prev_;
  };

 public:
  // определения типов
  using iterator = Node *;
  using const_iterator = const Node *;
  //  using iterator = Node&;
  //  using const_iterator = const Node&;

  ListIteratorAsMethod( );
  ~ListIteratorAsMethod( );

  // итераторы
  // очень неудобно иметь встроенный итератор, нужно помнить много деталей
  // операторы ++ -- и тд, оператор == применяются к объекту, а на самом деле к
  // итератору. Сам итератор организован как отдельное поле с модификатором
  // mutable для изменения при константности обьекта
  // лучше организовать итератор как простто набор методов без перегрузок
  // операций
  // Оператор * применяется к самому обьекту, содержащему ноды
  // begin( ) например возвращает *Node, *begin( ) == **Node или чтоб смоделировать хоть примерно правильное
  // поведение *(*begin()) -> тогда оператор * примениться к самому обьекту Node, но это тоже не то поведение

  // TODO КАК РЕАЛИЗОВАТЬ ПРАВИЛЬНОЕ ПОВЕДЕНИЕ ???
  // методами класса

  //  iterator begin( );
  //  const_iterator begin( ) const;
  //  iterator end( );
  //  const_iterator end( ) const;
  //  iterator operator++( );
  //  const_iterator operator++( ) const;
  //  iterator operator++( int );
  //  const_iterator operator++( int ) const;
  //  iterator operator--( );
  //  const_iterator operator--( ) const;
  //  iterator operator--( int );
  //  const_iterator operator--( int ) const;
  //  reference operator*( );
  //  const_reference operator*( ) const;
  //  bool operator==( iterator it ) const;
  //  bool operator==( const_iterator it ) const;
  //  bool operator!=( const_iterator it ) const;
  //  bool operator!=( iterator it ) const;

  //  iterator next( );
  //  const_iterator next( ) const;
  //  iterator prev( );
  //  const_iterator prev( ) const;

  //размер
  size_type size( ) const;
  bool empty( ) const;

  //модификаторы
  void push_back( const value_type &v );
  void pop_back( );

 private:
  Node *head_;
  Node *tail_;                  //пустой элемент
                                //переменная указатель для итерирования
  mutable Node *curIteration_;  //ВАЖНО!!! переменная инкремента не может (не должна) быть
  // const в константном обьекте, при реализации итератора
  // через методы класса
  size_type count_;
};

#endif  // LISTITERATORASMETHOD_H
