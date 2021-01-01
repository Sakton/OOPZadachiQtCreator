#ifndef ACCOUNTIMPL_H
#define ACCOUNTIMPL_H
#include "codeaccount.h"
#include "dateaccount.h"
#include "family.h"
#include "numberaccount.h"
#include "procent.h"
#include "summaccount.h"

class AccountImpl
{
 public:
  AccountImpl( );
  AccountImpl( const NumberAccount &num, const CodeAccount &code, const Family &family, const SummAccount &summa, const DateAccount &date,
               const Procent &procent );
  bool save( std::ofstream &out );
  bool read( std::ifstream &in );

  friend std::ostream &operator<<( std::ostream &out, const AccountImpl &acc );

 private:
  NumberAccount num_;
  CodeAccount code_;
  Family family_;
  SummAccount summa_;
  DateAccount data_open_;
  Procent procent_;
};

#endif  // ACCOUNTIMPL_H
