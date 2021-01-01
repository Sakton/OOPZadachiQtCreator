#ifndef POLINOM33VEC_H
#define POLINOM33VEC_H
#include <iostream>
#include <string>
#include <vector>

class Polinom33Vec {
 public:
  // type defines
  using value_type = double;
  using container_type = std::vector< value_type >;
  using reference = container_type::reference;
  using const_reference = container_type::const_reference;
  using iterator = container_type::iterator;
  using const_iterator = container_type::const_iterator;
  // size type
  using size_type = container_type::size_type;

  // ctor
  explicit Polinom33Vec( size_type n = 0, value_type k = 0 );
  Polinom33Vec( value_type *beg, value_type *end );

  // operators =
  Polinom33Vec &operator+=( const Polinom33Vec &rhs );
  Polinom33Vec &operator+=( const value_type &dx );
  Polinom33Vec &operator-=( const Polinom33Vec &rhs );
  Polinom33Vec &operator-=( const value_type &dx );
  Polinom33Vec &operator*=( const value_type &dx );
  Polinom33Vec &operator/=( const value_type &dx );

  // operation
  value_type integral( value_type x );
  value_type differencial( value_type x );

  // swap
  void swap( Polinom33Vec &oth );
  void swap( Polinom33Vec &rhs, Polinom33Vec &lhs );
  // friends
  friend std::ostream &operator<<( std::ostream &out, const Polinom33Vec &p );

  friend bool operator==( const Polinom33Vec &lhs, const Polinom33Vec &rhs );
  friend bool operator!=( const Polinom33Vec &lhs, const Polinom33Vec &rhs );

  // sz
  size_type size( ) const;

 private:
  container_type coeff_;
};

const Polinom33Vec operator+( const Polinom33Vec &lhs, const Polinom33Vec &rhs );
const Polinom33Vec operator+( const Polinom33Vec &lhs, Polinom33Vec::value_type dx );
const Polinom33Vec operator+( Polinom33Vec::value_type dx, const Polinom33Vec &rhs );
const Polinom33Vec operator-( const Polinom33Vec &lhs, const Polinom33Vec &rhs );
const Polinom33Vec operator-( const Polinom33Vec &lhs, Polinom33Vec::value_type dx );
const Polinom33Vec operator-( Polinom33Vec::value_type dx, const Polinom33Vec &rhs );
const Polinom33Vec operator*( const Polinom33Vec &lhs, Polinom33Vec::value_type dx );
const Polinom33Vec operator*( Polinom33Vec::value_type dx, const Polinom33Vec &rhs );
const Polinom33Vec operator/( const Polinom33Vec &lhs, Polinom33Vec::value_type dx );
const Polinom33Vec operator/( Polinom33Vec::value_type dx, const Polinom33Vec &rhs );

#endif  // POLINOM33VEC_H
