#include "accountimpl.h"

AccountImpl::AccountImpl( ) : num_( ), code_( ), family_( ), summa_( ), data_open_( ), procent_( ) {}

AccountImpl::AccountImpl( const NumberAccount &num, const CodeAccount &code, const Family &family, const SummAccount &summa,
                          const DateAccount &date, const Procent &procent )
    : num_ { num }, code_ { code }, family_ { family }, summa_ { summa }, data_open_ { date }, procent_ { procent } {}

bool AccountImpl::save( std::ofstream &out ) {
  out.write( reinterpret_cast< char * >( this ), sizeof( AccountImpl ) );
  return out.good( );
}

std::ostream &operator<<( std::ostream &out, const AccountImpl &acc ) {
  return out << acc.num_ << acc.code_ << acc.family_ << acc.summa_ << acc.data_open_ << acc.procent_;
}
