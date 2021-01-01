#include "account.h"

Account::Account( ) : num_( ), code_( ), family_( ), summa_( ), data_open_( ), procent_( ) {}

Account::Account( const NumberAccount &num, const CodeAccount &code, const Family &family, const SummAccount &summa,
                  const DateAccount &date, const Procent &procent )
    : num_ { num }, code_ { code }, family_ { family }, summa_ { summa }, data_open_ { date }, procent_ { procent } {}

bool Account::save( std::ofstream &out ) {
  out.write( reinterpret_cast< char * >( this ), sizeof( Account ) );
  return out.good( );
  // return pImpl_->save( out );
}

bool Account::read( std::ifstream &in ) {
  Account tmp;
  in.read( reinterpret_cast< char * >( &tmp ), sizeof( Account ) );
  *this = tmp;
  return in.good( );
  // return pImpl_->read( in );
}

NumberAccount Account::num( ) const { return num_; }

CodeAccount Account::code( ) const { return code_; }

Family Account::family( ) const { return family_; }

SummAccount Account::summa( ) const { return summa_; }

DateAccount Account::data_open( ) const { return data_open_; }

Procent Account::procent( ) const { return procent_; }

std::ostream &operator<<( std::ostream &out, const Account &acc ) {
  return out << acc.num_ << acc.code_ << acc.family_ << acc.summa_ << acc.data_open_ << acc.procent_;
}
