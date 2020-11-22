#ifndef STACK7_H
#define STACK7_H
#include <algorithm>
#include <string>

template < typename T >
class Stack7 {
 public:
  // type definition
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = int;

  // ctor
  Stack7( );
  ~Stack7( );

  // sizes
  bool empty( ) const;

  // behaviour
  reference top( );
  const_reference top( ) const;
  void pop( );
  void push( const value_type &v );

  //
 private:
  void resize( );

 private:
  size_type top_;
  size_type capacity_;
  value_type *elem_;
  static constexpr int MIN_ELEMENTS = 10;
};

#endif // STACK7_H

template < typename T >
Stack7< T >::Stack7( )
    : top_ { 0 },
      capacity_ { MIN_ELEMENTS },
      elem_ { new value_type[ MIN_ELEMENTS ] } {}

template < typename T >
Stack7< T >::~Stack7( ) {
  delete[] elem_;
}

template < typename T >
bool Stack7< T >::empty( ) const {
  return top_ == 0;
}

template < typename T >
typename Stack7< T >::reference Stack7< T >::top( ) {
  return elem_[ top_ - 1 ];
}

template < typename T >
typename Stack7< T >::const_reference Stack7< T >::top( ) const {
  return elem_[ top_ ];
}

template < typename T >
void Stack7< T >::pop( ) {
  --top_;
}

template < typename T >
void Stack7< T >::push( const Stack7::value_type &v ) {
  if ( top_ + 1 == capacity_ ) {
    resize( );
  }
  elem_[ top_++ ] = v;
}

template < typename T >
void Stack7< T >::resize( ) {
  value_type *tmp = new value_type[ capacity_ * 2 ];
  std::copy( elem_, elem_ + top_, tmp );
  delete[] elem_;
  elem_ = tmp;
  capacity_ *= 2;
}
