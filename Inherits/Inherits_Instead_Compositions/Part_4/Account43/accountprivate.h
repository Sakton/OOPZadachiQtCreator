#ifndef ACCOUNTPRIVATE_H
#define ACCOUNTPRIVATE_H
#include <string>

#include "date29.h"

class AccountPrivate : private Date29 {
 public:
  AccountPrivate( const std::string& name, const std::string& acc, double proc,
                  double summ, const std::string& date_open );
  void Display( );
  operator std::string( ) const;

  std::string name( ) const;
  void setName( const std::string& name );

  AccountPrivate& operator+=( double sm );
  AccountPrivate& operator-=( double sm );

  friend AccountPrivate operator+( const AccountPrivate& ac1, double sm );
  friend AccountPrivate operator+( double sm, const AccountPrivate& ac2 );
  friend AccountPrivate operator-( const AccountPrivate& ac1, double sm );
  friend AccountPrivate operator-( double sm, const AccountPrivate& ac2 );

  void AddProcent( );
  double ToDollar( double cours ) const;
  double ToEuro( double cours ) const;
  std::string ToChislitelnoe( ) const;

  void AddingProcentToDayCount( const Date29& dt );

 private:
  std::string Sotni( int chislo ) const;
  std::string Desyatki( int chislo ) const;
  std::string Edinitsy( int chislo ) const;
  std::string ParseSotni( int chislo ) const;
  std::string ParseThousand( int chislo ) const;
  std::string ParseMillion( int chislo ) const;

 private:
  std::string name_;
  std::string accountNum_;
  double procent_;
  double summa_;
};

#endif // ACCOUNTPRIVATE_H
