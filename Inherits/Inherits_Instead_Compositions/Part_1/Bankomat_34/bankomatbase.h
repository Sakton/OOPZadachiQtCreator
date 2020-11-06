#ifndef BANKOMATBASE_H
#define BANKOMATBASE_H
#include <string>

class BankomatBase
{
 public:
  static constexpr int COUNT_ELEMENTS = 5;
  using value_type = int32_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using SpecArray = value_type[ COUNT_ELEMENTS ];
  enum NOMINALS {
    NOM_10_RUR = 0,
    NOM_50_RUR,
    NOM_100_RUR,
    NOM_500_RUR,
    NOM_1000_RUR
  };

  BankomatBase( value_type id = 0, value_type min = 0, value_type max = 0,
                SpecArray cassetaMoney = nullptr );
  friend std::string toString( const BankomatBase &b );
  friend void Display( const BankomatBase &b );

  value_type getMin( ) const;
  value_type getMax( ) const;

 protected:
  static constexpr int NOMIMALS_BILL[] {
      10, 50, 100, 500, 1000 };  //денежки которые может хранить банкомат

  int64_t RemainerCash( ) const;
  reference operator[]( int ind );
  const_reference operator[]( int ind ) const;

 private:
  value_type id_;
  value_type min_;
  value_type max_;
  SpecArray cash_ { 0 };
};

#endif // BANKOMATBASE_H
