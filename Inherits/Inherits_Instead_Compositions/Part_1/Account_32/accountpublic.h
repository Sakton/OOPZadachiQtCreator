#ifndef ACCOUNTPUBLIC_H
#define ACCOUNTPUBLIC_H
#include "baseaccount.h"

class AccountPublic : public BaseAccount {
 public:
  AccountPublic( const std::string& name, const std::string& acc, double proc,
                 double summ );

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
  // std::string ParseMillion( int chislo );
};

#endif // ACCOUNTPUBLIC_H
