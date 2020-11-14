#ifndef POLIGON_H
#define POLIGON_H
#include <memory>

class Poligon
{
 public:
  // type defines
  using type = double;
  using value_type = std::pair< type, type >;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  // sz
  using size_type = size_t;

  // ctor/cpu
  Poligon( const value_type points[], size_type n );
  Poligon( const_iterator beg, const_iterator end );
  Poligon( const Poligon &oth );
  Poligon( Poligon &&oth );
  const Poligon &operator=( const Poligon &oth );
  const Poligon &operator=( Poligon &&oth );

  // iterators
  const_iterator begin( ) const;
  const_iterator end( ) const;
  iterator begin( );
  iterator end( );

  // indexes
  const_reference operator[]( size_type idx ) const;
  reference operator[]( size_type idx );

  // area
  double area( ) const;
  double perimetr( ) const;
  // bool intersection( const Poligon &other ) const; // возня с формулой, пропуск пока

 private:
  void validIndex( size_type idx ) const;
  double lenStraight( const_reference a, const_reference b ) const;

 private:
  size_type size_;
  std::unique_ptr< value_type[] > data_;
};

#endif // POLIGON_H
