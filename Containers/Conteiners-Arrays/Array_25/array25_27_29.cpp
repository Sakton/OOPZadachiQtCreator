#include "array25_27_29.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdexcept>

ArrayGeneral::ArrayGeneral( size_type begInd, size_type endInd, const value_type& dt )
    : begIndex_ { begInd },
      endIndex_ { endInd },
      count_ { static_cast< size_type >( endInd - begInd ) },
      date_ { new value_type[ count_ ] } {
  for ( size_type i = begInd; i < endInd; ++i ) date_[ index( i ) ] = dt;
}

ArrayGeneral::ArrayGeneral( ArrayGeneral::const_iterator beg, ArrayGeneral::const_iterator end, ArrayGeneral::size_type startInd )
    : begIndex_ { startInd },
      endIndex_ { static_cast< size_type >( startInd + std::distance( beg, end ) ) },
      count_ { static_cast< size_type >( std::distance( beg, end ) ) },
      date_ { new value_type[ count_ ] } {
  std::copy( beg, end, begin( ) );
}

ArrayGeneral::ArrayGeneral( const ArrayGeneral& oth )
    : begIndex_ { oth.begIndex_ }, endIndex_ { oth.endIndex_ }, count_ { oth.count_ }, date_ { new value_type[ oth.count_ ] } {
  std::copy( oth.begin( ), oth.end( ), begin( ) );
}

ArrayGeneral::ArrayGeneral( ArrayGeneral&& oth ) : begIndex_ { 0 }, endIndex_ { 0 }, count_ { 0 }, date_ { nullptr } {
  std::cout << "move_ctor=" << std::endl;
  swap( oth );
}

ArrayGeneral& ArrayGeneral::operator=( const ArrayGeneral& oth ) {
  if ( this != &oth ) {
    ArrayGeneral tmp = oth;
    swap( tmp );
  }
  return *this;
}

ArrayGeneral& ArrayGeneral::operator=( ArrayGeneral&& oth ) {
  std::cout << "move_op=" << std::endl;
  if ( this != &oth ) {
    swap( oth );
  }
  return *this;
}

ArrayGeneral::const_iterator ArrayGeneral::begin( ) const { return date_.get( ); }

ArrayGeneral::const_iterator ArrayGeneral::end( ) const { return date_.get( ) + count_; }

ArrayGeneral::iterator ArrayGeneral::begin( ) {
  return const_cast< ArrayGeneral::iterator >( static_cast< const ArrayGeneral& >( *this ).begin( ) );
}

ArrayGeneral::iterator ArrayGeneral::end( ) {
  return const_cast< ArrayGeneral::iterator >( static_cast< const ArrayGeneral& >( *this ).end( ) );
}

ArrayGeneral::const_reference ArrayGeneral::operator[]( ArrayGeneral::size_type idx ) const {
  validIndex( idx );
  return date_[ idx ];
}

ArrayGeneral::reference ArrayGeneral::operator[]( ArrayGeneral::size_type idx ) {
  return const_cast< ArrayGeneral::reference >( static_cast< const ArrayGeneral& >( *this )[ idx ] );
}

void ArrayGeneral::swap( ArrayGeneral& oth ) {
  std::swap( begIndex_, oth.begIndex_ );
  std::swap( endIndex_, oth.endIndex_ );
  std::swap( count_, oth.count_ );
  //  std::swap( date_, oth.date_ );
  date_.swap( oth.date_ );
}

ArrayGeneral::value_type ArrayGeneral::min( ) { return *std::min_element( begin( ), end( ) ); }

ArrayGeneral::value_type ArrayGeneral::max( ) { return *std::max_element( begin( ), end( ) ); }

ArrayGeneral::value_type ArrayGeneral::midleArifvetic( ) {
  return std::accumulate( begin( ), end( ), 0, []( ArrayGeneral::value_type acc, ArrayGeneral::value_type el ) { return acc + el; } ) /
         size( );
}

ArrayGeneral::const_iterator ArrayGeneral::findElem( const ArrayGeneral::value_type& el ) { return std::find( begin( ), end( ), el ); }

void ArrayGeneral::sort( ) { std::sort( begin( ), end( ) ); }

void ArrayGeneral::permutation( ) { std::random_shuffle( begin( ), end( ) ); }

ArrayGeneral::size_type ArrayGeneral::size( ) const { return count_; }

ArrayGeneral& ArrayGeneral::operator+=( const ArrayGeneral& oth ) {
  validSize( oth );
  ArrayGeneral loc( oth );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::plus<>( ) );
  swap( loc );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator-=( const ArrayGeneral& oth ) {
  validSize( oth );
  ArrayGeneral loc( oth );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::minus<>( ) );
  swap( loc );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator*=( const ArrayGeneral& oth ) {
  validSize( oth );
  ArrayGeneral loc( oth );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::multiplies<>( ) );
  swap( loc );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator/=( const ArrayGeneral& oth ) {
  validSize( oth );
  ArrayGeneral loc( oth );
  std::transform( begin( ), end( ), oth.begin( ), loc.begin( ), std::divides<>( ) );
  swap( loc );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator+=( const ArrayGeneral::value_type& num ) {
  using namespace std::placeholders;
  ArrayGeneral tmp( begIndex( ), endIndex( ), 0 );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::plus<>( ), _1, num ) );
  swap( tmp );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator-=( const ArrayGeneral::value_type& num ) {
  using namespace std::placeholders;
  ArrayGeneral tmp( begIndex( ), endIndex( ), 0 );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::minus<>( ), _1, num ) );
  swap( tmp );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator*=( const ArrayGeneral::value_type& num ) {
  using namespace std::placeholders;
  ArrayGeneral tmp( begIndex( ), endIndex( ), 0 );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::multiplies<>( ), _1, num ) );
  swap( tmp );
  return *this;
}

ArrayGeneral& ArrayGeneral::operator/=( const ArrayGeneral::value_type& num ) {
  using namespace std::placeholders;
  ArrayGeneral tmp( begIndex( ), endIndex( ), 0 );
  std::transform( begin( ), end( ), tmp.begin( ), std::bind( std::divides<>( ), _1, num ) );
  swap( tmp );
  return *this;
}

ArrayGeneral::size_type ArrayGeneral::index( ArrayGeneral::size_type ind ) const {
  validIndex( ind );
  return ind - begIndex_;
}

ArrayGeneral::size_type ArrayGeneral::begIndex( ) const { return begIndex_; }

ArrayGeneral::size_type ArrayGeneral::endIndex( ) const { return endIndex_; }

void ArrayGeneral::validIndex( ArrayGeneral::size_type ind ) const {
  if ( ind < begIndex_ || endIndex_ <= ind ) throw std::out_of_range( "OUT OF RANGE" );
}

void ArrayGeneral::validSize( const ArrayGeneral& oth ) const {
  if ( size( ) != oth.size( ) ) throw std::runtime_error( "ERROR SIZE ==" );
}

const ArrayGeneral operator+( const ArrayGeneral& lhs, const ArrayGeneral& rhs ) {
  ArrayGeneral loc = lhs;
  loc += rhs;
  return loc;
}
const ArrayGeneral operator-( const ArrayGeneral& lhs, const ArrayGeneral& rhs ) {
  ArrayGeneral loc = lhs;
  loc -= rhs;
  return loc;
}
const ArrayGeneral operator*( const ArrayGeneral& lhs, const ArrayGeneral& rhs ) {
  ArrayGeneral loc = lhs;
  loc *= rhs;
  return loc;
}
const ArrayGeneral operator/( const ArrayGeneral& lhs, const ArrayGeneral& rhs ) {
  ArrayGeneral loc = lhs;
  loc /= rhs;
  return loc;
}

const ArrayGeneral operator+( const ArrayGeneral& lhs, const ArrayGeneral::value_type& num ) {
  ArrayGeneral loc = lhs;
  loc += num;
  return loc;
}
const ArrayGeneral operator-( const ArrayGeneral& lhs, const ArrayGeneral::value_type& num ) {
  ArrayGeneral loc = lhs;
  loc -= num;
  return loc;
}
const ArrayGeneral operator*( const ArrayGeneral& lhs, const ArrayGeneral::value_type& num ) {
  ArrayGeneral loc = lhs;
  loc *= num;
  return loc;
}
const ArrayGeneral operator/( const ArrayGeneral& lhs, const ArrayGeneral::value_type& num ) {
  ArrayGeneral loc = lhs;
  loc /= num;
  return loc;
}

const ArrayGeneral operator+( const ArrayGeneral::value_type& num, const ArrayGeneral& rhs ) { return rhs + num; }
const ArrayGeneral operator-( const ArrayGeneral::value_type& num, const ArrayGeneral& rhs ) { return rhs - num; }
const ArrayGeneral operator*( const ArrayGeneral::value_type& num, const ArrayGeneral& rhs ) { return rhs * num; }
const ArrayGeneral operator/( const ArrayGeneral::value_type& num, const ArrayGeneral& rhs ) { return rhs / num; }
