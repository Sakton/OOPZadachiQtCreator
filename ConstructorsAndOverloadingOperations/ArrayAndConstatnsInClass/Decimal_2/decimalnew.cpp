#include "decimalnew.h"

#include <algorithm>
#include <iostream>

DecimalNew::DecimalNew( int n ) : number_ { nullptr }, count_ { 0 } {
  number_ = new Uch[ n ] { 0 };
  count_ = n;
}

DecimalNew::DecimalNew( int64_t num, bool ) : DecimalNew( ) {
  count_ = lenNumber( num );
  number_ = new Uch[ count_ ];
  int i = 0;
  while ( num ) {
    ( *this )[ i++ ] = num % 10;
    num /= 10;
  }
  std::reverse( number_, number_ + count_ );
}

DecimalNew::DecimalNew( const std::string& str ) : DecimalNew( ) {
  count_ = str.size( );
  number_ = new Uch[ count_ ];
  int i = 0;
  for ( char el : str ) {
    ( *this )[ i++ ] = el - '0';
  }
}

DecimalNew::~DecimalNew( ) { delete[] number_; }

DecimalNew::Uch& DecimalNew::operator[]( int index ) {
  if ( !number_ ) {
    std::cerr << "ERROR [] NULLPTR";
    exit( 1 );
  }
  if ( index < 0 || index >= count_ ) {
    std::cerr << "ERROR OUT OF RANGE INDEX";
    exit( 1 );
  }
  return number_[ count_ - 1 - index ];
}

const DecimalNew::Uch& DecimalNew::operator[]( int index ) const {
  if ( !number_ ) {
    std::cerr << "ERROR [] NULLPTR";
    exit( 1 );
  }
  if ( index < 0 || index >= count_ ) {
    std::cerr << "ERROR OUT OF RANGE INDEX";
    exit( 1 );
  }
  return number_[ count_ - 1 - index ];
}

int DecimalNew::getSize( ) { return SIZE; }

int DecimalNew::lenNumber( int64_t num ) {
  int res = 0;
  while ( num ) {
    ++res;
    num /= 10;
  }
  return res;
}

std::ostream& operator<<( std::ostream& out, const DecimalNew& dm ) {
  std::reverse_copy( dm.number_, dm.number_ + dm.count_,
                     std::ostream_iterator< int >( out ) );
  return out;
}
