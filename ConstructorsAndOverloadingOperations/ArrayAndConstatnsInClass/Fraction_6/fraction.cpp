#include "fraction.h"

#include <iostream>
#include <iterator>

Fraction::Fraction( const std::string& str )
    : cel_ { nullptr }, drobn_ { nullptr }, sizeCel_ { 0 }, sizeDrobn_ { 0 } {
  auto para = parseString( str );
  sizeCel_ = para.first.size( );
  sizeDrobn_ = para.second.size( );

  if ( sizeCel_ > MAXSIZE || sizeDrobn_ > MAXSIZE ) {
    std::cout << "ERROR SIZE CTOR";
    exit( 1 );
  }

  cel_ = new unsigned char[ sizeCel_ ];
  drobn_ = new unsigned char[ sizeDrobn_ ];
  int i = 0;
  for ( auto it = para.first.crbegin( ); it != para.first.crend( ); ++it ) {
    cel_[ i++ ] = *it - '0';
  }
  // debugPrint( cel_, sizeCel_ );
  i = 0;
  for ( auto it = para.second.cbegin( ); it != para.second.cend( ); ++it ) {
    drobn_[ i++ ] = *it - '0';
  }
  // debugPrint( drobn_, sizeDrobn_ );
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

void Fraction::debugPrint( unsigned char arr[], int16_t sz ) {
  std::cout << "debug " << std::endl;
  std::ostream_iterator< int > oi( std::cout );
  std::copy( arr, arr + sz, oi );
  std::cout << std::endl;
}

int16_t Fraction::getSizeDrobn( ) const { return sizeDrobn_; }

int16_t Fraction::getSizeCel( ) const { return sizeCel_; }
