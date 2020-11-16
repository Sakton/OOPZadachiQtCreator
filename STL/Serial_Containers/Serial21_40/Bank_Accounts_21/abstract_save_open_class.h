#ifndef ABSTRACT_SAVE_OPEN_CLASS_H
#define ABSTRACT_SAVE_OPEN_CLASS_H
#include <fstream>

class abstract_save_open_class {
 public:
  virtual ~abstract_save_open_class( ) {}
  virtual bool save( std::ofstream& out ) = 0;
  virtual bool read( std::ifstream& in ) = 0;
};

#endif  // ABSTRACT_SAVE_OPEN_CLASS_H
