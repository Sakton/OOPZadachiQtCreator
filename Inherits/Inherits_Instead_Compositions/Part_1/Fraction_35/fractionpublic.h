#ifndef FRACTIONPUBLIC_H
#define FRACTIONPUBLIC_H
#include "fractionbase.h"

// TODO ДОДЕЛАТЬ и переделать
// пока оставить

class FractionPublic : public FractionBase {
 public:
  FractionPublic( int64_t w = 0, int16_t f = 0 );

  FractionPublic &operator+=( const FractionPublic &fr );
  FractionPublic &operator-=( const FractionPublic &fr );
  FractionPublic &operator*=( const FractionPublic &fr );
  //  FractionPublic &operator/=( const FractionPublic &fr );

  friend FractionPublic operator+( const FractionPublic &fr1,
                                   const FractionPublic &fr2 );
  friend FractionPublic operator-( const FractionPublic &fr1,
                                   const FractionPublic &fr2 );
  friend FractionPublic operator*( const FractionPublic &fr1,
                                   const FractionPublic &fr2 );
  //  friend FractionPublic operator/( const FractionPublic &fr1,
  //                                   const FractionPublic &fr2 );

  friend bool operator==( const FractionPublic &fr1,
                          const FractionPublic &fr2 );
  friend bool operator!=( const FractionPublic &fr1,
                          const FractionPublic &fr2 );
  friend bool operator>( const FractionPublic &fr1, const FractionPublic &fr2 );
  friend bool operator>=( const FractionPublic &fr1,
                          const FractionPublic &fr2 );
  friend bool operator<( const FractionPublic &fr1, const FractionPublic &fr2 );
  friend bool operator<=( const FractionPublic &fr1,
                          const FractionPublic &fr2 );

 private:
  FractionPublic AddModul( const FractionPublic &a,
                           const FractionPublic &b ) const;
  FractionPublic SubModul( const FractionPublic &a,
                           const FractionPublic &b ) const;
  FractionPublic MulModul( const FractionPublic &a,
                           const FractionPublic &b ) const;
  FractionPublic MulDesyatki( int mul ) const;
  FractionPublic MulOneNumber( int num ) const;
  FractionPublic Modul( const FractionPublic &a ) const;
  FractionPublic OneDivFrac( const FractionPublic &a ) const;
  bool LessMod( const FractionPublic &b ) const;
  bool EqModul( const FractionPublic &b ) const;
};

#endif // FRACTIONPUBLIC_H
