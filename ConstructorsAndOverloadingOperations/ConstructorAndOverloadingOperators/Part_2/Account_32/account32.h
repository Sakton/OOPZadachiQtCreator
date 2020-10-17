#ifndef ACCOUNT32_H
#define ACCOUNT32_H
#include <string>

class Account32 {
 public:
  Account32( const std::string& name, const std::string& acc, double proc,
             double summ );
  // void Read( );
  friend void Display( const Account32& ac );
  operator std::string( ) const;
  // std::string ToString( ) const;

  friend std::string name( const Account32& ac );
  friend void setName( Account32& ac, const std::string& name );
  friend void AddSumm( Account32& ac, double sm );
  friend void SubSumm( Account32& ac, double sm );
  friend void AddProcent( Account32& ac );
  friend double ToDollar( const Account32& ac, double cours );
  friend double ToEuro( const Account32& ac, double cours );
  friend std::string ToChislitelnoe( const Account32& ac );

  // private:
  friend std::string Sotni( const Account32&, int chislo );
  friend std::string Desyatki( const Account32&, int chislo );
  friend std::string Edinitsy( const Account32&, int chislo );
  friend std::string ParseSotni( const Account32&, int chislo );
  friend std::string ParseThousand( const Account32&, int chislo );
  friend std::string ParseMillion( const Account32&, int chislo );

 private:
  std::string name_;
  std::string accountNum_;
  double procent_;
  double summa_;
};

#endif // ACCOUNT32_H
