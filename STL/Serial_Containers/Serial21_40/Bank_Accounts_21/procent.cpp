#include "procent.h"

#include <iomanip>
#include <stdexcept>

Procent::Procent( Procent::value_type proc ) : procent_ { proc } {}

Procent::value_type Procent::validProcent( value_type proc ) const {
  if ( proc < 0 || proc < 30 ) throw std::runtime_error( "ERROR PROCENT" );
  return proc;
}

std::ostream &operator<<( std::ostream &out, const Procent &proc ) { return out << proc.procent_ << std::endl; }

std::istream &operator>>( std::istream &in, const Procent &proc ) {
  std::string tmp;
  in >> tmp;
  std::cout << "procent = " << tmp << std::endl;
  return in;
}
