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
  Pred( int data = 0 ) : data_ { data } { };
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
  for ( const auto &el : va ) {
    std::cout << el;
  }

  std::cout << "/******************************************" << std::endl;
  std::cout << "/******************************************" << std::endl;

  std::map< std::string, Account_Bank, Pred > map_name;
  auto fun = []( const Account_Bank &a ) { return a.name < "30"; };
  auto it = std::find_if( va.cbegin( ), va.cend( ), fun );
  // поиск по имени и запись в мап
  // все остальные аналогичные
  while ( it != va.cend( ) ) {
    map_name.insert( std::make_pair( it->name, *it ) );
    ++it;
    it = std::find_if( it, va.cend( ), fun );
  }

  for ( const auto &el : map_name ) {
    std::cout << el.second;
  }
  //****************************
  std::cout << "/******************************************" << std::endl;
  std::map< std::string, Account_Bank, Pred > map_acc;
  auto fun1 = []( const Account_Bank &a ) { return a.acc < "5000"; };

  it = std::find_if( va.cbegin( ), va.cend( ), fun1 );
  while ( it != va.cend( ) ) {
    map_acc.insert( std::make_pair( it->name, *it ) );
    ++it;
    it = std::find_if( it, va.cend( ), fun1 );
  }

  for ( const auto &el : map_acc ) {
    std::cout << el.second;
  }

  std::cout << "/**************** ID **********************" << std::endl;

  auto fun2 = []( const Account_Bank &a ) { return a.id < 5000; };
  std::map< int, Account_Bank, Pred > map_id;
  it = std::find_if( va.cbegin( ), va.cend( ), fun2 );
  while ( it != va.cend( ) ) {
    map_id.insert( std::make_pair( it->id, *it ) );
    ++it;
    it = std::find_if( it, va.cend( ), fun2 );
  }

  for ( const auto &el : map_id ) {
    std::cout << el.second;
  }

  std::cout << "/**************************************************************" << std::endl;
  std::cout << "/**************************************************************" << std::endl;

  // std::map< std::string, Account_Bank > mp1( va.begin( ), va.end( ) );  //без цикла не выйдет!!!!!!
  //  for ( auto &el : mp1 ) {
  //    std::cout << el.second << std::endl;
  //  }
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
