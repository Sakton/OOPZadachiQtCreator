#include <algorithm>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

static const std::string PATH = "../../stl_part1/Files/";
static constexpr int N = 6;

using type = int32_t;
using type_container = std::deque< type >;
// using type_container = std::list< type >;
// using type_container = std::vector< type >;
using reference_container = type_container &;
using const_reference_container = const type_container &;

const std::string createFile( const std::string &name_file );
type_container inputFile( const std::string &name_file );
void tasks( reference_container ( *modificator )( reference_container c ) );

// modificators
reference_container modify1( reference_container c );
reference_container modify2( reference_container c );
reference_container modify3( reference_container c );
reference_container modify4( reference_container c );
reference_container modify5( reference_container c );
reference_container modify6( reference_container c );
reference_container modify7( reference_container c );
reference_container modify8( reference_container c );
reference_container modify9( reference_container c );
reference_container modify10( reference_container c );
reference_container modify11( reference_container c );
reference_container modify12( reference_container c );
reference_container modify13( reference_container c );
reference_container modify14( reference_container c );
reference_container modify15( reference_container c );
reference_container modify16( reference_container c );
reference_container modify17( reference_container c );
reference_container modify18( reference_container c );
reference_container modify19( reference_container c );
reference_container modify20( reference_container c );

int main( ) {
  using modify = reference_container ( * )( reference_container c );
  // change this
  modify modificator = modify20;
  //***
  try {
    tasks( modificator );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( ... ) {
    std::cerr << "OTHER ERROR" << std::endl;
  }

  return 0;
}

const std::string createFile( const std::string &name_file ) {
  std::ofstream ofile( PATH + name_file );
  if ( !ofile.is_open( ) ) throw std::runtime_error( "NO OPEN FILE" );
  std::srand( std::time( nullptr ) );
  for ( int i = 0; i < N; ++i ) {
    int rand = std::rand( ) % 50;
    if ( !( rand % 3 ) ) rand *= -1;
    ofile << rand << '\n';
  }
  return PATH + name_file;
}

type_container inputFile( const std::string &name_file ) {
  type_container res;
  std::ifstream ifile( name_file );
  if ( !ifile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int x = 0;
  while ( ifile ) {
    ifile >> std::skipws >> x;
    if ( !ifile.eof( ) )
      res.push_back( x );  // in order not to write the last one twice
  }
  return res;
}

// tasks driver
void tasks( reference_container ( *modificator )( reference_container c ) ) {
  type_container v = inputFile( createFile( "input.txt" ) );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
  std::cout << '\n'
            << "***************************************************************"
               "************"
            << std::endl;
  modificator( v );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
}

reference_container modify1( reference_container c ) {
  auto max_iterator = std::max_element( c.cbegin( ), c.cend( ) );
  auto factor = std::sqrt( std::abs( ( *max_iterator ) * c.back( ) ) );
  for ( auto &el : c ) el *= factor;
  return c;
}

struct Pred2 {
  bool operator( )( int a ) { return a < 0; }
};

reference_container modify2( reference_container c ) {
  auto el = std::find_if( c.cbegin( ), c.cend( ), Pred2( ) );
  if ( el == c.end( ) ) throw std::runtime_error( "NO NEGATIVE ELEMENT" );
  //  std::cout << "elem < 0 => " << *el << std::endl;
  type_container::const_iterator it = c.cbegin( );
  for ( int i = 0; i < N / 2; ++i )
    ++it;  //??? может как то лучше можно прыгнуть сразу в середину любого
           //контейнера
  //  std::cout << "elem2 n/2 " << *it << std::endl;
  auto polusumma = ( *el + *it ) / 2;
  if ( polusumma == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  for ( auto &el : c ) el /= polusumma;
  return c;
}

reference_container modify3( reference_container c ) {
  auto max_elem = *std::max_element( c.begin( ), c.end( ) );
  for ( auto &el : c ) el -= max_elem;
  return c;
}

reference_container modify4( reference_container c ) {
  auto min_elem = *std::min_element( c.begin( ), c.end( ) );
  for ( auto &el : c ) el *= min_elem;
  return c;
}

reference_container modify5( reference_container c ) {
  auto sum = 0;
  for ( auto &el : c ) sum += el;
  sum /= N;
  if ( sum == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  for ( auto &el : c ) {
    if ( ( std::abs( el ) % 2 ) ) {
      el /= sum;
    }
  }
  return c;
}

reference_container modify6( reference_container c ) {
  auto summ = 0;
  for ( auto &el : c ) summ += el;
  for ( auto &el : c ) el -= summ;
  return c;
}

reference_container modify7( reference_container c ) {
  auto dvoin_summa = 0;
  for ( auto it = c.cbegin( ); it != c.cend( ); ++it ) {
    if ( *it < 0 ) {
      dvoin_summa += *it;
      break;
    }
  }

  for ( auto it = c.crbegin( ); it != c.crend( ); ++it ) {
    if ( *it < 0 ) {
      dvoin_summa += *it;
      break;
    }
  }

  dvoin_summa *= 2;
  std::cout << "dvoin_summa = " << dvoin_summa << std::endl;
  int idx = 1;
  for ( auto &el : c ) {
    if ( !( idx % 3 ) ) el *= dvoin_summa;
    ++idx;
  }
  return c;
}

reference_container modify8( reference_container c ) {
  auto first_nechet = 0;
  for ( auto &el : c ) {
    if ( std::abs( el ) % 2 ) {
      first_nechet = el;
      break;
    }
  }
  for ( auto &el : c ) el += first_nechet;
  return c;
}

reference_container modify9( reference_container c ) {
  auto first_nagative = 0;
  for ( auto &el : c )
    if ( el < 0 ) {
      first_nagative = el;
      break;
    }
  for ( auto &el : c ) {
    if ( !( std::abs( el ) % 2 ) ) {
      el *= first_nagative;
    }
  }
  return c;
}

reference_container modify10( reference_container c ) {
  auto mnog = 0;
  for ( auto it = c.crbegin( ); it != c.crend( ); ++it ) {
    if ( *it < 0 ) {
      mnog = *it / 2;
      break;
    };
  }
  for ( auto &el : c ) {
    el += mnog;
  }
  return c;
}

reference_container modify11( reference_container c ) {
  auto half_max = *std::max_element( c.cbegin( ), c.cend( ) ) / 2;
  if ( half_max == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  for ( auto &el : c ) {
    el /= half_max;
  }
  return c;
}

reference_container modify12( reference_container c ) {
  auto middle_arifmetic = 0;
  for ( auto &el : c ) middle_arifmetic += el;
  middle_arifmetic /= N;
  std::cout << "middle_arifmetic = " << middle_arifmetic << std::endl;
  for ( auto &el : c ) el = ( el != 0 ) ? el : middle_arifmetic;
  return c;
}

reference_container modify13( reference_container c ) {
  auto sqr_min_elem =
      std::pow( *std::min_element( c.cbegin( ), c.cend( ) ), 2 );
  for ( auto &el : c ) el = ( el > 0 ) ? sqr_min_elem : el;
  return c;
}

reference_container modify14( reference_container c ) {
  auto half_nagative = 0;
  for ( auto &el : c ) {
    if ( el < 0 ) half_nagative += el;
  };
  half_nagative >>= 1;
  std::cout << "half_nagative = " << half_nagative << std::endl;
  for ( auto &el : c ) el += half_nagative;
  return c;
}

reference_container modify15( reference_container c ) {
  std::pair< type, type > para_min_max { 0, 0 };
  for ( auto &el : c ) {
    if ( para_min_max.first < std::abs( el ) )
      para_min_max.first = std::abs( el );
    if ( para_min_max.second > std::abs( el ) )
      para_min_max.second = std::abs( el );
  }
  auto middle_min_max = ( para_min_max.first + para_min_max.second ) / 2;
  std::cout << "middle_min_max = " << middle_min_max << std::endl;
  for ( auto &el : c ) el += middle_min_max;
  return c;
}

reference_container modify16( reference_container c ) {
  auto pair = std::minmax_element( c.cbegin( ), c.cend( ) );
  auto pair_min_max = std::make_pair( *pair.first, *pair.second );
  for ( auto &el : c ) el = ( el / pair_min_max.first ) + pair_min_max.second;
  return c;
}

reference_container modify17( reference_container c ) {
  auto max_num = *std::max_element( c.cbegin( ), c.cend( ) );
  for ( auto &el : c )
    if ( el > 0 ) el = max_num;
  return c;
}

reference_container modify18( reference_container c ) {
  auto pr = std::minmax_element( c.cbegin( ), c.cend( ) );
  auto min_max_pair = std::make_pair( *pr.first, *pr.second );
  for ( auto &el : c )
    if ( !( std::abs( el ) % 2 ) ) {
      el = min_max_pair.second - min_max_pair.first;
    }
  return c;
}

reference_container modify19( reference_container c ) {
  auto max = *std::max_element( c.begin( ), c.end( ) );
  int i = 1;
  for ( auto &el : c ) {
    if ( el < 0 ) {
      if ( !( i % 2 ) ) {
        el = max / 2;
      }
      ++i;
    }
  }
  return c;
}

reference_container modify20( reference_container c ) {
  auto summ = 0;
  for ( auto &el : c ) summ += el;
  int i = 1;
  for ( auto &el : c ) {
    if ( el > 0 ) {
      if ( !( i % 3 ) ) {
        el = summ / N;
      }
      ++i;
    }
  }
  return c;
}
