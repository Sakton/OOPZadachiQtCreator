#ifndef ACCOUNT32_H
#define ACCOUNT32_H
#include <string>

//#include "money33.h"

class Account32 {
 public:
  class Money33 {
   public:
    explicit Money33( double sum = 0.0 );

    void Display( ) const;

    Money33& operator+=( const Money33& b1 );
    Money33& operator-=( const Money33& b1 );
    Money33& operator*=( const Money33& b1 );
    Money33& operator*=( double x );  // Adding

    Money33& operator/=( const Money33& b1 );
    Money33& operator/=( double x );

    friend Money33 operator+( const Money33& b1, const Money33& b2 );
    friend Money33 operator-( const Money33& b1, const Money33& b2 );
    friend Money33 operator*( const Money33& b1, const Money33& b2 );
    friend Money33 operator*( const Money33& b1, double x );  // Adding
    friend Money33 operator*( double x, const Money33& b1 );  // Adding
    friend Money33 operator/( const Money33& b1, const Money33& b2 );
    friend Money33 operator/( const Money33& b1, double x );
    friend Money33 operator/( double x, const Money33& b1 );  // Adding

    friend bool operator<( const Money33& b1, const Money33& b2 );
    friend bool operator<=( const Money33& b1, const Money33& b2 );
    friend bool operator>( const Money33& b1, const Money33& b2 );
    friend bool operator>=( const Money33& b1, const Money33& b2 );
    friend bool operator==( const Money33& b1, const Money33& b2 );
    friend bool operator!=( const Money33& b1, const Money33& b2 );

    explicit operator std::string( ) const;
    explicit operator double( ) const;

   private:
    void ParseSum( double sum );

   private:
    enum NOMINALS {
      NOM_1_COP = 0,
      NOM_5_COP,
      NOM_10_COP,
      NOM_50_COP,
      NOM_1_RUR,
      NOM_2_RUR,
      NOM_5_RUR,
      NOM_10_RUR,
      NOM_50_RUR,
      NOM_100_RUR,
      NOM_200_RUR,
      NOM_500_RUR,
      NOM_1000_RUR,
      NOM_2000_RUR,
      NOM_5000_RUR
    };
    static const int COUNT_ELEMENTS = 15;
    static const int INDEX_COP = 3;
    static const double NOMIMALS_BILL[];

    int64_t summa_[ COUNT_ELEMENTS ] { };
  };

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
  // double summa_;
  Money33 summa_;
};

#endif // ACCOUNT32_H
