#ifndef BASEMONEY_H
#define BASEMONEY_H
#include <string>

class BaseMoney
{
 public:
  explicit BaseMoney( double sum = 0.0 );
  explicit operator std::string( ) const;
  explicit operator double( ) const;

  friend void Display( const BaseMoney& b );

 private:
  void ParseSum( double sum );

 protected:
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

 private:
  int64_t summa_[ COUNT_ELEMENTS ] { };
};

#endif // BASEMONEY_H
