#ifndef DRIVERTEMPLATE_H
#define DRIVERTEMPLATE_H

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "account.h"

// TODO общий шаблон семейства задач 21-40
// общий шаблон решения семейства задач,
// меняются сами классы агрегатов
// лямбды для сортировок и выборок
// заполнялку нужно вытащить в классы

template < typename T, typename Container = std::vector< T > >
class DriverTemplate;

template < typename T, typename Container >
std::ostream& operator<<( std::ostream& out, const DriverTemplate< T, Container >& ba );

template < typename T, typename Container /* = std::vector< T >*/ >
class DriverTemplate {
 public:
  DriverTemplate( );

  void push_back( const T& el );
  bool save( std::ofstream& fout );
  bool read( std::ifstream& fin );

  template < typename Functor >
  std::queue< T > searchLinear_if( Functor fun );

  template < typename Functor >
  std::queue< T > searchBinary_if( Functor fun );

  template < typename Functor >
  void sort( Functor fun );

  void printDebug( );

  friend std::ostream& operator<<< T, Container >( std::ostream& out, const DriverTemplate< T, Container >& ba );

 private:
  Container container_;
};

template < typename T, typename Container >
template < typename Functor >
std::queue< T > DriverTemplate< T, Container >::searchLinear_if( Functor fun ) {
  auto res = std::find_if( container_.begin( ), container_.end( ), fun );
  std::queue< T > tempQueue;
  while ( res != container_.end( ) ) {
    if ( fun( *res ) ) {
      tempQueue.push( *res );
    }
    ++res;
  }
  return tempQueue;
}

template < typename T, typename Container >
template < typename Functor >
std::queue< T > DriverTemplate< T, Container >::searchBinary_if( Functor fun ) {
  // FIXME
}

template < typename T, typename Container >
template < typename Functor >
void DriverTemplate< T, Container >::sort( Functor fun ) {
  std::sort( container_.begin( ), container_.end( ), fun );
}

template < typename T, typename Container >
DriverTemplate< T, Container >::DriverTemplate( ) : container_( ) {}

template < typename T, typename Container >
void DriverTemplate< T, Container >::push_back( const T& el ) {
  container_.push_back( el );
}

template < typename T, typename Container >
bool DriverTemplate< T, Container >::save( std::ofstream& fout ) {
  for ( auto& el : container_ ) {
    fout.write( reinterpret_cast< char* >( &el ), sizeof( T ) );
  }
  return fout.good( );
}

template < typename T, typename Container >
bool DriverTemplate< T, Container >::read( std::ifstream& fin ) {
  while ( fin ) {
    T el { };
    fin.read( reinterpret_cast< char* >( &el ), sizeof( T ) );
    if ( fin.good( ) ) {
      container_.push_back( el );
    }
  }
  return fin.good( );
}

template < typename T, typename Container >
std::ostream& operator<<( std::ostream& out, const DriverTemplate< T, Container >& ba ) {
  std::copy( ba.container_.begin( ), ba.container_.end( ), std::ostream_iterator< T >( out, "\n" ) );
  return out;
}

#endif  // DRIVERTEMPLATE_H
