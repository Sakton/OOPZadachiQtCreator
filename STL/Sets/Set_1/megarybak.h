#ifndef MEGARYBAK_H
#define MEGARYBAK_H
#include "rybak.h"

class MegaRybak : public Rybak {
 public:
  MegaRybak();
  void addConcreteFish( Ozero* o, int id );
  void megaUlov( Ozero* o );
};

#endif // MEGARYBAK_H
