#include "fraction.h"

#include <iostream>
#include <iterator>

Fraction::Fraction( const std::string& str )
    : cel_ { nullptr }, drobn_ { nullptr }, sizeCel_ { 0 }, sizeDrobn_ { 0 } {
  auto para = parseString( str );
  sizeCel_ = ( para.first.size( ) % 2 ) ? para.first.size( ) / 2 + 1
                                        : para.first.size( ) / 2;
  sizeDrobn_ = ( para.second.size( ) % 2 ) ? para.second.size( ) / 2 + 1
                                           : para.second.size( ) / 2;

  if ( sizeCel_ > MAXSIZE || sizeDrobn_ > MAXSIZE ) {
    std::cout << "ERROR SIZE CTOR";
    exit( 1 );
  }
  cel_ = new unsigned char[ sizeCel_ ] { 0 };
  drobn_ = new unsigned char[ sizeDrobn_ ] { 0 };
  readChislitel( para.first );
  readZnamenatel( para.second );
}

Fraction::Fraction( long double x ) {
  int64_t cel = x;
  long double drob = x - cel;
}

Fraction::~Fraction( ) {
  delete[] cel_;
  delete[] drobn_;
}

Fraction::Fraction( const Fraction& fr )
    : cel_ { new unsigned char[ fr.sizeCel_ ] },
      drobn_ { new unsigned char[ fr.sizeDrobn_ ] },
      sizeCel_ { fr.sizeCel_ },
      sizeDrobn_ { fr.sizeDrobn_ } {
  //  std::cout << "cpu ctor" << std::endl;
  std::copy( fr.cel_, fr.cel_ + fr.sizeCel_, cel_ );
  std::copy( fr.drobn_, fr.drobn_ + fr.sizeDrobn_, drobn_ );
  //  debugPrint( cel_, sizeCel_ );
  //  debugPrint( drobn_, sizeDrobn_ );
}

Fraction::Fraction( Fraction&& fr ) noexcept {
  delete[] cel_;
  cel_ = fr.cel_;
  fr.cel_ = nullptr;
  sizeCel_ = fr.sizeCel_;
  fr.sizeCel_ = 0;
  delete[] drobn_;
  drobn_ = fr.drobn_;
  fr.drobn_ = nullptr;
  sizeDrobn_ = fr.sizeDrobn_;
  fr.sizeDrobn_ = 0;
}

Fraction& Fraction::operator=( const Fraction& fr ) {
  std::cout << "op = " << std::endl;
  if ( this != &fr ) {
    unsigned char* tmpCel = new unsigned char[ fr.sizeCel_ ];
    std::copy( fr.cel_, fr.cel_ + fr.sizeCel_, tmpCel );
    unsigned char* tmpDrob = new unsigned char[ fr.sizeDrobn_ ];
    std::copy( fr.drobn_, fr.drobn_ + fr.sizeDrobn_, tmpDrob );
    sizeCel_ = fr.sizeCel_;
    sizeDrobn_ = fr.sizeDrobn_;
    delete[] cel_;
    delete[] drobn_;
    cel_ = tmpCel;
    drobn_ = tmpDrob;
    //    debugPrint( cel_, sizeCel_ );
    //    debugPrint( drobn_, sizeDrobn_ );
  }
  return *this;
}

Fraction& Fraction::operator=( Fraction&& fr ) noexcept {
  if ( this != &fr ) {
    delete[] cel_;
    cel_ = fr.cel_;
    fr.cel_ = nullptr;
    sizeCel_ = fr.sizeCel_;
    fr.sizeCel_ = 0;
    delete[] drobn_;
    drobn_ = fr.drobn_;
    fr.drobn_ = nullptr;
    sizeDrobn_ = fr.sizeDrobn_;
    fr.sizeDrobn_ = 0;
  }
  return *this;
}

std::ostream& operator<<( std::ostream& out, const Fraction& fr1 ) {
  std::string res;
  for ( int i = fr1.sizeCel_ - 1; i >= 0; --i ) {
    if ( static_cast< int16_t >( fr1.cel_[ i ] ) < 10 ) {
      res += '0';
    }
    res += std::to_string( static_cast< int16_t >( fr1.cel_[ i ] ) );
  }
  //  for ( int i = 0; i < fr1.sizeCel_; ++i ) {
  //    res += std::to_string( static_cast< int16_t >( fr1.cel_[ i ] ) );
  //  }
  res += ',';
  for ( int i = fr1.sizeDrobn_ - 1; i >= 0; --i ) {
    if ( static_cast< int16_t >( fr1.drobn_[ i ] ) < 10 ) {
      res += '0';
    }
    res += std::to_string( static_cast< int16_t >( fr1.drobn_[ i ] ) );
  }
  if ( res.find_first_not_of( '0' ) != std::string::npos ) {
    res = res.substr( res.find_first_not_of( '0' ) );
  }
  out << res;
  return out;
}

Fraction& Fraction::operator+=( const Fraction& fr ) {
  int tmpSizeDrobn = std::max( sizeDrobn_, fr.sizeDrobn_ );
  unsigned char* tmpDrobn = new unsigned char[ tmpSizeDrobn + 1 ] { 0 };
  for ( int i = tmpSizeDrobn - 1; i >= 0; --i ) {
    if ( i > sizeDrobn_ ) {
      tmpDrobn[ i ] = fr.drobn_[ i ];
    } else if ( i > fr.sizeDrobn_ ) {
      tmpDrobn[ i ] = drobn_[ i ];
    } else {
      tmpDrobn[ i ] = drobn_[ i ] + fr.drobn_[ i ];
    }
  }

  for ( int i = tmpSizeDrobn - 1; i > 0; --i ) {
    if ( tmpDrobn[ i ] > OSNOVA ) {
      tmpDrobn[ i ] -= OSNOVA;
      tmpDrobn[ i - 1 ]++;
    }
  }

  int tmpSizeCel = std::max( sizeCel_, fr.sizeCel_ ) + 1;
  unsigned char* tmpCel =
      new unsigned char[ std::max( sizeCel_, fr.sizeCel_ ) + 1 ] { 0 };

  for ( int i = 0; i < tmpSizeCel - 1; ++i ) {
    if ( i > sizeCel_ ) {
      tmpCel[ i ] = fr.cel_[ i ];
    } else if ( i > fr.sizeCel_ ) {
      tmpCel[ i ] = cel_[ i ];
    } else {
      tmpCel[ i ] = cel_[ i ] + fr.cel_[ i ];
    }
    //переход дроби
    if ( tmpDrobn[ 0 ] > OSNOVA && i == 0 ) {
      tmpCel[ i ]++;
      tmpDrobn[ 0 ] -= OSNOVA;
    }
  }

  for ( int i = 0; i < tmpSizeCel; ++i ) {
    if ( tmpCel[ i ] > OSNOVA ) {
      tmpCel[ i ] -= OSNOVA;
      tmpCel[ i + 1 ]++;
    }
  }

  delete[] cel_;
  cel_ = tmpCel;
  sizeCel_ = tmpSizeCel;
  delete[] drobn_;
  drobn_ = tmpDrobn;
  sizeDrobn_ = tmpSizeDrobn;

  return *this;
}

std::pair< std::string, std::string > Fraction::parseString(
    const std::string& str ) const {
  std::string::size_type i_delim = str.find_first_of( ",." );
  std::string celoe;
  std::string drobnoe;
  if ( i_delim != std::string::npos ) {
    celoe = str.substr( 0, i_delim );
    drobnoe = str.substr( i_delim + 1, str.size( ) );
    //    std::cout << celoe << " ++++++ " << drobnoe;
  }
  return std::make_pair( celoe, drobnoe );
}

void Fraction::readChislitel( const std::string& str ) {
  int j = 0;
  int x = 0;
  std::string t = str;
  while ( t.size( ) > 1 ) {
    std::string tt = t.substr( t.size( ) - 2 );

    x = std::stoi( t.substr( t.size( ) - 2 ) );

    cel_[ j++ ] = x;
    t = t.substr( 0, t.size( ) - 2 );

    //    x = std::stoi( t.substr( 0, 2 ) );
    //    cel_[ j++ ] = x;
    //    t = t.substr( 2 );
  }
  if ( t.size( ) == 1 ) {
    cel_[ j++ ] = std::stoi( t );
  }
}

void Fraction::readZnamenatel( const std::string& str ) {
  int j = 0;
  int x = 0;
  std::string t = str;
  while ( t.size( ) > 1 ) {
    //    x = std::stoi( t.substr( t.size( ) - 2 ) );
    //    drobn_[ j++ ] = x;
    //    t = t.substr( 0, t.size( ) - 2 );

    x = std::stoi( t.substr( 0, 2 ) );
    drobn_[ j++ ] = x;
    t = t.substr( 2 );
  }
  if ( t.size( ) == 1 ) {
    drobn_[ j++ ] = std::stoi( t );
  }
}

void Fraction::debugPrint( unsigned char arr[], int16_t sz ) {
  std::cout << "debug " << std::endl;
  std::ostream_iterator< int > oi( std::cout );
  std::copy( arr, arr + sz, oi );
  std::cout << std::endl;
}

int16_t Fraction::getSizeDrobn( ) const { return sizeDrobn_; }

int16_t Fraction::getSizeCel( ) const { return sizeCel_; }
