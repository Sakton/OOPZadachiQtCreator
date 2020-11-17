#include "procent.h"

#include <iomanip>
#include <stdexcept>

Procent::Procent( Procent::value_type proc ) : procent_ { proc } {}

Procent::value_type Procent::validProcent( value_type proc ) const {
  if ( proc < 0 || proc > 20 ) throw std::runtime_error( "ERROR PROCENT" );
  return proc;
}

Procent::value_type Procent::procent( ) const { return procent_; }

std::ostream &operator<<( std::ostream &out, const Procent &proc ) { return out << proc.procent( ) << std::endl; }
