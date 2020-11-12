#include "listiteratorasmethod.h"

#include <stdexcept>

ListIteratorAsMethod::ListIteratorAsMethod( ) : head_ { new Node }, tail_ { head_ }, curIteration_ { head_ }, count_ { 0 } {}

ListIteratorAsMethod::~ListIteratorAsMethod( ) {
  iterator del = head_;
  head_ = head_->next_;
  while ( head_ != tail_ ) {
    delete del;
    del = head_;
    head_ = head_->next_;
  }
  delete tail_;
}

// FIXME проверки добавить

ListIteratorAsMethod::iterator ListIteratorAsMethod::begin( ) {
  if ( empty( ) ) throw std::runtime_error( "LIST EMPTY" );
  return curIteration_ = head_;
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::begin( ) const { return curIteration_ = head_; }

ListIteratorAsMethod::iterator ListIteratorAsMethod::end( ) { return tail_; }

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::end( ) const { return tail_; }

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator++( ) {
  curIteration_ = curIteration_->next_;
  return curIteration_;
  // return next( );
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator++( ) const {
  curIteration_ = curIteration_->next_;
  return curIteration_;
  // return next( );
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator++( int ) const {
  iterator t = curIteration_;
  curIteration_ = curIteration_->next_;
  // next( );
  return t;
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator++( int ) {
  iterator t = curIteration_;
  curIteration_ = curIteration_->next_;
  // next( );
  return t;
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator--( ) {
  return ( curIteration_ = curIteration_->prev_ );
  // return prev( );
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator--( ) const {
  return ( curIteration_ = curIteration_->prev_ );
  // return prev( );
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator--( int ) {
  iterator t = curIteration_;
  curIteration_ = curIteration_->prev_;
  // prev( );
  return t;
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator--( int ) const {
  iterator t = curIteration_;
  curIteration_ = curIteration_->prev_;
  // prev( );
  return t;
}

ListIteratorAsMethod::reference ListIteratorAsMethod::operator*( ) { return curIteration_->item_; }

ListIteratorAsMethod::const_reference ListIteratorAsMethod::operator*( ) const { return curIteration_->item_; }

bool ListIteratorAsMethod::operator==( ListIteratorAsMethod::iterator it ) const { return curIteration_ == it; }

bool ListIteratorAsMethod::operator==( ListIteratorAsMethod::const_iterator it ) const { return curIteration_ == it; }

bool ListIteratorAsMethod::operator!=( ListIteratorAsMethod::const_iterator it ) const { return !( curIteration_ == it ); }

bool ListIteratorAsMethod::operator!=( ListIteratorAsMethod::iterator it ) const { return !( curIteration_ == it ); }

// ListIteratorAsMethod::iterator ListIteratorAsMethod::next( ) {
//  return curIteration_ = curIteration_->next_;
//}

// ListIteratorAsMethod::const_iterator ListIteratorAsMethod::next( ) const {
//  return curIteration_ = curIteration_->next_;
//}

// ListIteratorAsMethod::iterator ListIteratorAsMethod::prev( ) {
//  return curIteration_ = curIteration_->prev_;
//}

// ListIteratorAsMethod::const_iterator ListIteratorAsMethod::prev( ) const {
//  return curIteration_ = curIteration_->prev_;
//}

ListIteratorAsMethod::size_type ListIteratorAsMethod::size( ) const { return count_; }

bool ListIteratorAsMethod::empty( ) const { return head_ == tail_; }

void ListIteratorAsMethod::push_back( const value_type &v ) {
  Node *t = new Node( v );
  if ( head_ == tail_ ) {
    head_ = t;
    tail_->prev_ = head_;
    head_->next_ = head_->prev_ = tail_;
    curIteration_ = head_;
  } else {
    t->next_ = tail_;
    t->prev_ = tail_->prev_;
    tail_->prev_ = t;
    t->prev_->next_ = t;
  }
  ++count_;
}

void ListIteratorAsMethod::pop_back( ) {
  Node *delNode = tail_->prev_;
  if ( delNode == head_ ) {
    head_ = tail_;
  } else {
    delNode->prev_->next_ = tail_;
    tail_->prev_ = delNode->prev_;
  }
  delete delNode;
  --count_;
}
