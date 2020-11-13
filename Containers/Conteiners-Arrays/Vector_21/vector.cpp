#include "vector.h"

#include <iostream>
#include <new>
#include <numeric>

MY::Vector::Vector( Vector::size_type n, Vector::value_type k ) : count_ { n }, data_ { nullptr } {
  if ( n == 0 ) throw std::bad_alloc( );
  data_ = new value_type[ n ];
  for ( size_type i = 0; i < n; ++i ) data_[ i ] = k;
}

MY::Vector::Vector( const_iterator beg, const_iterator end ) : count_ { 0 }, data_ { nullptr } {
  if ( beg == end ) throw std::bad_alloc( );
  auto i = beg;
  while ( i != end ) {
    ++count_;
    ++i;
  }
  data_ = new value_type[ count_ ];
  std::copy( beg, end, data_ );
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
  if ( idx >= count_ ) throw std::out_of_range( "OUT OF RANGE" );
  return data_[ idx ];
}

MY::Vector::iterator MY::Vector::begin( ) { return const_cast< value_type * >( static_cast< const MY::Vector & >( *this ).begin( ) ); }

MY::Vector::iterator MY::Vector::end( ) { return const_cast< value_type * >( static_cast< const MY::Vector & >( *this ).end( ) ); }

MY::Vector::const_iterator MY::Vector::begin( ) const { return data_; }

MY::Vector::const_iterator MY::Vector::end( ) const { return data_ + count_; }

const MY::Vector &MY::Vector::operator+=( const MY::Vector &rhs ) {
  lessCount( rhs );
  Vector tmp( size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ), std::plus< MY::Vector::value_type >( ) );
  swap( tmp );
  return *this;
}

const MY::Vector &MY::Vector::operator-=( const MY::Vector &rhs ) {
  lessCount( rhs );
  Vector tmp( size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ), std::minus< MY::Vector::value_type >( ) );
  swap( tmp );
  return *this;
}

const MY::Vector &MY::Vector::operator*=( const MY::Vector &rhs ) {
  lessCount( rhs );
  Vector tmp( size( ) );
  std::transform( begin( ), end( ), rhs.begin( ), tmp.begin( ), std::multiplies< MY::Vector::value_type >( ) );
  swap( tmp );
  return *this;
}

void MY::Vector::swap( MY::Vector &v ) {
  std::swap( data_, v.data_ );
  std::swap( count_, v.count_ );
}

MY::Vector::size_type MY::Vector::size( ) const { return count_; }

bool MY::Vector::empty( ) const { return count_ == 0; }

double MY::Vector::euclidNorm( ) const {
  using namespace std::placeholders;
  return std::sqrt( std::inner_product( begin( ), end( ), begin( ), 0 ) );
}

void MY::Vector::lessCount( const MY::Vector &rhs ) {
  if ( size( ) != rhs.size( ) ) throw std::runtime_error( "ERROR SIZE" );
}

const MY::Vector MY::operator+( const MY::Vector &lhs, const MY::Vector &rhs ) {
  MY::Vector loc = lhs;
  loc += rhs;
  return loc;
}

const MY::Vector MY::operator-( const Vector &lhs, const Vector &rhs ) {
  MY::Vector loc = lhs;
  loc -= rhs;
  return loc;
}

bool MY::eqEuclidNorn( const Vector &lhs, const Vector &rhs ) { return std::fabs( lhs.euclidNorm( ) - rhs.euclidNorm( ) ) < 1e-2; }
