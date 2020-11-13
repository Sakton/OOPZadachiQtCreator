#ifndef ARRAY_H
#define ARRAY_H

namespace MY {

class Array {
 public:
  // type defines
  using value_type = double;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  // sz
  using size_type = size_t;

  explicit Array( size_type n, const value_type &d = 0 );
  Array( const_iterator beg, const_iterator end );
};

}  // namespace MY

#endif  // ARRAY_H
