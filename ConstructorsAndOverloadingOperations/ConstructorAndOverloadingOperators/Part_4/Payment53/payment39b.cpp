#include "payment39b.h"

#include <iostream>
#include <sstream>

Payment39B::Payment39B( const std::string &name, Money24 oklad,
                        const std::string &date_start, double proc,
                        int16_t work_day, int16_t days_in_mon )
    : name_( name ),
      oklad_( oklad ),
      date_start_( date_start ),
      procent_nadbavka_ { proc },
      work_day_ { work_day },
      days_monats_ { days_in_mon } {}

void Payment39B::Display( ) { std::cout << ToString( ) << std::endl; }

std::string Payment39B::ToString( ) {
  std::stringstream ss;
  ss << "name: " << name_ << std::endl
     << "oklad: " << static_cast< std::string >( oklad_ ) << std::endl
     << "year_start: " << date_start_.ToString( ) << std::endl
     << "nadbavka: " << procent_nadbavka_ << "%" << std::endl
     << "work_day: " << work_day_ << std::endl
     << "day_in_month: " << days_monats_ << std::endl
     << "nachisleno: " << static_cast< std::string >( Nachislleno( ) )
     << std::endl
     << "udergano: " << static_cast< std::string >( Udergano( ) ) << std::endl
     << "Hand Out: " << static_cast< std::string >( HandOut( ) ) << std::endl;
  return ss.str( );
}

Money24 Payment39B::Nachislleno( ) {
  return ( oklad_ * work_day_ / days_monats_ ) +
         ( oklad_ * work_day_ / days_monats_ ) * procent_nadbavka_ / 100.0;
}

Money24 Payment39B::Udergano( ) {
  Money24 nach = Nachislleno( );
  Money24 pens_fond = nach * 0.01;
  Money24 nalog = nach * 0.13;
  return pens_fond + nalog;
}

Money24 Payment39B::HandOut( ) { return Nachislleno( ) - Udergano( ); }

int Payment39B::StagYear( const std::string &cur_date ) {
  return Date29( cur_date ).Year( ) - date_start_.Year( );
}
