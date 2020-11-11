#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>

class Vector {
 public:
  using type = int;
  using iterator = type *;
  using const_iterator = const type *;
  using reference = type &;
  using const_reference = const type &;

  using size_type = std::size_t;

  explicit Vector( int n = 3, int k = 0 );
  Vector( const_iterator beg, const_iterator end );
  ~Vector( );

 private:
  size_type count_;
  type *data_;
};

#endif // VECTOR_H
