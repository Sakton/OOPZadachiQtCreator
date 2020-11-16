#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "codeaccount.h"
#include "dateaccount.h"
#include "family.h"
#include "numberaccount.h"
#include "procent.h"
#include "summaccount.h"

//пустые аккаунты недопустимы

class Account : public abstract_save_open_class {
 public:
  Account( const NumberAccount &num, const CodeAccount &code/*, const Family &family, const SummAccount &summa = SummAccount( ),
           const DateAccount &date_ = DateAccount( ), const Procent &procent = Procent( ) */);
  ~Account( ) override;
  bool save( std::ofstream &out ) override;
  bool read( std::ifstream &in ) override;

  friend std::ostream &operator<<( std::ostream &out, const Account &acc );

 private:
  NumberAccount num_;
  CodeAccount code_;
  //  Family family_;
  //  SummAccount summa_;
  //  DateAccount data_open_;
  //  Procent procent_;
};

#endif // ACCOUNT_H
