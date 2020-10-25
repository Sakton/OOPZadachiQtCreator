#ifndef ACCOUNTPRIVATE_H
#define ACCOUNTPRIVATE_H
#include "baseaccount.h"

class AccountPrivate : BaseAccount {
 public:
  AccountPrivate( const std::string& name, const std::string& acc, double proc,
                  double summ );

  friend std::string ToString( const AccountPrivate& ap );
  friend void Display( const AccountPrivate& ap );

  void AddSumm( double sm );
  void SubSumm( double sm );
  void AddProcent( );
  double ToDollar( double cours );
  double ToEuro( double cours );
  std::string ToChislitelnoe( );

 private:
  std::string Sotni( int chislo );
  std::string Desyatki( int chislo );
  std::string Edinitsy( int chislo );
  std::string ParseSotni( int chislo );
  std::string ParseThousand( int chislo );
};

#endif // ACCOUNTPRIVATE_H
