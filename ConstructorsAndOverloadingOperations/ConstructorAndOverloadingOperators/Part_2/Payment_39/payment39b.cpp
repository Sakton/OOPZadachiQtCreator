#include "payment39b.h"

#include <iostream>
#include <sstream>

Payment39B::Payment39B( const std::string &name, double oklad,
                        int16_t year_start, double proc, int16_t work_day,
                        int16_t days_in_mon ) {
  if ( name == "" || year_start < 1970 || oklad < 5000.0 || proc < 1.0 ||
       work_day < 1 || !( 0 < days_in_mon && days_in_mon <= 31 ) ) {
    std::cout << "ERROR DATA";
    exit( 1 );
  }

  name_ = name;
  oklad_ = oklad;
  year_start_ = year_start;
  procent_nadbavka_ = proc;
  work_day_ = work_day;
  days_monats_ = days_in_mon;
}

void Payment39B::Display( ) { std::cout << ToString( ) << std::endl; }

std::string Payment39B::ToString( ) {
  std::stringstream ss;

  ss << "name: " << name_ << std::endl
     << "oklad: " << oklad_ << std::endl
     << "year_start: " << year_start_ << std::endl
     << "nadbavka: " << procent_nadbavka_ << "%" << std::endl
     << "work_day: " << work_day_ << std::endl
     << "day_in_month: " << days_monats_ << std::endl
     << "nachisleno: " << Nachislleno( ) << std::endl
     << "udergano: " << Udergano( ) << std::endl
     << "Hand Out: " << HandOut( ) << std::endl;

  return ss.str( );
}

double Payment39B::Nachislleno( ) {
  return ( oklad_ * work_day_ / days_monats_ ) +
         ( oklad_ * work_day_ / days_monats_ ) * procent_nadbavka_ / 100.0;
}

double Payment39B::Udergano( ) {
  double nach = Nachislleno( );
  double pens_fond = nach * 0.01;
  double nalog = nach * 0.13;
  return pens_fond + nalog;
}

double Payment39B::HandOut( ) { return Nachislleno( ) - Udergano( ); }

int Payment39B::StagYear( int currnetYear ) {
  return currnetYear - year_start_;
}
