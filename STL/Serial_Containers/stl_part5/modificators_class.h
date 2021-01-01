#ifndef MODIFICATORS_CLASS_H
#define MODIFICATORS_CLASS_H
#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// types defined
using type = int32_t;
using type_container = std::vector< type >;
using reference_container = type_container &;
using const_reference_container = const type_container &;
static constexpr int N = 6;

class Modificators {
 public:
  virtual type operator( )( const type &el ) = 0;
  virtual ~Modificators( ) { };
};

class Modify1 : public Modificators {
 public:
  explicit Modify1( const_reference_container cnt ) : factor_ { 0 } {
    factor_ = std::sqrt( ( *std::max_element( cnt.begin( ), cnt.end( ) ) ) *
                         cnt.back( ) );
  }
  ~Modify1( ) override {}
  type operator( )( const type &el ) override {
    return static_cast< type >( el * factor_ );
  }

 private:
  double factor_;
};

class Modify2 : public Modificators {
 public:
  explicit Modify2( const_reference_container cnt ) : polusumma_ { 0 } {
    auto el =
        std::find_if( cnt.cbegin( ), cnt.cend( ),
                      []( const type &elem ) -> bool { return elem < 0; } );
    type_container::const_iterator it = cnt.cbegin( );
    for ( int i = 0; i < N / 2; ++i ) ++it;
    polusumma_ = ( *el + *it ) / 2;
  }
  ~Modify2( ) override {}

  type operator( )( const type &elem ) override {
    if ( polusumma_ == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
    return elem / polusumma_;
  }

 private:
  type polusumma_;
};

class Modify3 : public Modificators {
 public:
  explicit Modify3( const_reference_container cnt ) : max_elem_ { 0 } {
    max_elem_ = *std::max_element( cnt.begin( ), cnt.end( ) );
    std::cout << '\n'
              << "functor3: member max_elem = " << max_elem_ << std::endl;
  }
  ~Modify3( ) {}
  type operator( )( const type &el ) override { return el - max_elem_; }

 private:
  type max_elem_;
};

class Modify4 : public Modificators {
 public:
  explicit Modify4( const_reference_container cnt ) : min_ { 0 } {
    min_ = *std::min_element( cnt.begin( ), cnt.end( ) );
    std::cout << '\n' << "functor4: member min_ = " << min_ << std::endl;
  }
  ~Modify4( ) override {}
  type operator( )( const type &el ) override { return el * min_; }

 private:
  type min_;
};

class Modify5 : public Modificators {
 public:
  explicit Modify5( const_reference_container cnt ) : srednee_arifmet_ { 0 } {
    srednee_arifmet_ = std::accumulate( cnt.cbegin( ), cnt.cend( ), 0 );
    std::cout << '\n'
              << "functor5: member srednee_arifmet_ = " << srednee_arifmet_
              << std::endl;
  }
  ~Modify5( ) override {}
  type operator( )( const type &el ) override {
    if ( std::abs( el ) % 2 != 0 ) return el / srednee_arifmet_;
    return el;
  }

 private:
  type srednee_arifmet_;
};

class Modify6 : public Modificators {
 public:
  explicit Modify6( const_reference_container cnt ) : summ_ { 0 } {
    summ_ = std::accumulate( cnt.begin( ), cnt.end( ), 0 );
    std::cout << '\n' << "functor6: member summ_ = " << summ_ << std::endl;
  }
  ~Modify6( ) override {}
  type operator( )( const type &el ) override { return el - summ_; }

 private:
  type summ_;
};

class Modify7 : public Modificators {
 public:
  explicit Modify7( const_reference_container cnt )
      : summ_first_end_negative_ { 0 } {
    for ( auto it = cnt.cbegin( ); it != cnt.cend( ); ++it ) {
      if ( *it < 0 ) {
        summ_first_end_negative_ += *it;
        break;
      }
    }
    for ( auto it = cnt.crbegin( ); it != cnt.crend( ); ++it ) {
      if ( *it < 0 ) {
        summ_first_end_negative_ += *it;
        break;
      }
    }
    summ_first_end_negative_ *= 2;
    std::cout << '\n'
              << "functor7: member summ_first_end_negative_ = "
              << summ_first_end_negative_ << std::endl;
  }

  ~Modify7( ) override {}

  type operator( )( const type &el ) override {
    ++count;
    if ( count % 3 == 0 ) {
      return el * summ_first_end_negative_;
    }
    return el;
  }

 private:
  static int count;
  type summ_first_end_negative_;
};

class Modify8 : public Modificators {
 public:
  explicit Modify8( const_reference_container cnt )
      : first_nechet_abs_ { std::numeric_limits< type >::min( ) } {
    for ( auto &el : cnt ) {
      if ( std::abs( el ) % 2 != 0 ) {
        first_nechet_abs_ = std::abs( el );
        break;
      }
    }
    std::cout << '\n'
              << "functor8: member first_nechet_abs_ = " << first_nechet_abs_
              << std::endl;
  }

  ~Modify8( ) override {}

  type operator( )( const type &el ) override { return el + first_nechet_abs_; }

 private:
  type first_nechet_abs_;
};

class Modify9 : public Modificators {
 public:
  explicit Modify9( const_reference_container cnt )
      : first_negative_ { std::numeric_limits< type >::max( ) } {
    first_negative_ =
        *std::find_if( cnt.cbegin( ), cnt.cend( ),
                       []( const type &el ) -> bool { return el < 0; } );
    std::cout << '\n'
              << "functor9: member first_negative_ = " << first_negative_
              << std::endl;
  }
  ~Modify9( ) override {}
  type operator( )( const type &el ) override {
    if ( el % 2 == 0 ) return el * first_negative_;
    return el;
  }

 private:
  type first_negative_;
};

class Modify10 : public Modificators {
 public:
  explicit Modify10( const_reference_container cnt )
      : half_last_negative_ { std::numeric_limits< type >::min( ) } {
    for ( auto it = cnt.crbegin( ); it != cnt.crend( ); ++it ) {
      if ( *it < 0 ) {
        half_last_negative_ = *it / 2;
        break;
      }
    }
    std::cout << '\n'
              << "functor10: member half_last_negative_ = "
              << half_last_negative_ << std::endl;
  }

  ~Modify10( ) {}

  type operator( )( const type &el ) override {
    return el + half_last_negative_;
  }

 private:
  type half_last_negative_;
};

class Modify11 : public Modificators {
 public:
  explicit Modify11( const_reference_container cnt )
      : half_max_ { *std::max_element( cnt.cbegin( ), cnt.cend( ) ) / 2 } {
    std::cout << '\n'
              << "functor11: member half_max_ = " << half_max_ << std::endl;
  }
  ~Modify11( ) override {}
  type operator( )( const type &el ) override {
    if ( half_max_ == 0 ) throw std::runtime_error( "DIVIDE BY ZEROmodify11 " );
    return el / half_max_;
  }

 private:
  type half_max_;
};

class Modify12 : public Modificators {
 public:
  explicit Modify12( const_reference_container cnt ) : mid_arifm_ { 0 } {
    for ( auto it = cnt.begin( ); it != cnt.end( ); ++it ) {
      mid_arifm_ += *it;
    }
    mid_arifm_ /= N;
    std::cout << '\n'
              << "functor12: member half_max_ = " << mid_arifm_ << std::endl;
  }
  type operator( )( const type &el ) override {
    return ( el == 0 ) ? mid_arifm_ : el;
  }

 private:
  type mid_arifm_;
};

class Modify13 : public Modificators {
 public:
  explicit Modify13( const_reference_container cnt )
      : quadrat_min_ { static_cast< type >(
            std::pow( *std::min_element( cnt.begin( ), cnt.end( ) ), 2 ) ) } {
    std::cout << '\n'
              << "functor13: member quadrat_min_ = " << quadrat_min_
              << std::endl;
  }
  ~Modify13( ) {}
  type operator( )( const type &el ) override {
    return ( el > 0 ) ? quadrat_min_ : el;
  }

 private:
  type quadrat_min_;
};

class Modify14 : public Modificators {
 public:
  explicit Modify14( const_reference_container cnt )
      : polusumma_nagative_ { 0 } {
    //    for ( auto &el : cnt )
    //      if ( el < 0 ) polusumma_nagative_ += el;
    polusumma_nagative_ =
        std::accumulate( cnt.cbegin( ), cnt.cend( ), 0,
                         []( type el1, type el2 ) {
                           return ( el1 += ( el2 < 0 ) ? el2 : 0 );
                         } ) >>
        1;
    std::cout << '\n'
              << "functor14: member polusumma_nagative_ = "
              << polusumma_nagative_ << std::endl;
  }
  ~Modify14( ) {}
  type operator( )( const type &el ) override {
    return el + polusumma_nagative_;
  }

 private:
  type polusumma_nagative_;
};

class Modify15 : public Modificators {
 public:
  explicit Modify15( const_reference_container cnt ) : mid_min_max_ { 0 } {
    auto p = std::minmax_element( cnt.begin( ), cnt.end( ) );
    mid_min_max_ = ( std::abs( *p.first ) + std::abs( *p.second ) ) >> 1;
    std::cout << '\n'
              << "functor15: member mid_min_max_ = " << mid_min_max_
              << std::endl;
  }
  ~Modify15( ) override {}
  type operator( )( const type &el ) override { return el + mid_min_max_; }

 private:
  type mid_min_max_;
};

class Modify16 : public Modificators {
 public:
  explicit Modify16( const_reference_container cnt )
      : min_max_ { std::minmax_element( cnt.cbegin( ), cnt.cend( ) ) } {
    std::cout << '\n'
              << "functor16: member min_max_ = " << *min_max_.first << " : "
              << *min_max_.second << std::endl;
  }

  ~Modify16( ) override {}
  type operator( )( const type &el ) override {
    return ( el / ( *min_max_.first ) ) + ( *min_max_.second );
  }

 private:
  std::pair< type_container::const_iterator, type_container::const_iterator >
      min_max_;
};

class Modify17 : public Modificators {
 public:
  explicit Modify17( const_reference_container cnt )
      : max_ { *std::max_element( cnt.begin( ), cnt.end( ) ) } {
    std::cout << '\n' << "functor17: member max_ = " << max_ << std::endl;
  }
  ~Modify17( ) override {}
  type operator( )( const type &el ) override { return ( el > 0 ) ? max_ : el; }

 private:
  type max_;
};

class Modify18 : public Modificators {
 public:
  explicit Modify18( const_reference_container cnt )
      : min_max_ { std::minmax_element( cnt.begin( ), cnt.end( ) ) } {
    std::cout << '\n'
              << "functor18: member min_max_ = " << *min_max_.first << " : "
              << *min_max_.second << std::endl;
  }
  ~Modify18( ) override {}
  type operator( )( const type &el ) override {
    if ( std::abs( el ) % 2 == 0 ) return *min_max_.second - *min_max_.first;
    return el;
  }

 private:
  std::pair< type_container::const_iterator, type_container::const_iterator >
      min_max_;
};

class Modify19 : public Modificators {
 public:
  explicit Modify19( const_reference_container cnt )
      : half_max_ { *std::max_element( cnt.begin( ), cnt.end( ) ) / 2 } {
    std::cout << '\n'
              << "functor19: member half_max_ = " << half_max_ << std::endl;
  }
  ~Modify19( ) {}
  type operator( )( const type &el ) override {
    ++count;
    if ( count % 2 == 0 && el < 0 ) return half_max_;
    return el;
  }

 private:
  static int count;
  type half_max_;
};

class Modify20 : public Modificators {
 public:
  explicit Modify20( const_reference_container cnt ) : middle_arifmetic_ { 0 } {
    middle_arifmetic_ = std::accumulate( cnt.begin( ), cnt.end( ), 0 ) >> 1;
    std::cout << '\n'
              << "functor20: member middle_arifmetic_ = " << middle_arifmetic_
              << std::endl;
  }

  ~Modify20( ) override {}

  type operator( )( const type &el ) override {
    ++count;
    if ( count % 3 == 0 && el > 0 ) {
      return middle_arifmetic_;
    }
    return el;
  }

 private:
  static int count;
  type middle_arifmetic_;
};

#endif  // MODIFICATORS_CLASS_H
