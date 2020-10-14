#include "date.h"

Date::Date( int day, int mon, int year ) : Triad( day, mon, year ) {}

int &Date::firstNext( ) { return Triad::firstNext( ) %= 31; }

int &Date::secondNext( ) { return Triad::secondNext( ) %= 12; }

int &Date::thirdNext( ) { return Triad::thirdNext( ); }

std::ostream &operator<<( std::ostream &out, const Date &dt ) {
  dt.Show( out );
  return out;
}
