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

std::ostream &operator<<( std::ostream &out, const CodeAccount &oth ) {
  out << oth.id( ) << std::endl;
  return out;
}

std::istream &operator>>( std::istream &in, CodeAccount &oth ) {
  std::string tmp;
  in >> tmp;
  std::cout << "tmp Id = " << tmp << std::endl;
  //  std::string::size_type ind = tmp.find( "CodeAccount = " );
  //  if(ind != std::string::npos)
  //    tmp = tmp.substr(0, );
  // TODO ОБРАБОТАТЬ СТРОКУ
  // oth.setId( tmp );
  return in;
}
