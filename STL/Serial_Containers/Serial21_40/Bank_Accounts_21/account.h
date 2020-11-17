#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <memory>

// #include "accountimpl.h"
#include "codeaccount.h"
#include "dateaccount.h"
#include "family.h"
#include "numberaccount.h"
#include "procent.h"
#include "summaccount.h"

//пустые аккаунты недопустимы

class Account {
 public:
  Account( );
  explicit Account( const NumberAccount &num, const CodeAccount &code, const Family &family, const SummAccount &summa,
                    const DateAccount &date, const Procent &procent );
  Account( const Account &oth ) = default;
  Account &operator=( const Account &oth ) = default;

  bool save( std::ofstream &out );
  bool read( std::ifstream &in );

  NumberAccount num( ) const;
  CodeAccount code( ) const;
  Family family( ) const;
  SummAccount summa( ) const;
  DateAccount data_open( ) const;
  Procent procent( ) const;

  friend std::ostream &operator<<( std::ostream &out, const Account &acc );

 private:
  //это можно выделить в пимпл
  // std::unique_ptr< AccountImpl > pImpl_;
  NumberAccount num_;
  CodeAccount code_;
  Family family_;
  SummAccount summa_;
  DateAccount data_open_;
  Procent procent_;
};

#endif // ACCOUNT_H
