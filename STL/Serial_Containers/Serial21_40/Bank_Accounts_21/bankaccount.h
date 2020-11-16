#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <fstream>
#include <iostream>
#include <vector>

#include "account.h"

template < typename T, typename Container = std::vector< T > >
class BankAccounts;

template < typename T, typename Container >
std::ostream& operator<<( std::ostream& out, const BankAccounts< T, Container >& ba );

template < typename T, typename Container /* = std::vector< T >*/ >
class BankAccounts {
 public:
  BankAccounts( );

  void push_back( const T& el );
  bool save( std::ofstream& fout );
  bool read( std::ifstream& fin );

  friend std::ostream& operator<<< T, Container >( std::ostream& out, const BankAccounts< T, Container >& ba );

 private:
  Container container_;
};

template < typename T, typename Container >
BankAccounts< T, Container >::BankAccounts( ) : container_( ) {}

template < typename T, typename Container >
void BankAccounts< T, Container >::push_back( const T& el ) {
  container_.push_back( el );
}

template < typename T, typename Container >
bool BankAccounts< T, Container >::save( std::ofstream& fout ) {
  std::copy( container_.begin( ), container_.end( ), std::ostream_iterator< T >( fout ) );
  return fout.good( );
}

template < typename T, typename Container >
bool BankAccounts< T, Container >::read( std::ifstream& fin ) {
  std::copy( std::istream_iterator< T >( fin ), std::istream_iterator< T >( ), std::back_inserter( container_ ) );
  return fin.good( );
}

template < typename T, typename Container >
std::ostream& operator<<( std::ostream& out, const BankAccounts< T, Container >& ba ) {
  std::copy( ba.container_.begin( ), ba.container_.end( ), std::ostream_iterator< T >( out, "\n" ) );
  return out;
}

#endif  // BANKACCOUNT_H
