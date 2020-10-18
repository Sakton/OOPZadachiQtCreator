#ifndef BANKOMAT34_H
#define BANKOMAT34_H
#include <string>

class Bankomat34 {
 public:
  static constexpr int COUNT_ELEMENTS = 5;
  using SpecArray = int16_t[ COUNT_ELEMENTS ];
  enum NOMINALS {
    NOM_10_RUR = 0,
    NOM_50_RUR,
    NOM_100_RUR,
    NOM_500_RUR,
    NOM_1000_RUR
  };

  Bankomat34( int32_t id = 0, int32_t min = 0, int32_t max = 0,
              SpecArray cassetaMoney = nullptr );
  friend void Display( const Bankomat34& bn );
  // void Read( );
  // std::string ToString( );
  explicit operator std::string( ) const;
  friend void AddCash( Bankomat34& bn, SpecArray cassetaMoney );
  friend void SubCash( Bankomat34& bn, int32_t summ );

  // private:
  friend void ParsePoNominals( /*const Bankomat34& bn, */ int32_t summ,
                               SpecArray arr );
  friend int64_t RemainerCash( const Bankomat34& bn );

 private:
  static constexpr int NOMIMALS_BILL[] {
      10, 50, 100, 500, 1000 };  //денежки которые может хранить банкомат

  int32_t id_;
  int32_t min_;
  int32_t max_;
  SpecArray cash_ { 0 };
};
//lslslslslsl

#endif // BANKOMAT34_H
