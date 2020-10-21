#ifndef MONEY33_H
#define MONEY33_H
#include <string>

class Money33 {
 public:
  explicit Money33( double sum = 0.0 );
  friend void Display( const Money33& b );

  friend Money33 operator+( const Money33& b1, const Money33& b2 );
  friend Money33 operator-( const Money33& b1, const Money33& b2 );
  friend Money33 operator*( const Money33& b1, const Money33& b2 );
  friend Money33 operator/( const Money33& b1, const Money33& b2 );
  friend Money33 operator/( const Money33& b1, double x );

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

#endif // MONEY33_H
