#include "bill.h"

#include <iostream>

Bill::Bill( const std::string &name, const std::string &phone, double tarif,
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

Time30 Bill::start_time( ) const { return start_time_; }

void Bill::setStart_time( const Time30 &start_time ) {
  start_time_ = start_time;
}

Time30 Bill::end_time( ) const { return end_time_; }

void Bill::setEnd_time( const Time30 &end_time ) { end_time_ = end_time; }
