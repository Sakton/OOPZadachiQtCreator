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
static constexpr int N = 6;

class Modificators {
 public:
  virtual void operator( )( type &el ) = 0;
  virtual ~Modificators( ) { };
};

class Modify1 : public Modificators {
 public:
  Modify1( const_reference_container cnt ) : factor_ { 0 } {
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
  Modify2( const_reference_container cnt ) : polusumma_ { 0 } {
    auto el =
        std::find_if( cnt.cbegin( ), cnt.cend( ),
                      []( const type &elem ) -> bool { return elem < 0; } );
    type_container::const_iterator it = cnt.cbegin( );
    for ( int i = 0; i < N / 2; ++i ) ++it;
    polusumma_ = ( *el + *it ) / 2;
  }

  ~Modify2( ) override {}

  void operator( )( type &elem ) override {
    if ( polusumma_ == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
    elem /= polusumma_;
  }

 private:
  type polusumma_;
};

class Modify3 : public Modificators {
 public:
  Modify3( const_reference_container cnt ) : max_elem_ { 0 } {
    max_elem_ = *std::max_element( cnt.begin( ), cnt.end( ) );
    std::cout << '\n'
              << "functor3: member max_elem = " << max_elem_ << std::endl;
  }
  ~Modify3( ) {}
  void operator( )( type &el ) override { el -= max_elem_; }

 private:
  type max_elem_;
};

class Modify4 : public Modificators {
 public:
  Modify4( const_reference_container cnt ) : min_ { 0 } {
    min_ = *std::min_element( cnt.begin( ), cnt.end( ) );
    std::cout << '\n' << "functor4: member min_ = " << min_ << std::endl;
  }
  ~Modify4( ) override {}
  void operator( )( type &el ) override { el *= min_; }

 private:
  type min_;
};

class Modify5 : public Modificators {
 public:
  Modify5( const_reference_container cnt ) : srednee_arifmet_ { 0 } {
    for ( auto &el : cnt ) srednee_arifmet_ += el;
    srednee_arifmet_ /= N;
    std::cout << '\n'
              << "functor5: member srednee_arifmet_ = " << srednee_arifmet_
              << std::endl;
  }
  ~Modify5( ) override {}
  void operator( )( type &el ) override {
    if ( std::abs( el ) % 2 != 0 ) el /= srednee_arifmet_;
  }

 private:
  type srednee_arifmet_;
};

class Modify6 : public Modificators {
 public:
  Modify6( const_reference_container cnt ) : summ_ { 0 } {
    for ( auto &el : cnt ) summ_ += el;
    std::cout << '\n' << "functor6: member summ_ = " << summ_ << std::endl;
  }
  ~Modify6( ) override {}
  void operator( )( type &el ) override { el -= summ_; }

 private:
  type summ_;
};

class Modify7 : public Modificators {
 public:
  Modify7( const_reference_container cnt ) : summ_first_end_negative_ { 0 } {
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

  void operator( )( type &el ) override {
    static int count = 1;
    if ( count % 3 == 0 ) {
      el *= summ_first_end_negative_;
    }
    ++count;
  }

 private:
  type summ_first_end_negative_;
};

class Modify8 : public Modificators {
 public:
  Modify8( const_reference_container cnt )
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

  void operator( )( type &el ) override { el += first_nechet_abs_; }

 private:
  type first_nechet_abs_;
};

class Modify9 : public Modificators {
 public:
  Modify9( const_reference_container cnt )
      : first_negative_ { std::numeric_limits< type >::max( ) } {
    for ( auto &el : cnt ) {
      if ( el < 0 ) {
        first_negative_ = el;
        break;
      }
    }
    std::cout << '\n'
              << "functor9: member first_negative_ = " << first_negative_
              << std::endl;
  }
  ~Modify9( ) override {}
  void operator( )( type &el ) override {
    if ( el % 2 == 0 ) el *= first_negative_;
  }

 private:
  type first_negative_;
};

class Modify10 : public Modificators {
 public:
  Modify10( const_reference_container cnt )
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

  void operator( )( type &el ) override { el += half_last_negative_; }

 private:
  type half_last_negative_;
};

class Modify11 : public Modificators {
 public:
  Modify11( const_reference_container cnt )
      : half_max_ { *std::max_element( cnt.cbegin( ), cnt.cend( ) ) / 2 } {
    std::cout << '\n'
              << "functor11: member half_max_ = " << half_max_ << std::endl;
  }
  ~Modify11( ) override {}
  void operator( )( type &el ) override {
    if ( half_max_ == 0 ) throw std::runtime_error( "DIVIDE BY ZERO modify11" );
    el /= half_max_;
  }

 private:
  type half_max_;
};

class Modify12 : public Modificators {
 public:
  Modify12( const_reference_container cnt ) : mid_arifm_ { 0 } {
    for ( auto it = cnt.begin( ); it != cnt.end( ); ++it ) {
      mid_arifm_ += *it;
    }
    mid_arifm_ /= N;
    std::cout << '\n'
              << "functor12: member half_max_ = " << mid_arifm_ << std::endl;
  }
  void operator( )( type &el ) override { el = ( el == 0 ) ? mid_arifm_ : el; }

 private:
  type mid_arifm_;
};

class Modify13 : public Modificators {
 public:
  Modify13( const_reference_container cnt )
      : quadrat_min_ { static_cast< type >(
            std::pow( *std::min_element( cnt.begin( ), cnt.end( ) ), 2 ) ) } {
    std::cout << '\n'
              << "functor13: member quadrat_min_ = " << quadrat_min_
              << std::endl;
  }
  ~Modify13( ) {}
  void operator( )( type &el ) override { el = ( el > 0 ) ? quadrat_min_ : el; }

 private:
  type quadrat_min_;
};

class Modify14 : public Modificators {
 public:
  Modify14( const_reference_container cnt ) : polusumma_nagative_ { 0 } {
    for ( auto &el : cnt )
      if ( el < 0 ) polusumma_nagative_ += el;
    polusumma_nagative_ >>= 1;
    std::cout << '\n'
              << "functor14: member polusumma_nagative_ = "
              << polusumma_nagative_ << std::endl;
  }
  ~Modify14( ) {}
  void operator( )( type &el ) { el += polusumma_nagative_; }

 private:
  type polusumma_nagative_;
};

#endif  // MODIFICATORS_CLASS_H
