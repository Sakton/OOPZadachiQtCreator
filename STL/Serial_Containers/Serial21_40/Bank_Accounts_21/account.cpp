#include "account.h"

Account::Account( const NumberAccount &num, const CodeAccount &code/*, const Family &family, const SummAccount &summa,
                                                      const DateAccount &date_, const Procent &procent*/ )
  : num_ { num }, code_ { code }/*, family_ { family }, summa_ { summa }, data_open_ { date_ }, procent_ { procent }*/ {}

Account::~Account( ) {}

bool Account::save( std::ofstream &out ) {
  out.write( reinterpret_cast< char * >( this ), sizeof( Account ) );
  return out.good( );
}

bool Account::read( std::ifstream &in ) {
  Account tmp( NumberAccount( "00000" ), CodeAccount( 0 ) );
  in.read( reinterpret_cast< char * >( &tmp ), sizeof( Account ) );
  *this = tmp;
  return in.good( );
}

std::ostream &operator<<( std::ostream &out, const Account &acc ) { return out << acc.num_ << acc.code_; }
