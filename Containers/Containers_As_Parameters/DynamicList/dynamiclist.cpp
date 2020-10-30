#include "dynamiclist.h"

#include <iostream>

bool DynamicList::Iterator::operator==( const DynamicList::Iterator& oit ) {
  return elem_ == oit.elem_;
}

bool DynamicList::Iterator::operator!=( const DynamicList::Iterator& oit ) {
  return !( *this == oit );
}

DynamicList::Iterator& DynamicList::Iterator::operator++( ) {
  if ( elem_ == nullptr ) throw NullNodeException( "operator++( )" );
  elem_ = elem_->next_;
  return *this;
}

DynamicList::Iterator& DynamicList::Iterator::operator--( ) {
  if ( elem_ == nullptr ) throw NullNodeException( "operator--( )" );
  elem_ = elem_->prev_;
  return *this;
}

DynamicList::value_type& DynamicList::Iterator::operator*( ) {
  return elem_->item_;
}

DynamicList::Node* DynamicList::Iterator::operator->( ) {
  if ( elem_ == nullptr ) throw NullNodeException( "operator->( )" );
  return elem_;
}

DynamicList::Iterator DynamicList::Iterator::operator++( int ) {
  if ( elem_ == nullptr ) throw NullNodeException( "operator++( )" );
  Iterator res = *this;
  elem_ = elem_->next_;
  return res;
}

DynamicList::Iterator DynamicList::Iterator::operator--( int ) {
  if ( elem_ == nullptr ) throw NullNodeException( "operator--( )" );
  Iterator res = *this;
  elem_ = elem_->prev_;
  return res;
}

DynamicList::DynamicList( )
    : count_ { 0 }, tail_ { nullptr }, head_ { nullptr } {}

DynamicList::DynamicList( const DynamicList::value_type& v,
                          DynamicList::size_type n )
    : DynamicList( ) {
  for ( size_type i = 0; i < n; ++i ) {
  }
}

DynamicList::DynamicList( DynamicList::Iterator first,
                          DynamicList::Iterator last )
    : DynamicList { } {}

DynamicList::~DynamicList( ) {
  std::cout << "destructor" << std::endl;
  Node* delNode = head_;
  Node* cur = head_;
  while ( cur != tail_ ) {
    cur = cur->next_;
    delete delNode;
    delNode = cur;
    --count_;
  }
  delete delNode;
}

DynamicList::Iterator DynamicList::begin( ) {
  if ( !head_ ) throw NullNodeException( "begin( )" );
  return Iterator( head_ );
}

DynamicList::Iterator DynamicList::begin( ) const {
  if ( !head_ ) throw NullNodeException( "begin( )" );
  return Iterator( head_ );
}

DynamicList::Iterator DynamicList::end( ) { return Iterator( tail_->next_ ); }

DynamicList::Iterator DynamicList::end( ) const {
  return Iterator( tail_->next_ );
}

DynamicList::size_type DynamicList::size( ) const { return count_; }

bool DynamicList::empty( ) const { return head_ == tail_; }

DynamicList::value_type& DynamicList::front( ) { return *begin( ); }

DynamicList::value_type& DynamicList::back( ) {
  Iterator it = end( );
  --it;
  return *it;
}

void DynamicList::push_back( const DynamicList::value_type& v ) {
  Node* t = new Node( v );
  if ( head_ == nullptr && tail_ == nullptr ) {
    head_ = tail_ = t;
  } else {
    tail_->next_ = t;
    t->prev_ = tail_;
    tail_ = t;
  }
  ++count_;
}

void DynamicList::pop_back( ) {
  Node* dlt = tail_;
  if ( !tail_ ) throw NullNodeException( "pop_back( )" );
  if ( tail_->prev_ ) {  //пока есть предыдущий элемент
    tail_->prev_->next_ = tail_->next_;
    tail_ = tail_->prev_;
  } else if ( tail_->prev_ == nullptr ) {  //элемент последний, тогда он же и
                                           //головной, его надо обнулить
    head_ = nullptr;
    tail_ = nullptr;
  }
  --count_;
  delete dlt;
}
