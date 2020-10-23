#ifndef ACCOUNT32_H
#define ACCOUNT32_H
#include <string>

//#include "date29.h"

class Account32 {
 public:
  class Date29 {
    constexpr static int monats[ 12 ] { 31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31 };

   public:
    Date29( int16_t y, int16_t m, int16_t d );
    Date29( const std::string& dt );
    Date29( const Date29& dt );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    Date29 AddDay( int days ) const;
    Date29 SubDay( int days ) const;
    int16_t Interval( const Date29& other ) const;
    bool IsVisokosny( ) const;

    int16_t Year( ) const;
    void setYear( const int16_t& y );
    int16_t Month( ) const;
    void setMonth( const int16_t& m );
    int16_t Day( ) const;
    void setDay( const int16_t& d );

   private:
    int16_t y_;
    int16_t m_;
    int16_t d_;
  };

  Account32( const std::string& name, const std::string& acc, double proc,
             double summ, const Date29& date_open );
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
  Date29 date_open_;
};

#endif // ACCOUNT32_H
