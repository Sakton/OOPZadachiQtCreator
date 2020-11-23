#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Account_Bank {
  std::string name;
  std::string acc;
  int id;
};

std::ostream &operator<<( std::ostream &ou, const Account_Bank &ab );

class Pred {
 public:
  // enum Ts { TsName, TsAcc, TsId };
  // Pred( Ts ts = TsId ) : ts_ { ts } {}
  Pred( int data = 0 ) : data_ { data } { };

  //  bool operator( )( const Account_Bank &a, const Account_Bank &b ) {
  //    switch ( ts_ ) {
  //      case TsName:
  //        return a.name < b.name;
  //      case TsAcc:
  //        return a.acc < b.acc;
  //      case TsId:
  //        return a.id < b.id;
  //    }
  //  }

  //  bool operator( )( const std::string &param, const Account_Bank &b ) {
  //    switch ( ts_ ) {
  //      case TsName:
  //        return param < b.name;
  //      case TsAcc:
  //        return param < b.acc;
  //      case TsId:
  //        return false;
  //    }
  //    return false;
  //  }

  bool operator( )( const std::string &a, const std::string &b ) const { return a > b; }

  bool operator( )( int ident, int x ) const { return ident < x; }

  // private:
  //  Ts ts_;
  int data_;
};

std::vector< Account_Bank > generate( );

int main( ) {
  std::srand( std::time( nullptr ) );
  std::vector< Account_Bank > va = generate( );
  std::map< std::string, Account_Bank, Pred > map_name;

  auto it = std::find_if( va.cbegin( ), va.cend( ), []( const Account_Bank &a ) { return a.name < "30"; } );
  // поиск по имени и запись в мап
  // все остальные аналогичные
  while ( it != va.cend( ) ) {
    map_name.insert( std::make_pair( it->name, *it ) );
    ++it;
  }

  for ( const auto &el : map_name ) {
    std::cout << el.second;
  }
}

std::vector< Account_Bank > generate( ) {
  std::vector< Account_Bank > res;
  for ( int i = 0; i < 10; ++i ) {
    res.push_back( { std::to_string( std::rand( ) % 100 ), std::to_string( std::rand( ) % 10000 ), std::rand( ) % 10000 } );
  }
  return res;
}

std::ostream &operator<<( std::ostream &ou, const Account_Bank &ab ) {
  ou << "name = " << ab.name << std::endl;
  ou << "acc  = " << ab.acc << std::endl;
  ou << "id   = " << ab.id << std::endl;
  ou << std::endl;
  return ou;
}
