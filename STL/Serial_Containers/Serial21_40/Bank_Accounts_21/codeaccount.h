#ifndef CODEACCOUNT_H
#define CODEACCOUNT_H
#include <cstdint>

#include "abstract_save_open_class.h"

class CodeAccount {
 public:
  using id_type = uint32_t;

  explicit CodeAccount( const id_type &id );
  id_type id( ) const;
  friend std::ostream &operator<<( std::ostream &out, const CodeAccount &oth );

 private:
  id_type validateCode( id_type code );

 private:
  id_type id_;
};

#endif // CODEACCOUNT_H
