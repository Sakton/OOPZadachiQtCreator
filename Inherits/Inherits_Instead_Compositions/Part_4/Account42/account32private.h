#ifndef ACCOUNT32PRIVATE_H
#define ACCOUNT32PRIVATE_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

#include "account32.h"

class Account32private : private Money33 {
 public:
  Account32private( const std::string& name, const std::string& acc,
                    double proc, double summ );
  void Display( );
  operator std::string( ) const;

  std::string name( ) const;
  void setName( const std::string& name );

  Account32private& operator+=( double sm );
  Account32private& operator-=( double sm );

  friend Account32private operator+( const Account32private& ac1, double sm );
  friend Account32private operator+( double sm, const Account32private& ac2 );
  friend Account32private operator-( const Account32private& ac1, double sm );
  friend Account32private operator-( double sm, const Account32private& ac2 );

  void AddProcent( );
  double ToDollar( double cours ) const;
  double ToEuro( double cours ) const;
  std::string ToChislitelnoe( ) const;

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
};

#endif // ACCOUNT32PRIVATE_H
