#include "codeaccount.h"

CodeAccount::CodeAccount( const id_type &id ) : id_ { validateCode( id ) } {}

CodeAccount::id_type CodeAccount::id( ) const { return id_; }

CodeAccount::id_type CodeAccount::validateCode( CodeAccount::id_type code ) {
  // какието проверки, генерация может быть и тд.
  return code;
}

std::ostream &operator<<( std::ostream &out, const CodeAccount &oth ) {
  out << "CodeAccount = " << oth.id( ) << std::endl;
  return out;
}
