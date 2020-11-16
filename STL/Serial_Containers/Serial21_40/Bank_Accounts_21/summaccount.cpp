#include "summaccount.h"

#include <iomanip>
#include <stdexcept>
#include <string>

SummAccount::SummAccount( const value_type &summa ) : summa_ { validateSumma( summa ) } {}

const SummAccount::value_type &SummAccount::validateSumma( const SummAccount::value_type &summ ) const {
  if ( summ < 0 ) throw std::runtime_error( "SUMMA < 0" );
  return summ;
}

SummAccount::value_type SummAccount::summa( ) const { return summa_; }

void SummAccount::setSumma( const value_type &summa ) { summa_ = summa; }

std::ostream &operator<<( std::ostream &out, const SummAccount &ak ) { return out << ak.summa( ) << std::endl; }

std::istream &operator>>( std::istream &in, SummAccount &ak ) {
  std::string tmp;
  in >> tmp;
  std::cout << "tmp summAkk = " << tmp << std::endl;
  return in;
}
