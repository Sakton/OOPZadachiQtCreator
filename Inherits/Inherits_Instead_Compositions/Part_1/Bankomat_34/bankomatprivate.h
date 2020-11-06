#ifndef BANKOMATPRIVATE_H
#define BANKOMATPRIVATE_H
#include "bankomatbase.h"

class BankomatPrivate : private BankomatBase {
 public:
  //  using BankomatBase::NOMINALS;
  // enum NOMINALS, non open through private inherits
  // does not open via private inheritance
  // TODO ?? redefinition enums
  enum NOMINALS {
    NOM_10_RUR = 0,
    NOM_50_RUR,
    NOM_100_RUR,
    NOM_500_RUR,
    NOM_1000_RUR
  };
  using BankomatBase::SpecArray;

  BankomatPrivate( value_type id = 0, value_type min = 0, value_type max = 0,
                   SpecArray cassetaMoney = nullptr );
  void AddCash( SpecArray cassetaMoney );
  void SubCash( value_type summ );

  friend void Display( const BankomatPrivate &b );
  friend std::string toString( const BankomatPrivate &b );

 private:
  void ParsePoNominals( value_type summ, SpecArray arr );
};

#endif // BANKOMATPRIVATE_H
