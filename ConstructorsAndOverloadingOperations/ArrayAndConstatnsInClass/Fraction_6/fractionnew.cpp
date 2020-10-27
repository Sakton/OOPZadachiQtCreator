#include "fractionnew.h"

#include <iostream>
#include <iterator>

FractionNew::FractionNew( int szCel, int szDrob )
    : cel_ { nullptr }, drobn_ { nullptr }, sizeCel_ { 0 }, sizeDrobn_ { 0 } {
  // cel_ = unsigned char[szC]
  if ( szCel >= MAXSIZE || szDrob >= MAXSIZE || szCel < 0 || szDrob < 0 ) {
    std::cout << "ERROR SIZE CTOR";
    exit( 1 );
  }
  cel_ = new unsigned char[ szCel ] { 0 };
  drobn_ = new unsigned char[ szDrob ] { 0 };
  sizeCel_ = szCel;
  sizeDrobn_ = szDrob;
}

FractionNew::~FractionNew( ) {
  delete[] cel_;
  delete[] drobn_;
}

FractionNew::FractionNew( const FractionNew& fr )
    : cel_ { new unsigned char[ fr.sizeCel_ ] },
      drobn_ { new unsigned char[ fr.sizeDrobn_ ] },
      sizeCel_ { fr.sizeCel_ },
      sizeDrobn_ { fr.sizeDrobn_ } {
  //  std::cout << "cpu ctor" << std::endl;
  std::copy( fr.cel_, fr.cel_ + fr.sizeCel_, cel_ );
  std::copy( fr.drobn_, fr.drobn_ + fr.sizeDrobn_, drobn_ );
}

FractionNew::FractionNew( FractionNew&& fr ) noexcept {
  delete[] cel_;
  cel_ = fr.cel_;
  sizeCel_ = fr.sizeCel_;
  fr.cel_ = nullptr;
  fr.sizeCel_ = 0;
  delete[] drobn_;
  drobn_ = fr.drobn_;
  fr.drobn_ = nullptr;
  fr.sizeDrobn_ = 0;
}

FractionNew& FractionNew::operator=( const FractionNew& fr ) {
  if ( this != &fr ) {
    unsigned char* tmpCel = new unsigned char[ fr.sizeCel_ ] { 0 };
    unsigned char* tmpDrob = new unsigned char[ fr.sizeDrobn_ ] { 0 };
    std::copy( fr.cel_, fr.cel_ + fr.sizeCel_, tmpCel );
    std::copy( fr.drobn_, fr.drobn_ + fr.sizeDrobn_, tmpDrob );
    sizeCel_ = fr.sizeCel_;
    sizeDrobn_ = fr.sizeDrobn_;
    delete[] cel_;
    delete[] drobn_;
    cel_ = tmpCel;
    drobn_ = tmpDrob;
  }
  return *this;
}

FractionNew& FractionNew::operator=( FractionNew&& fr ) noexcept {
  if ( this != &fr ) {
    delete[] cel_;
    cel_ = fr.cel_;
    sizeCel_ = fr.sizeCel_;
    fr.cel_ = nullptr;
    fr.sizeCel_ = 0;
    delete[] drobn_;
    drobn_ = fr.drobn_;
    fr.drobn_ = nullptr;
    fr.sizeDrobn_ = 0;
  }
  return *this;
}

// WARNING bugs indexes

unsigned char& FractionNew::operator[]( int16_t index ) {
  if ( 0 <= index && index < sizeDrobn_ ) {
    return drobn_[ sizeDrobn_ - index - 1 ];
  }
  if ( sizeDrobn_ <= index && index < sizeCel_ + sizeDrobn_ ) {
    return cel_[ index - sizeDrobn_ ];
  } else {
    std::cout << "OIT OF RANGE " << index;
    exit( 1 );
  }
}

const unsigned char& FractionNew::operator[]( int16_t index ) const {
  if ( 0 <= index && index < sizeDrobn_ ) {
    return drobn_[ sizeDrobn_ - index - 1 ];
  }
  if ( sizeDrobn_ <= index && index < sizeCel_ + sizeDrobn_ ) {
    return cel_[ index - sizeDrobn_ ];
  } else {
    std::cout << "OIT OF RANGE " << index;
    exit( 1 );
  }
}

//сложение цифр одинаковой размерности
FractionNew& FractionNew::operator+=( const FractionNew& fr ) {
  FractionNew tmp( std::max( sizeCel_, fr.sizeCel_ ) + 1,
                   std::max( sizeDrobn_, fr.sizeDrobn_ ) );
  int len = sizeCel_ + sizeDrobn_;
  int maxSize = tmp.sizeCel_ + tmp.sizeDrobn_;
  for ( int i = 0; i < len; ++i ) {
    tmp[ i ] = this->operator[]( i ) + fr[ i ];
  }

  for ( int i = 0; i < maxSize; ++i ) {
    if ( tmp[ i ] >= OSNOVA ) {
      tmp[ i ] -= OSNOVA;
      tmp[ i + 1 ]++;
    }
  }
  return *this = tmp;
}

// FractionNew& FractionNew::operator+=( const FractionNew& fr ) {
//  int sizeTmpDr = std::max( sizeDrobn_, fr.sizeDrobn_ ) + 1;
//  unsigned char* tmpDrob = new unsigned char[ sizeTmpDr ] { 0 };
//  for ( int i = std::max( sizeDrobn_, fr.sizeDrobn_ ) - 1; i >= 0; --i ) {
//    if ( i > sizeDrobn_ ) {
//      tmpDrob[ i + 1 ] = fr.drobn_[ i ];
//    } else if ( i > fr.sizeDrobn_ ) {
//      tmpDrob[ i + 1 ] = drobn_[ i ];
//    } else {
//      tmpDrob[ i + 1 ] = drobn_[ i ] + fr.drobn_[ i ];
//    }
//  }

//  for ( int i = sizeTmpDr - 1; i > 0; --i ) {
//    if ( tmpDrob[ i ] > OSNOVA ) {
//      tmpDrob[ i ] %= OSNOVA;
//      tmpDrob[ i - 1 ]++;
//    }
//  }

//  int perenos = tmpDrob[ 0 ];
//  //убрать переносный символ
//  for ( int i = 0; i < sizeTmpDr - 1; ++i ) {
//    tmpDrob[ i ] = tmpDrob[ i + 1 ];
//  }
//  --sizeTmpDr;

//  // debugPrint( tmpDrob, sizeTmpDr );

//  //*****
//  int sizeTmpCel = std::max( sizeCel_, fr.sizeCel_ ) + 1;
//  unsigned char* tmpCel = new unsigned char[ sizeTmpCel ] { 0 };
//  for ( int i = 0; i < std::max( sizeCel_, fr.sizeCel_ ); ++i ) {
//    if ( i > fr.sizeCel_ ) {
//      tmpCel[ i ] = cel_[ i ];
//    } else if ( i > sizeCel_ ) {
//      tmpCel[ i ] = fr.cel_[ i ];
//    } else {
//      tmpCel[ i ] = cel_[ i ] + fr.cel_[ i ];
//    }
//    if ( i == 0 && perenos ) {
//      tmpCel[ i ] += perenos;
//    }
//  }

//  for ( int i = 0; i < sizeTmpCel - 1; ++i ) {
//    if ( tmpCel[ i ] > OSNOVA ) {
//      tmpCel[ i ] %= OSNOVA;
//      tmpCel[ i + 1 ]++;
//    }
//  }
//  //оставим нулевой симвл чтобы не копировать
//  if ( tmpCel[ sizeTmpCel - 1 ] == 0 ) --sizeTmpCel;
//  // debugPrint( tmpCel, sizeTmpCel );

//  delete[] cel_;
//  cel_ = tmpCel;
//  sizeCel_ = sizeTmpCel;

//  delete[] drobn_;
//  drobn_ = tmpDrob;
//  sizeDrobn_ = sizeTmpDr;

//  return *this;
//}

void FractionNew::debugPrint( unsigned char arr[], int16_t sz ) {
  std::cout << "debug " << std::endl;
  std::ostream_iterator< int > oi( std::cout );
  std::copy( arr, arr + sz, oi );
  std::cout << std::endl;
}

int FractionNew::countNums( int64_t cel ) {
  int count = 0;
  while ( cel ) {
    ++count;
    cel /= 10;
  }
  return count;
}

void FractionNew::fillArray( unsigned char* arr, int64_t x ) {
  int i = 0;
  while ( x ) {
    arr[ i++ ] = x % 10;
    x /= 10;
  }
}

bool FractionNew::IndexIsValid( int index ) {
  return ( 0 <= index && index < ( sizeCel_ + sizeDrobn_ ) );
}

int16_t FractionNew::getSizeDrobn( ) const { return sizeDrobn_; }

int16_t FractionNew::getSizeCel( ) const { return sizeCel_; }

std::ostream& operator<<( std::ostream& out, const FractionNew& fr ) {
  std::string res;
  for ( int i = fr.sizeCel_ - 1; i >= 0; --i ) {
    res.push_back( fr.cel_[ i ] + '0' );
  }
  res += ',';
  for ( int i = 0; i < fr.sizeDrobn_; ++i ) {
    res.push_back( fr.drobn_[ i ] + '0' );
  }
  out << res;
  return out;
}
