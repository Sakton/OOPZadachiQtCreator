#ifndef ACCOUNT32_H
#define ACCOUNT32_H
#include <string>

class Account32 {
 public:
  Account32( const std::string& name, const std::string& acc, double proc,
             double summ );
  void Display( );
  operator std::string( ) const;

  std::string name( ) const;
  void setName( const std::string& name );

  Account32& operator+=( double sm );
  Account32& operator-=( double sm );

  friend Account32 operator+( const Account32& ac1, double sm );
  friend Account32 operator+( double sm, const Account32& ac2 );
  friend Account32 operator-( const Account32& ac1, double sm );
  friend Account32 operator-( double sm, const Account32& ac2 );

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
  double summa_;
};

#endif // ACCOUNT32_H
