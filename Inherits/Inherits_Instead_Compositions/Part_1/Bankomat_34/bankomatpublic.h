#ifndef BANKOMATPUBLIC_H
#define BANKOMATPUBLIC_H
#include "bankomatbase.h"

class BankomatPublic : public BankomatBase {
 public:
  BankomatPublic( value_type id = 0, value_type min = 0, value_type max = 0,
                  SpecArray cassetaMoney = nullptr );

  void AddCash( SpecArray cassetaMoney );
  void SubCash( value_type summ );

 private:
  void ParsePoNominals( value_type summ, SpecArray arr );
};

#endif // BANKOMATPUBLIC_H
