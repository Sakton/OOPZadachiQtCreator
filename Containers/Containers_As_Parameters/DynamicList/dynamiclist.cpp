#include "dynamiclist.h"

bool DynamicList::Iterator::operator==( const DynamicList::Iterator& oit ) {
  return elem_ == oit.elem_;
}

bool DynamicList::Iterator::operator!=( const DynamicList::Iterator& oit ) {
  return !( *this == oit );
}

DynamicList::Iterator& DynamicList::Iterator::operator++( ) {
  // FIXME проверки и throw
  elem_ = elem_->next_;
  return *this;
}

DynamicList::Iterator& DynamicList::Iterator::operator--( ) {
  // FIXME проверки и throw
  elem_ = elem_->prev_;
  return *this;
}

DynamicList::value_type& DynamicList::Iterator::operator*( ) {
  return elem_->item_;
}

// DynamicList::Iterator & DynamicList::Iterator::operator++(int)
//{
//}

DynamicList::Node* DynamicList::Iterator::operator->( ) {
  // FIXME проверки и throw
  return elem_;
}
