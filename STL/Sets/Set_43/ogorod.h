#ifndef OGOROD_H
#define OGOROD_H
#include <iostream>
#include <memory>
#include <set>

#include "fabriqueculture.h"

class Ogorod
{
 public:
  Ogorod( );

  friend std::ostream &operator<<( std::ostream &out, const Ogorod &og );
  friend Ogorod operator+( const Ogorod &o1, const Ogorod &o2 );
  friend Ogorod operator-( const Ogorod &o1, const Ogorod &o2 );
  friend Ogorod operator/( const Ogorod &o1, const Ogorod &o2 );

  void clear( );

 private:
  void getRandomCulture( );

 private:
  std::set< std::shared_ptr< AbstractCulture >, CulturePredicat > cult_;
};

#endif // OGOROD_H
