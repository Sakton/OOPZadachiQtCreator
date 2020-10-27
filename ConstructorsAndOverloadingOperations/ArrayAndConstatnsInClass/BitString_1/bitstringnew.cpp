#include "bitstringnew.h"

#include <iostream>

BitstringNew::BitstringNew( int sz ) : bitstr_ { nullptr }, count_ { 0 } {
  if ( sz < 0 || sz > SIZE ) {
    std::cout << "ERROR SIZE";
    exit( 1 );
  }
  bitstr_ = new Uch[ sz ] { 0 };
  count_ = sz;
}

BitstringNew::BitstringNew( const std::string &bitStr ) {}

BitstringNew::Uch &BitstringNew::operator[]( int index ) {}

int BitstringNew::getSIZE( ) { return SIZE; }
