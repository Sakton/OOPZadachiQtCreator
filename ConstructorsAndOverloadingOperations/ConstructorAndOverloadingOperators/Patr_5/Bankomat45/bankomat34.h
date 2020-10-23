#ifndef BANKOMAT34_H
#define BANKOMAT34_H
#include <string>

//#include "money33.h"

class Bankomat34 {
 public:
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

  Bankomat34( int32_t id = 0, int32_t min = 0, int32_t max = 0,
              Money33 cash = Money33( ) );
  void Display( ) const;
  operator double( ) const;
  explicit operator std::string( ) const;

  void AddCash( double money );
  void SubCash( double summ );

 private:
  int32_t id_;
  int32_t min_;
  int32_t max_;
  Money33 cash_;
};

#endif // BANKOMAT34_H
