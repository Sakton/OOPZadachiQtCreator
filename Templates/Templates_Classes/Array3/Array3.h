#ifndef ARRAY3_H
#define ARRAY3_H
#include <cstdint>

template < typename T, std::int32_t F, std::int32_t S >
class Array3 {
 public:
  // type definitions
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

  // size type definition
  using size_type = std::int32_t;

  // static size
  static constexpr size_type SIZE_ = S - F;

  // iterator type definition
  using iterator = T *;
  using const_iterator = const T *;

  Array3( );
  Array3( iterator first, iterator second );

  // sizes

  // iterators

  //

 private:
  T *elem_;
  size_type count_;
};

#endif // ARRAY3_H
