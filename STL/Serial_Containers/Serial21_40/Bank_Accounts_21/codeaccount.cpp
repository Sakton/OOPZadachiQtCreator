#include "codeaccount.h"

#include <iostream>
#include <string>

CodeAccount::CodeAccount( const id_type &id ) : id_ { validateCode( id ) } {}

CodeAccount::id_type CodeAccount::id( ) const { return id_; }

CodeAccount::id_type CodeAccount::validateCode( CodeAccount::id_type code ) {
  // какието проверки, генерация может быть и тд.
  return code;
}

void CodeAccount::setId( const id_type &id ) { id_ = id; }

std::ostream &operator<<( std::ostream &out, const CodeAccount &oth ) { return out << oth.id( ) << std::endl; }
