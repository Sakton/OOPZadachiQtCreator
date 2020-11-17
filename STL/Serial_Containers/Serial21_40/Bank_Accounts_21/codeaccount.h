#ifndef CODEACCOUNT_H
#define CODEACCOUNT_H
#include <cstdint>

#include "abstract_save_open_class.h"

class CodeAccount {
 public:
  using id_type = uint32_t;

  explicit CodeAccount( const id_type &id = 0 );
  id_type id( ) const;
  void setId( const id_type &id );

 private:
  id_type validateCode( id_type code );

 private:
  id_type id_;
};

std::ostream &operator<<( std::ostream &out, const CodeAccount &oth );

#endif // CODEACCOUNT_H
