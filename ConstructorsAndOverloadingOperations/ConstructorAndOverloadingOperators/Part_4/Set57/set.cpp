#include "set.h"

#include <iostream>

Set::Set( const Bitstring37B& set ) : set_( set ) {}

void Set::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Set::ToString( ) const { return set_.ToString( ); }

Set& Set::operator+=( const Set& oth ) {
  set_ = ( set_ | oth.set_ );
  return *this;
}

Set& Set::operator-=( const Set& oth ) {
  set_ = ( set_ ^ oth.set_ );
  return *this;
}

Set& Set::operator*=( const Set& oth ) {
  set_ = ( set_ & oth.set_ );
  return *this;
}

int Set::Count( ) {
  std::string set = set_.ToString( );
  int count = 0;
  for ( char el : set ) {
    if ( el == '1' ) ++count;
  }
  return count;
}

Set operator+( const Set& set1, const Set& set2 ) {
  Set loc = set1;
  loc += set2;
  return loc;
}

Set operator-( const Set& set1, const Set& set2 ) {
  Set loc = set1;
  loc -= set2;
  return loc;
}

Set operator*( const Set& set1, const Set& set2 ) {
  Set loc = set1;
  loc *= set2;
  return loc;
}
