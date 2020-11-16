#include "account.h"

Account::Account( ) : num_( ), code_( ), family_( ), summa_( ), data_open_( ), procent_( ) {}

Account::Account( const NumberAccount &num, const CodeAccount &code, const Family &family, const SummAccount &summa,
                  const DateAccount &date, const Procent &procent )
    : num_ { num }, code_ { code }, family_ { family }, summa_ { summa }, data_open_ { date }, procent_ { procent } {}

Account::Account( const Account &oth )
    : num_( oth.num_ ),
      code_( oth.code_ ),
      family_( oth.family_ ),
      summa_( oth.summa_ ),
      data_open_( oth.data_open_ ),
      procent_( oth.procent_ ) {}

Account &Account::operator=( const Account &oth ) {
  if ( this == &oth ) return *this;
  num_ = oth.num_;
  code_ = oth.code_;
  family_ = oth.family_;
  summa_ = oth.summa_;
  data_open_ = oth.data_open_;
  procent_ = oth.procent_;
  return *this;
}

bool Account::save( std::ofstream &out ) {
  out.write( reinterpret_cast< char * >( this ), sizeof( Account ) );
  return out.good( );
}

bool Account::read( std::ifstream &in ) {
  Account tmp;
  in.read( reinterpret_cast< char * >( &tmp ), sizeof( Account ) );
  *this = tmp;
  return in.good( );
}

std::ostream &operator<<( std::ostream &out, const Account &acc ) {
  return out << acc.num_ << acc.code_ << acc.family_ << acc.summa_ << acc.data_open_ << acc.procent_;
}

std::istream &operator>>( std::istream &in, Account &acc ) {
  in >> acc.num_ >> acc.code_ >> acc.family_ >> acc.summa_ >> acc.data_open_ >> acc.procent_;
  return in;
}
