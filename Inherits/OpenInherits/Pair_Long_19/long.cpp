#include "long.h"

Long::Long( int f, int s ) : Pair( f, s ) {}

// Long &Long::operator+=( const Long &l ) {
//  setFirst( first( ) + second( ) );
//  setSecond( l.first( ) + l.second( ) );
//  return *this;
//}

Long &Long::operator-=( const Long &l ) {
  setFirst( first( ) - second( ) );
  setSecond( l.first( ) - l.second( ) );
  return *this;
}

Long &Long::operator*=( const Long &l ) {
  setFirst( first( ) * second( ) );
  setSecond( l.first( ) * l.second( ) );
  return *this;
}

Long operator-( const Long &l1, const Long &l2 ) {
  Long loc = l1;
  loc -= l2;
  return loc;
}

Long operator*( const Long &l1, const Long &l2 ) {
  Long loc = l1;
  loc *= l2;
  return loc;
}
