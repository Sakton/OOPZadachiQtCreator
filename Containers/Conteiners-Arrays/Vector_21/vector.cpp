#include "vector.h"

#include <iostream>
#include <new>

MY::Vector::Vector( Vector::size_type n, Vector::value_type k ) : count_ { n }, data_ { nullptr } {
  if ( n != 0 ) data_ = new value_type[ n ];
  for ( size_type i = 0; i < n; ++i ) data_[ i ] = k;
}

MY::Vector::Vector( const_iterator beg, const_iterator end ) : Vector( static_cast< size_type >( end - beg ), 0 ) {
  auto it = begin( );
  while ( beg != end ) *it++ = *beg++;
}

MY::Vector::~Vector( ) { delete[] data_; }

//копирование (раз правый вектор существует то он нормальный)
MY::Vector::Vector( const MY::Vector &vec ) : count_ { vec.size( ) }, data_ { new value_type[ vec.size( ) ] } {
  for ( size_type i = 0; i < vec.size( ); ++i ) ( *this )[ i ] = vec[ i ];
}

MY::Vector::Vector( MY::Vector &&vec ) : count_ { vec.count_ }, data_ { vec.data_ } { vec.data_ = nullptr; }

MY::Vector &MY::Vector::operator=( const MY::Vector &vec ) {
  if ( this != &vec ) {
    value_type *t = new value_type[ vec.size( ) ];
    for ( size_type i = 0; i < vec.size( ); ++i ) t[ i ] = vec.data_[ i ];
    count_ = vec.size( );
    delete[] data_;
    data_ = t;
  }
  return *this;
}

MY::Vector &MY::Vector::operator=( MY::Vector &&vec ) {
  if ( this != &vec ) {
    delete[] data_;
    data_ = vec.data_;
    count_ = vec.count_;
  }
  return *this;
}

MY::Vector::reference MY::Vector::operator[]( MY::Vector::size_type idx ) {
  //правило 3 майерс (не дублирование кода)
  return const_cast< MY::Vector::reference >( static_cast< const MY::Vector & >( *this )[ idx ] );
}

MY::Vector::const_reference MY::Vector::operator[]( MY::Vector::size_type idx ) const {
  if ( idx >= count_ ) throw std::out_of_range( "op[]" );
  return data_[ idx ];
}

MY::Vector::iterator MY::Vector::begin( ) { return data_; }

MY::Vector::size_type MY::Vector::size( ) const { return count_; }

bool MY::Vector::empty( ) const { return count_ == 0; }
