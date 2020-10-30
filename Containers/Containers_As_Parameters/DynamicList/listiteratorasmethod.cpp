#include "listiteratorasmethod.h"

ListIteratorAsMethod::ListIteratorAsMethod( )
    : head_ { new Node },
      tail_ { head_ },
      curIteration_ { head_ },
      count_ { 0 } {}

ListIteratorAsMethod::~ListIteratorAsMethod( ) {}

// FIXME проверки добавить

ListIteratorAsMethod::iterator ListIteratorAsMethod::begin( ) {
  return curIteration_;
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::begin( ) const {
  return curIteration_;
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::end( ) { return tail_; }

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::end( ) const {
  return tail_;
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator++( ) {
  return ( curIteration_ = curIteration_->next_ );
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator++( int ) {
  Node *t = curIteration_;
  curIteration_ = curIteration_->next_;
  return t;
}

ListIteratorAsMethod::iterator ListIteratorAsMethod::operator--( ) {
  return ( curIteration_ = curIteration_->prev_ );
}

ListIteratorAsMethod::const_iterator ListIteratorAsMethod::operator--( int ) {
  Node *t = curIteration_;
  curIteration_ = curIteration_->prev_;
  return t;
}

ListIteratorAsMethod::reference ListIteratorAsMethod::operator*( ) {
  return curIteration_->item_;
}

ListIteratorAsMethod::const_reference ListIteratorAsMethod::operator*( ) const {
  return curIteration_->item_;
}

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
