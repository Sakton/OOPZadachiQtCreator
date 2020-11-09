#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

static const std::string PATH = "../../stl_part3/Files/";
static constexpr int N = 6;

using type = int32_t;
using type_container = std::vector< type >;
using reference_container = type_container &;
using const_reference_container = const type_container &;

using container_iterator = typename type_container::iterator;
using const_container_iterator = typename type_container::const_iterator;
using reverse_container_iterator = typename type_container::reverse_iterator;
using const_reverse_container_iterator =
    typename type_container::const_reverse_iterator;

const std::string createFile( const std::string &name_file );
type_container inputFile( const std::string &name_file );
// void tasks( const_container_iterator ( *modificator )(
//    container_iterator beg_it, container_iterator end_it ) );
void tasks( void ( *modificator )( container_iterator beg_it,
                                   container_iterator end_it ) );
void outFile( const std::string &name_file, const_container_iterator begIt,
              const_container_iterator endIt );

// modificators
void modify1( container_iterator beg_it, container_iterator end_it );
void modify2( container_iterator beg_it, container_iterator end_it );
void modify3( container_iterator beg_it, container_iterator end_it );
void modify4( container_iterator beg_it, container_iterator end_it );
void modify5( container_iterator beg_it, container_iterator end_it );
void modify6( container_iterator beg_it, container_iterator end_it );
void modify7( container_iterator beg_it, container_iterator end_it );
void modify8( container_iterator beg_it, container_iterator end_it );
void modify9( container_iterator beg_it, container_iterator end_it );
void modify10( container_iterator beg_it, container_iterator end_it );
void modify11( container_iterator beg_it, container_iterator end_it );
void modify12( container_iterator beg_it, container_iterator end_it );
void modify13( container_iterator beg_it, container_iterator end_it );
void modify14( container_iterator beg_it, container_iterator end_it );
void modify15( container_iterator beg_it, container_iterator end_it );
void modify16( container_iterator beg_it, container_iterator end_it );
void modify17( container_iterator beg_it, container_iterator end_it );
void modify18( container_iterator beg_it, container_iterator end_it );
void modify19( container_iterator beg_it, container_iterator end_it );
void modify20( container_iterator beg_it, container_iterator end_it );

int main( ) {
  using modify =
      void ( * )( container_iterator beg_it, container_iterator end_it );
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

void outFile( const std::string &name_file, const_container_iterator begIt,
              const_container_iterator endIt ) {
  std::ofstream ofile( name_file );
  std::ostream_iterator< type > outIterator( ofile, "\n" );
  auto it = begIt;
  while ( it != endIt ) {
    *outIterator++ = *it;
    ++it;
  }
}

const std::string createFile( const std::string &name_file ) {
  std::ofstream ofile( PATH + name_file );
  if ( !ofile.is_open( ) ) throw std::runtime_error( "NO OPEN FILE" );
  std::srand( std::time( nullptr ) );
  std::ostream_iterator< type > out_stream( ofile, "\n" );
  for ( int i = 0; i < N; ++i ) {
    int rand = std::rand( ) % 50;
    if ( !( rand % 3 ) ) rand *= -1;
    *out_stream++ = rand;
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
void tasks( void ( *modificator )( container_iterator beg_it,
                                   container_iterator end_it ) ) {
  type_container v = inputFile( createFile( "input.txt" ) );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
  std::cout << '\n'
            << "***************************************************************"
               "************"
            << std::endl;
  modificator( v.begin( ), v.end( ) );
  outFile( PATH + "output.txt", v.begin( ), v.end( ) );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
}

void modify1( container_iterator beg_it, container_iterator end_it ) {
  auto max = *std::max_element( beg_it, end_it );

  auto factor = std::sqrt( std::abs( max * ( *( --end_it ) ) ) );
  auto it = beg_it;
  while ( it != end_it ) {
    ( *it++ ) *= factor;
  }
}

struct Pred2 {
  bool operator( )( int a ) { return a < 0; }
};

void modify2( container_iterator beg_it, container_iterator end_it ) {
  auto el = std::find_if( beg_it, end_it, Pred2( ) );
  if ( el == end_it ) throw std::runtime_error( "NO NEGATIVE ELEMENT" );
  //  std::cout << "elem < 0 => " << *el << std::endl;
  container_iterator it = beg_it;
  for ( int i = 0; i < N / 2; ++i )
    ++it;  //??? улучшить (это решение подойдет и для списка)
  auto polusumma = ( *el + *it ) / 2;
  std::cout << "polusumma = " << polusumma << std::endl;
  if ( polusumma == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  it = beg_it;
  for ( ; it != end_it; ++it ) ( *it ) /= polusumma;
}

void modify3( container_iterator beg_it, container_iterator end_it ) {
  auto max_elem = *std::max_element( beg_it, end_it );
  auto it = beg_it;
  for ( ; it != end_it; ++it ) ( *it ) -= max_elem;
}

void modify4( container_iterator beg_it, container_iterator end_it ) {
  auto min_elem = *std::min_element( beg_it, end_it );
  auto it = beg_it;
  for ( ; it != end_it; ++it ) ( *it ) *= min_elem;
}

void modify5( container_iterator beg_it, container_iterator end_it ) {
  auto sum = 0;
  auto it = beg_it;
  for ( ; it != end_it; ++it ) sum += ( *it );
  sum /= N;
  if ( sum == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  it = beg_it;
  for ( ; it != end_it; ++it ) {
    if ( ( std::abs( ( *it ) ) % 2 ) ) {
      ( *it ) /= sum;
    }
  }
}

void modify6( container_iterator beg_it, container_iterator end_it ) {
  auto summ = 0;
  auto it = beg_it;
  for ( ; it != end_it; ++it ) summ += ( *it );
  it = beg_it;
  for ( ; it != end_it; ++it ) ( *it ) -= summ;
}

void modify7( container_iterator beg_it, container_iterator end_it ) {
  auto dvoin_summa = 0;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( *it < 0 ) {
      dvoin_summa += *it;
      break;
    }
  }

  //реверс итераторы из обычных.
  //создаются из обычных через класс контейнера
  // rev_beg - начальный из конечного итератора
  // rev_end - конечный из начального
  type_container::reverse_iterator rev_beg( end_it );
  type_container::reverse_iterator rev_end( beg_it );

  for ( auto it = rev_beg; it != rev_end; ++it ) {
    if ( *it < 0 ) {
      dvoin_summa += *it;
      break;
    }
  }

  dvoin_summa *= 2;
  std::cout << "dvoin_summa = " << dvoin_summa << std::endl;
  int idx = 1;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( !( idx % 3 ) ) ( *it ) *= dvoin_summa;
    ++idx;
  }
}

void modify8( container_iterator beg_it, container_iterator end_it ) {
  auto first_nechet = 0;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( std::abs( ( *it ) ) % 2 ) {
      first_nechet = ( *it );
      break;
    }
  }
  for ( auto it = beg_it; it != end_it; ++it ) ( *it ) += first_nechet;
}

void modify9( container_iterator beg_it, container_iterator end_it ) {
  auto first_nagative = 0;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( ( *it ) < 0 ) {
      first_nagative = ( *it );
      break;
    }
  }

  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( !( std::abs( ( *it ) ) % 2 ) ) {
      ( *it ) *= first_nagative;
    }
  }
}

void modify10( container_iterator beg_it, container_iterator end_it ) {
  auto mnog = 0;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( *it < 0 ) {
      mnog = *it / 2;
      break;
    };
  }
  for ( auto it = beg_it; it != end_it; ++it ) {
    *it += mnog;
  }
}

void modify11( container_iterator beg_it, container_iterator end_it ) {
  auto half_max = *std::max_element( beg_it, end_it ) / 2;
  if ( half_max == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  for ( auto it = beg_it; it != end_it; ++it ) {
    *it /= half_max;
  }
}

void modify12( container_iterator beg_it, container_iterator end_it ) {
  auto middle_arifmetic = 0;
  for ( auto it = beg_it; it != end_it; ++it ) middle_arifmetic += *it;
  middle_arifmetic /= N;
  std::cout << "middle_arifmetic = " << middle_arifmetic << std::endl;
  for ( auto it = beg_it; it != end_it; ++it )
    *it = ( *it != 0 ) ? *it : middle_arifmetic;
}

void modify13( container_iterator beg_it, container_iterator end_it ) {
  auto sqr_min_elem = std::pow( *std::min_element( beg_it, end_it ), 2 );
  for ( auto it = beg_it; it != end_it; ++it )
    *it = ( *it > 0 ) ? sqr_min_elem : *it;
}

void modify14( container_iterator beg_it, container_iterator end_it ) {
  auto half_nagative = 0;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( *it < 0 ) half_nagative += *it;
  };
  half_nagative >>= 1;
  std::cout << "half_nagative = " << half_nagative << std::endl;
  for ( auto it = beg_it; it != end_it; ++it ) *it += half_nagative;
}

void modify15( container_iterator beg_it, container_iterator end_it ) {
  std::pair< type, type > para_min_max { 0, 0 };
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( para_min_max.first < std::abs( *it ) )
      para_min_max.first = std::abs( *it );
    if ( para_min_max.second > std::abs( *it ) )
      para_min_max.second = std::abs( *it );
  }
  auto middle_min_max = ( para_min_max.first + para_min_max.second ) / 2;
  std::cout << "middle_min_max = " << middle_min_max << std::endl;
  for ( auto it = beg_it; it != end_it; ++it ) *it += middle_min_max;
}

void modify16( container_iterator beg_it, container_iterator end_it ) {
  auto pair = std::minmax_element( beg_it, end_it );
  auto pair_min_max = std::make_pair( *pair.first, *pair.second );
  for ( auto it = beg_it; it != end_it; ++it )
    *it = ( *it / pair_min_max.first ) + pair_min_max.second;
}

void modify17( container_iterator beg_it, container_iterator end_it ) {
  auto max_num = *std::max_element( beg_it, end_it );
  for ( auto it = beg_it; it != end_it; ++it )
    if ( *it > 0 ) *it = max_num;
}

void modify18( container_iterator beg_it, container_iterator end_it ) {
  auto pr = std::minmax_element( beg_it, end_it );
  auto min_max_pair = std::make_pair( *pr.first, *pr.second );
  for ( auto it = beg_it; it != end_it; ++it )
    if ( !( std::abs( *it ) % 2 ) ) {
      *it = min_max_pair.second - min_max_pair.first;
    }
}

void modify19( container_iterator beg_it, container_iterator end_it ) {
  auto max = *std::max_element( beg_it, end_it );
  int i = 1;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( *it < 0 ) {
      if ( !( i % 2 ) ) {
        *it = max / 2;
      }
      ++i;
    }
  }
}

void modify20( container_iterator beg_it, container_iterator end_it ) {
  auto summ = 0;
  for ( auto it = beg_it; it != end_it; ++it ) summ += *it;
  int i = 1;
  for ( auto it = beg_it; it != end_it; ++it ) {
    if ( *it > 0 ) {
      if ( !( i % 3 ) ) {
        *it = summ / N;
      }
      ++i;
    }
  }
}
