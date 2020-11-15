#ifndef BINARY_H
#define BINARY_H
#include <memory>

class Binary {
 public:
  // type define
  using value_type = unsigned char;
  using refernce = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  // sz
  using size_type = size_t;
  Binary( size_type n );
  Binary( );

 private:
  size_type size_;
  std::unique_ptr< value_type[] > data_;
};

#endif // BINARY_H
