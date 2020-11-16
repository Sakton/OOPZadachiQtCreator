#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <vector>

#include "account.h"

template < typename T, typename Container = std::vector< T > >
class BankAccounts {
 public:
  BankAccounts( );

 private:
  Container container_;
};

#endif // BANKACCOUNT_H
