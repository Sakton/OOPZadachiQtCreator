#include "rational7.h"

#include <iostream>

const int Rational7::MAX = 0;

Rational7::Rational7( int n )
    : chislitel_ { nullptr },
      znamenatel_ { nullptr },
      chislitel_size_ { 0 },
      znamenatel_size_ { 0 } {
  if ( n < 0 || n > MAX ) {
    std::cout << "ERROR";
    exit( 1 );
  }
  chislitel_ = new UChar[ n ] { 0 };
  znamenatel_ = new UChar[ n ] { 0 };
}

Rational7::Rational7( const std::string &drob )
    : chislitel_ { nullptr },
      znamenatel_ { nullptr },
      chislitel_size_ { 0 },
      znamenatel_size_ { 0 } {
  uint64_t tmpIndex = drob.find( '/' );
  if ( tmpIndex != std::string::npos ) {
    std::string chisl( drob.substr( 0, tmpIndex ) );
    std::string znam( drob.substr( tmpIndex + 1, drob.size( ) ) );
    // debug
    std::cout << chisl << "/////" << znam << std::endl;
    // end debug
    chislitel_ = new UChar[ chisl.size( ) ];
    chislitel_size_ = chisl.size( );
    for ( std::size_t i = 0; i < chislitel_size_; ++i ) {
      chislitel_[ i ] = chisl[ chislitel_size_ - 1 - i ] - '0';
    }
    znamenatel_ = new UChar[ znam.size( ) ];
    znamenatel_size_ = znam.size( );
    for ( std::size_t i = 0; i < znamenatel_size_; ++i ) {
      znamenatel_[ i ] = znam[ znamenatel_size_ - 1 - i ] - '0';
    }
    // debug
    for ( std::size_t i = 0; i < chislitel_size_; ++i ) {
      std::cout << char( chislitel_[ i ] + '0' );
    }
    std::cout << " ***** ";
    for ( std::size_t i = 0; i < znamenatel_size_; ++i ) {
      std::cout << char( znamenatel_[ i ] + '0' );
    }
    std::cout << std::endl;
    // end debug
  }
}

Rational7::Rational7( const Rational7 &rvalue ) {
  UChar *tmpChislitel = new UChar[ rvalue.chislitel_size_ ];
  chislitel_size_ = rvalue.chislitel_size_;
  for ( std::size_t i = 0; i < chislitel_size_; ++i ) {
    tmpChislitel[ i ] = rvalue.chislitel_[ i ];
  }
  UChar *tmpZnamenatel = new UChar[ rvalue.znamenatel_size_ ];
  znamenatel_size_ = rvalue.znamenatel_size_;
  for ( std::size_t i = 0; i < znamenatel_size_; ++i ) {
    tmpZnamenatel[ i ] = rvalue.znamenatel_[ i ];
  }
  delete[] chislitel_;
  chislitel_ = tmpChislitel;
  delete[] znamenatel_;
  znamenatel_ = tmpZnamenatel;
}

Rational7::Rational7( Rational7 &&tmpVal ) {
  delete[] chislitel_;
  chislitel_ = tmpVal.chislitel_;
  tmpVal.chislitel_ = nullptr;
  chislitel_size_ = tmpVal.chislitel_size_;
  tmpVal.chislitel_size_ = 0;
  delete[] znamenatel_;
  znamenatel_ = tmpVal.znamenatel_;
  tmpVal.znamenatel_ = nullptr;
  znamenatel_size_ = tmpVal.znamenatel_size_;
  tmpVal.znamenatel_size_ = 0;
}

Rational7::~Rational7( ) {
  delete[] chislitel_;
  delete[] znamenatel_;
}

Rational7 &Rational7::operator=( const Rational7 &rvalue ) {
  if ( this != &rvalue ) {
    UChar *tmpChislitel = new UChar[ rvalue.chislitel_size_ ];
    chislitel_size_ = rvalue.chislitel_size_;
    for ( std::size_t i = 0; i < chislitel_size_; ++i ) {
      tmpChislitel[ i ] = rvalue.chislitel_[ i ];
    }
    UChar *tmpZnamenatel = new UChar[ rvalue.znamenatel_size_ ];
    znamenatel_size_ = rvalue.znamenatel_size_;
    for ( std::size_t i = 0; i < znamenatel_size_; ++i ) {
      tmpZnamenatel[ i ] = rvalue.znamenatel_[ i ];
    }
    delete[] chislitel_;
    chislitel_ = tmpChislitel;
    delete[] znamenatel_;
    znamenatel_ = tmpZnamenatel;
  }
  return *this;
}

Rational7 &Rational7::operator=( Rational7 &&tmpVal ) {
  if ( this != &tmpVal ) {
    delete[] chislitel_;
    chislitel_ = tmpVal.chislitel_;
    tmpVal.chislitel_ = nullptr;
    chislitel_size_ = tmpVal.chislitel_size_;
    tmpVal.chislitel_size_ = 0;
    delete[] znamenatel_;
    znamenatel_ = tmpVal.znamenatel_;
    tmpVal.znamenatel_ = nullptr;
    znamenatel_size_ = tmpVal.znamenatel_size_;
    tmpVal.znamenatel_size_ = 0;
  }
  return *this;
}

std::pair< UChar *, int > Rational7::Summa_2_Arrays( UChar arrOne[],
                                                     size_t sizeOne,
                                                     UChar arrTwo[],
                                                     size_t sizeTwo ) {
  UChar *p_curMaxLenArray = nullptr;
  UChar *p_curMinLenArray = nullptr;
  std::size_t curMaxLenSize = 0;
  std::size_t curMinLenSize = 0;
  //выбор большего и меньшего из массивов
  if ( sizeTwo <= sizeOne ) {
    p_curMaxLenArray = arrOne;
    p_curMinLenArray = arrTwo;
    curMaxLenSize = sizeOne;
    curMinLenSize = sizeTwo;
  } else {
    p_curMaxLenArray = arrTwo;
    p_curMinLenArray = arrOne;
    curMaxLenSize = sizeTwo;
    curMinLenSize = sizeOne;
  }
  //новый массив
  UChar *resultArray = new UChar[ curMaxLenSize + 1 ];
  int carry = 0;
  std::size_t i = 0;
  for ( ; i < curMinLenSize; ++i ) {
    int c = p_curMinLenArray[ i ] + p_curMaxLenArray[ i ] + carry;
    if ( c > 10 ) {
      carry = 1;
      c %= 10;
    } else {
      carry = 0;
    }
    resultArray[ i ] = c;
  }
  for ( ; i < curMaxLenSize; ++i ) {
    int c = p_curMaxLenArray[ i ] + carry;
    if ( c > 10 ) {
      carry = 1;
      c %= 10;
    } else {
      carry = 0;
    }
    resultArray[ i ] = c;
  }
  resultArray[ curMaxLenSize ] = carry;
  std::size_t resultSize = curMaxLenSize + 1;
  TrimN( resultArray, resultSize );
  return std::make_pair( resultArray, resultSize );
}

void Rational7::Trim( UChar *&arr, std::size_t &size ) {
  if ( arr[ size - 1 ] == 0 ) {
    UChar *tmp = new UChar[ size - 1 ];
    for ( std::size_t i = 0; i < size - 1; ++i ) {
      tmp[ i ] = arr[ i ];
    }
    delete[] arr;
    arr = tmp;
    --size;
  }
}

void Rational7::TrimN( UChar *&arr, size_t &size ) {
  int count = 0;
  int sz = size - 1;
  while ( sz > 0 && arr[ sz ] == 0 ) {
    ++count;
    --sz;
  }
  int newSz = size - count;
  UChar *tmp = new UChar[ newSz ];
  for ( int i = 0; i < newSz; ++i ) {
    tmp[ i ] = arr[ i ];
  }
  delete[] arr;
  arr = tmp;
  size -= count;
}

// FIXME ПРОДОЛЖАТЬ ТУТ
