#include "payment39b.h"

#include <iostream>
#include <sstream>

Payment39B::Payment39B( const std::string &name, double oklad, int16_t year,
                        double proc, double nalog, int16_t work_day,
                        int16_t days_in_mon ) {
  if ( name == "" || year < 1970 || oklad < 5000.0 || proc < 1.0 ||
       nalog < 1.0 || work_day < 1 ||
       !( 0 < days_in_mon && days_in_mon <= 31 ) ) {
    std::cout << "ERROR DATA";
    exit( 1 );
  }

  name_ = name;
  oklad_ = oklad;
  year_ = year;
  procent_nadbavka_ = proc;
  nalog_ = nalog;
  work_day_ = work_day;
  days_monats_ = days_in_mon;
  //  nachisleno_ = nachisleno;
  //  udergano_ = udergano;
}

void Payment39B::Display( ) { std::cout << ToString( ) << std::endl; }

std::string Payment39B::ToString( ) {
  std::stringstream ss;

  ss << "name: " << name_ << std::endl
     << "oklad: " << oklad_ << std::endl
     << "year: " << year_ << std::endl
     << "nadbavka: " << procent_nadbavka_ << "%" << std::endl
     << "nalog: " << nalog_ << std::endl
     << "work_day: " << work_day_ << std::endl
     << "day_in_month: " << days_monats_ << std::endl
     << "nachisleno: " << nachisleno_ << std::endl
     << "udergano: " << udergano_;

  return ss.str( );
}
