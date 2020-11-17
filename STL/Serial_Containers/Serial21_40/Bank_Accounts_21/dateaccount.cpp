#include "dateaccount.h"

#include <stdexcept>

DateAccount::DateAccount( ) : day_( ), month_( Month::Jan( ) ), year_( ) {}

DateAccount::DateAccount( const Day &day, const Month &m, const Year &year ) : day_( day ), month_( m ), year_( year ) {}

DateAccount::DateAccount( const DateAccount &oth ) : day_( oth.day_ ), month_( oth.month_ ), year_( oth.year_ ) {}

Day::Day( Day::value_type d ) : day_ { validDay( d ) } {}

Day::value_type Day::validDay( Day::value_type d ) const {
  if ( d < 0 || 31 < d ) throw std::runtime_error( "ERROR DAY IN DATE" );
  return d;
}

Month::Month( Month::value_type m ) : m_ { m } {}

Month::value_type Month::month( ) const { return m_; }

Year::Year( Year::value_type year ) : year_( validateYear( year ) ) {}

Year::value_type Year::validateYear( Year::value_type year ) const {
  if ( year < 1950 || 2050 < year ) throw std::runtime_error( "YEAR INTERVAL ERROR" );
  return year;
}

std::ostream &operator<<( std::ostream &out, const Day &d ) { return out << d.day_ << " "; }

std::ostream &operator<<( std::ostream &out, const Month &m ) { return out << m.m_ << " "; }

std::ostream &operator<<( std::ostream &out, const Year &y ) { return out << y.year_; }

std::ostream &operator<<( std::ostream &out, const DateAccount &da ) { return out << da.day_ << da.month_ << da.year_ << std::endl; }
