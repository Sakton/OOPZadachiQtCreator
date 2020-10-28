#include "decimalnew.h"

#include <algorithm>
#include <iostream>

DecimalNew::DecimalNew( int n ) : number_ { nullptr }, count_ { 0 } {
  number_ = new Uch[ n ] { 0 };
  count_ = n;
}

DecimalNew::DecimalNew( int64_t num, bool ) : DecimalNew( ) {
  count_ = lenNumber( num );
  number_ = new Uch[ count_ ] { 0 };
  int i = 0;
  while ( num ) {
    ( *this )[ i++ ] = num % 10;
    num /= 10;
  }
  std::reverse( number_, number_ + count_ );
}

DecimalNew::DecimalNew( const std::string& str ) : DecimalNew( ) {
  count_ = str.size( );
  number_ = new Uch[ count_ ] { 0 };
  int i = 0;
  for ( char el : str ) {
    ( *this )[ i++ ] = el - '0';
  }
}

DecimalNew::~DecimalNew( ) { delete[] number_; }

DecimalNew::DecimalNew( const DecimalNew& dm ) {
  Uch* t = new Uch[ dm.count_ ] { 0 };
  std::copy( dm.number_, dm.number_ + dm.count_, t );
  delete[] number_;
  number_ = t;
  count_ = dm.count_;
}

DecimalNew& DecimalNew::operator=( const DecimalNew& dm ) {
  if ( this != &dm ) {
    Uch* t = new Uch[ dm.count_ ] { 0 };
    std::copy( dm.number_, dm.number_ + dm.count_, t );
    delete[] number_;
    number_ = t;
    count_ = dm.count_;
  }
  return *this;
}

DecimalNew::Uch& DecimalNew::operator[]( int index ) {
  if ( !number_ ) {
    std::cerr << "ERROR [] NULLPTR";
    exit( 1 );
  }
  if ( index < 0 || index >= count_ ) {
    std::cerr << "ERROR OUT OF RANGE INDEX = " << index;
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
    std::cerr << "ERROR OUT OF RANGE INDEX = " << index;
    exit( 1 );
  }
  return number_[ count_ - 1 - index ];
}

DecimalNew& DecimalNew::operator+=( const DecimalNew& dm ) {
  DecimalNew loc( std::max( count_, dm.count_ ) + 1 );
  for ( int i = 0; i < std::min( count_, dm.count_ ); ++i ) {
    if ( i > count_ )
      loc[ i ] = dm[ i ];
    else if ( i > dm.count_ )
      loc[ i ] = ( *this )[ i ];
    else
      loc[ i + 1 ] = ( *this )[ i ] + dm[ i ];
  }
  for ( int i = loc.count_ - 1; i > 0; --i ) {
    if ( loc[ i ] > OSNOVA ) {
      loc[ i ] -= OSNOVA;
      loc[ i - 1 ]++;
    }
  }
  if ( loc[ 0 ] == 0 ) --loc.count_;
  return *this = loc;
}

DecimalNew& DecimalNew::operator-=( const DecimalNew& dm ) {
  DecimalNew loc( std::max( count_, dm.count_ ) );
  for ( int i = 0; i < std::min( count_, dm.count_ ); ++i ) {
    if ( i > count_ )
      loc[ i ] = dm[ i ];
    else if ( i > dm.count_ )
      loc[ i ] = ( *this )[ i ];
    else
      loc[ i ] = ( *this )[ i ] - dm[ i ];
  }
  for ( int i = loc.count_ - 1; i > 0; --i ) {
    if ( loc[ i ] > OSNOVA ) {
      loc[ i ] += OSNOVA;
      loc[ i - 1 ]--;
    }
  }
  //уборка лидирующих нулей
  while ( loc.count_ > 1 && loc[ 0 ] == 0 ) {
    --loc.count_;
  }
  return *this = loc;
}

DecimalNew& DecimalNew::operator*=( const DecimalNew& dm ) {
  //последнее число в одной ячейке(2-значное)
  DecimalNew loc( count_ + dm.count_ - 1 );
  for ( int i = 0; i < std::max( count_, dm.count_ ); ++i ) {
    for ( int j = 0; j < std::min( count_, dm.count_ ); ++j ) {
      if ( count_ > dm.count_ ) {
        loc[ i + j ] += ( *this )[ i ] * dm[ j ];
      } else {
        loc[ i + j ] += dm[ i ] * ( *this )[ j ];
      }
    }
  }
  //переполнение по unsigned char в этом алгоритме !!!
  for ( int i = loc.count_ - 1; i > 0; --i ) {
    loc[ i - 1 ] += ( loc[ i ] / 10 );
    loc[ i ] %= OSNOVA;
  }
  //уборка лидирующих нулей
  return *this = loc;
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
