#ifndef MODIFICATORS_CLASS_H
#define MODIFICATORS_CLASS_H
#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

// types defined
using type = int32_t;
using type_container = std::vector< type >;
using reference_container = type_container &;
using const_reference_container = const type_container &;

class Modificators {
 public:
  virtual void operator( )( type &el ) = 0;
  virtual ~Modificators( ) { };
};

class Modify1 : public Modificators {
 public:
  Modify1( const_reference_container cnt ) {
    factor_ = std::sqrt( std::abs(
        *std::max_element( cnt.begin( ), cnt.end( ) ) * cnt.back( ) ) );
  }
  ~Modify1( ) override {}
  void operator( )( type &el ) override { el *= factor_; }

 private:
  double factor_;
};

class Modify2 : public Modificators {
 public:
  Modify2( const_reference_container cnt ) {}

 private:
  type polusumma_;
};

#endif  // MODIFICATORS_CLASS_H
