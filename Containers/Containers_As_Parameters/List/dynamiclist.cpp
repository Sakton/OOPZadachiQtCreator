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
    : count_ { 0 }, tail_ { new Node }, head_ { tail_ } {}

DynamicList::DynamicList( const DynamicList::value_type& v,
                          DynamicList::size_type n )
    : DynamicList( ) {
  for ( size_type i = 0; i < n; ++i ) {
    push_back( v );
  }
}

DynamicList::DynamicList( DynamicList::Iterator first,
                          DynamicList::Iterator last )
    : DynamicList { } {
  while ( first != last ) {
    push_back( first->item_ );
    ++first;
  }
}

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

DynamicList::DynamicList( const DynamicList& dl ) {
  DynamicList tmp( dl.begin( ), dl.end( ) );
  *this = tmp;
}

DynamicList::DynamicList( DynamicList&& dl ) : DynamicList( ) {
  delete tail_;
  head_ = dl.head_;
  tail_ = dl.tail_;
  count_ = dl.count_;
  dl.head_ = dl.tail_ = nullptr;
  dl.count_ = 0;
}

DynamicList& DynamicList::operator=( const DynamicList& dl ) {
  //  if ( this != &dl ) {
  //    clear( );
  //    for ( Iterator it = dl.begin( ); it != dl.end( ); ++it ) {
  //      push_back( it->item_ );
  //    }
  //  }
  DynamicList tmp( dl );
  swap( tmp );
  return *this;
}

DynamicList::Iterator DynamicList::begin( ) {
  if ( !head_ ) throw NullNodeException( "begin( )" );
  return Iterator( head_ );
}

DynamicList::const_iterator DynamicList::begin( ) const {
  if ( !head_ ) throw NullNodeException( "begin( )" );
  return Iterator( head_ );
}

DynamicList::iterator DynamicList::end( ) { return Iterator( tail_ ); }

DynamicList::const_iterator DynamicList::end( ) const { return Iterator( tail_ ); }

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
  //вставка первого элемента - отдельная задача
  if ( head_ == tail_ ) {
    head_ = t;
    head_->next_ = head_->prev_ = tail_;
    tail_->prev_ = head_;
  } else {  //если уже что то есть вставляем в конец (перед tail)
    t->next_ = tail_;
    t->prev_ = tail_->prev_;
    tail_->prev_ = t;
    t->prev_->next_ = t;
  }
  ++count_;
}

void DynamicList::pop_back( ) {
  if ( !empty( ) ) {
    Node* delNode = tail_->prev_;
    if ( delNode == head_ ) {
      tail_->prev_ = head_->prev_;
      head_ = tail_;
    } else {
      tail_->prev_ = delNode->prev_;
      delNode->prev_->next_ = tail_;
    }
    delete delNode;
    --count_;
  }
}

void DynamicList::swap( DynamicList& dl ) {
  std::swap( head_, dl.head_ );
  std::swap( tail_, dl.tail_ );
  std::swap( count_, dl.count_ );
}

void DynamicList::clear( ) {
  Node* delNode = nullptr;
  Node* p = head_;
  while ( p != tail_ ) {
    delNode = p;
    p = p->next_;
    delete delNode;
    delNode = p;
    --count_;
  }
  head_ = tail_;
}
