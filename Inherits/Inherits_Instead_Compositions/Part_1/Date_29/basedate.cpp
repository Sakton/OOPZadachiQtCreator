#include "basedate.h"

#include <iostream>
#include <regex>
#include <sstream>

BaseDate::BaseDate( int16_t y, int16_t m, int16_t d ) {
  if ( y < 0 || m < 0 || d < 0 ) {
    std::cout << "ERROR ARG";
    exit( 1 );
  }
  y_ = y;
  m_ = m;
  d_ = d;
}

BaseDate::BaseDate( const std::string& dt ) {
  std::regex t( R"((\d{2})\.(\d{2})\.(\d{4}))" );
  std::smatch res;
  if ( !std::regex_match( dt, res, t ) ) {
    std::cout << "ERROR ARG STR";
    exit( 1 );
  }

  int y = std::stoi( res[ 3 ] );
  int m = std::stoi( res[ 2 ] );
  int d = std::stoi( res[ 1 ] );

  *this = BaseDate( y, m, d );
}

BaseDate::BaseDate( const BaseDate& dt ) { *this = dt; }

int16_t BaseDate::Year( ) const { return y_; }

void BaseDate::setYear( const int16_t& y ) { y_ = y; }

int16_t BaseDate::Month( ) const { return m_; }

void BaseDate::setMonth( const int16_t& m ) { m_ = m; }

int16_t BaseDate::Day( ) const { return d_; }

void BaseDate::setDay( const int16_t& d ) { d_ = d; }

void Display( const BaseDate& dt ) { std::cout << ToString( dt ) << std::endl; }

std::string ToString( const BaseDate& dt ) {
  std::stringstream ss;
  ss << "\"";
  if ( dt.d_ < 10 ) ss << '0';
  ss << dt.d_ << ".";
  if ( dt.m_ < 10 ) ss << '0';
  ss << dt.m_ << "." << dt.y_ << "\"";
  return ss.str( );
}
