#include "bill.h"

#include <iostream>
#include <regex>
#include <sstream>

Bill::Time30::Time30( int16_t h, int16_t m, int16_t s )
    : h_ { 0 }, m_ { 0 }, s_ { 0 } {
  if ( !( 0 <= h && h < 24 ) || !( 0 <= m && m < 60 ) ||
       !( 0 <= s && s < 60 ) ) {
    std::cout << "ERROR INIT ARG";
    exit( 1 );
  }
  h_ = h;
  m_ = m;
  s_ = s;
}

Bill::Time30::Time30( const std::string& dt ) {
  std::regex reg( R"("(\d{2}):(\d{2}):(\d{2}))" );
  std::smatch res;
  if ( !std::regex_match( dt, res, reg ) ) {
    std::cout << "ERROR STR INIT ARG";
    exit( 1 );
  }
  *this = Time30( std::stoi( res[ 1 ] ), std::stoi( res[ 2 ] ),
                  std::stoi( res[ 3 ] ) );
}

Bill::Time30::Time30( const Time30& dt ) : Time30( dt.h_, dt.m_, dt.s_ ) {}

void Bill::Time30::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Bill::Time30::operator std::string( ) const {
  std::stringstream ss;
  ss << "\"";
  if ( h_ < 10 ) ss << '0';
  ss << h_ << ":";
  if ( m_ < 10 ) ss << '0';
  ss << m_ << ":";
  if ( s_ < 10 ) ss << '0';
  ss << s_ << "\"";
  return ss.str( );
}

int32_t operator-( const Bill::Time30& t1, const Bill::Time30& t2 ) {
  return std::abs( t1.ToMinut( ) - t2.ToMinut( ) );
}

Bill::Time30 operator+( const Bill::Time30& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec > Bill::Time30::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return Bill::Time30( ( other.ToSecond( ) + sec ) );
}

Bill::Time30 operator+( int32_t sec, const Bill::Time30& other ) {
  if ( other.ToSecond( ) + sec > Bill::Time30::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return Bill::Time30( ( other.ToSecond( ) + sec ) );
}

Bill::Time30 operator-( const Bill::Time30& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec < Bill::Time30::SEC_IN_DAY ) {
    std::cout << "ERROR SUB SEC";
    exit( 1 );
  }
  return Bill::Time30( other.ToSecond( ) - sec );
}

bool operator==( const Bill::Time30& t1, const Bill::Time30& t2 ) {
  return t1.ToSecond( ) == t2.ToSecond( );
}

bool operator<( const Bill::Time30& t1, const Bill::Time30& t2 ) {
  return t1.ToSecond( ) < t2.ToSecond( );
}

bool operator>( const Bill::Time30& t1, const Bill::Time30& t2 ) {
  return !( t1 < t2 );
}

int32_t Bill::Time30::ToSecond( ) const { return ( h_ * 60 + m_ ) * 60 + s_; }

int32_t Bill::Time30::ToMinut( ) const {
  //округлить вверх, кастуем в дабл + 0,5 кастуем обратно в инт
  return ( s_ > 30 ) ? m_ + 1 : m_;
}

Bill::Time30 Bill::Time30::ToTime( int32_t sec ) const {
  if ( sec > Time30::SEC_IN_DAY ) {
    std::cout << "ERROR SEC";
    exit( 1 );
  }
  return Time30( ( sec / 3600 ) % 24, ( sec / 60 ) % 60, sec % 60 );
}

Bill::Bill( const std::string& name, const std::string& phone, double tarif,
            double sale, Time30 start, Time30 end )
    : name_ { name },
      phone_ { phone },
      tarif_minut_ { tarif },
      sale_ { sale },
      start_time_( start ),
      end_time_( end ) {
  cost_ = Cost( );
}

void Bill::Display( ) const {
  std::cout << operator std::string( ) << std::endl;
}

Bill::operator std::string( ) const {
  return "name: " + name_ + "\n" + "phone: " + phone_ + "\n" +
         "tarif: " + std::to_string( tarif_minut_ ) + "\n" +
         "sale: " + std::to_string( sale_ ) + "\n" +
         "start_time: " + static_cast< std::string >( start_time_ ) + "\n" +
         "end_time: " + static_cast< std::string >( end_time_ ) + '\n' +
         "summa: " + std::to_string( cost_ ) + '\n';
}

int Bill::TimeSpeak( ) const {
  return end_time_.ToMinut( ) - start_time_.ToMinut( );
}

double Bill::Cost( ) const {
  return TimeSpeak( ) * tarif_minut_ -
         TimeSpeak( ) * tarif_minut_ * sale_ / 100.0;
}

std::string Bill::name( ) const { return name_; }

void Bill::setName( const std::string &name ) { name_ = name; }

std::string Bill::phone( ) const { return phone_; }

void Bill::setPhone( const std::string &phone ) { phone_ = phone; }

double Bill::tarif_minut( ) const { return tarif_minut_; }

void Bill::setTarif_minut( double tarif_minut ) { tarif_minut_ = tarif_minut; }

double Bill::sale( ) const { return sale_; }

void Bill::setSale( double sale ) { sale_ = sale; }

Bill::Time30 Bill::start_time( ) const { return start_time_; }

void Bill::setStart_time( const Time30 &start_time ) {
  start_time_ = start_time;
}

Bill::Time30 Bill::end_time( ) const { return end_time_; }

void Bill::setEnd_time( const Time30 &end_time ) { end_time_ = end_time; }
