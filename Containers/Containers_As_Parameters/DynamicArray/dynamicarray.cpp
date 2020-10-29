#include "dynamicarray.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

DynamicArray::DynamicArray( size_type n ) try : size_ { n }
, count_ { n }, elem_ { new value_type[ n ] { 0 } } {}
catch ( std::bad_alloc &e ) {
  std::cerr << e.what( ) << std::endl;
}
catch ( ... ) {
  std::cerr << "other except ctor1" << std::endl;
}

DynamicArray::DynamicArray( iterator first, iterator last ) try
    : size_( last - first ),
      count_( last - first ),
      elem_ {
  new value_type[ last - first ] { 0 }
}
{
  value_type *el = elem_;
  value_type *tm = first;
  while ( tm != last ) {
    *el++ = *tm++;
  }
  // std::copy( first, last, elem_ );
}
catch ( std::bad_alloc &e ) {
  std::cerr << e.what( ) << std::endl;
}
catch ( ... ) {
  std::cerr << "other except ctor2" << std::endl;
}

DynamicArray::DynamicArray( const DynamicArray &da ) {
  value_type *tmp = new value_type[ da.size( ) ];
  std::copy( da.begin( ), da.end( ), tmp );
  size_ = da.size( );
  count_ = da.count_;
  delete[] elem_;
  elem_ = tmp;
}

DynamicArray::DynamicArray( DynamicArray &&da )
    : size_ { da.size_ }, count_ { da.count_ }, elem_ { da.elem_ } {
  da.elem_ = nullptr;
  da.size_ = 0;
  da.count_ = 0;
}

DynamicArray::~DynamicArray( ) { delete[] elem_; }

DynamicArray &DynamicArray::operator=( const DynamicArray &da ) {
  if ( this != &da ) {
    value_type *tmp = new value_type[ da.size( ) ];
    std::copy( da.begin( ), da.end( ), tmp );
    size_ = da.size( );
    count_ = da.count_;
    delete[] elem_;
    elem_ = tmp;
  }
  return *this;
}

DynamicArray &DynamicArray::operator=( DynamicArray &&da ) {
  if ( this != &da ) {
    delete[] elem_;
    elem_ = da.elem_;
    da.elem_ = nullptr;
    size_ = da.size( );
    da.size_ = 0;
    count_ = da.count_;
    da.count_ = 0;
  }
  return *this;
}

DynamicArray::iterator DynamicArray::begin( ) { return elem_; }

DynamicArray::const_iterator DynamicArray::begin( ) const { return elem_; }

DynamicArray::iterator DynamicArray::end( ) { return elem_ + size( ); }

DynamicArray::const_iterator DynamicArray::end( ) const {
  return elem_ + size( );
}

DynamicArray::size_type DynamicArray::size( ) const { return size_; }

DynamicArray::size_type DynamicArray::capacity( ) const { return count_; }

void DynamicArray::resize( DynamicArray::size_type new_size ) {
  if ( capacity( ) < new_size ) {
    value_type *t = new value_type[ std::max( new_size, capacity( ) * 2 ) ];
    std::copy( elem_, elem_ + size_, t );
    count_ = std::max( new_size, capacity( ) * 2 );
    delete[] elem_;
    elem_ = t;
  }
}

void DynamicArray::reserve( DynamicArray::size_type new_size ) {
  if ( new_size > count_ ) {
    resize( std::max( new_size, capacity( ) * 2 ) );
  }
}

DynamicArray::reference DynamicArray::operator[](
    DynamicArray::size_type idx ) {
  if ( idx < 0 || idx >= count_ )
    throw std::out_of_range( "ERROR [] index" + std::to_string( idx ) );
  return elem_[ idx ];
}

DynamicArray::const_reference DynamicArray::operator[](
    DynamicArray::size_type idx ) const {
  if ( idx < 0 || idx >= count_ )
    throw std::out_of_range( "ERROR [] index" + std::to_string( idx ) );
  return elem_[ idx ];
}

DynamicArray::reference DynamicArray::front( ) { return elem_[ 0 ]; }

DynamicArray::const_reference DynamicArray::front( ) const {
  return elem_[ 0 ];
}

DynamicArray::reference DynamicArray::back( ) { return elem_[ count_ - 1 ]; }

DynamicArray::const_reference DynamicArray::back( ) const {
  return elem_[ count_ - 1 ];
}

void DynamicArray::push_back( const DynamicArray::value_type &v ) {
  if ( count_ == size_ ) {
    resize( capacity( ) * 2 );
  }
  elem_[ size_++ ] = v;
}

void DynamicArray::pop_back( ) { --size_; }

void DynamicArray::clear( ) { size_ = 0; }
