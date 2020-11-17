#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

#include "DriverTemplate.h"
//#include "bankaccount.h"

// TODO DriverTemplate - общий шаблон решения семейства задач 21-40
// общий шаблон решения семейства задач 21-40,
// меняются сами классы агрегатов
// лямбды для сортировок и выборок
// заполнялку(generateAccount) нужно вытащить в классы

const std::string PATH_INPUT = "../../Serial21_40/Bank_Accounts_21/Files/input";
const std::string PATH_INPUT_RES = "../../Serial21_40/Bank_Accounts_21/Files/result";

using current_type = Account;

void generateAccount( DriverTemplate< current_type > &ba, int n );

void saveResult( std::queue< current_type > &que );

void printFile( );

int main( ) {
  try {
    DriverTemplate< current_type > ba;
    generateAccount( ba, 5 );
    std::cout << ba;
    std::cout << "*****************************************" << std::endl;
    // ba.sort( []( const Account &a, const Account &b ) { return a.code( ).id( ) < b.code( ).id( ); } );
    ba.sort( []( const current_type &a, const current_type &b ) { return a.num( ).number( ) < b.num( ).number( ); } );
    auto res = ba.searchLinear_if( []( const current_type &a ) { return a.code( ).id( ) < 10000; } );
    saveResult( res );
    printFile( );

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}

void generateAccount( DriverTemplate< current_type > &ba, int n ) {
  srand( std::time( nullptr ) );
  for ( int i = 0; i < n; ++i )
    ba.push_back( current_type( NumberAccount( std::to_string( std::rand( ) % 100000 ) ), CodeAccount( std::rand( ) % 100000 ),
                                Family( "famFive" ), SummAccount( std::rand( ) % 100000 ),
                                DateAccount( Day( std::rand( ) % 31 ), Month::Mar( ), Year( 2024 ) ), Procent( 6.7 ) ) );
}

void saveResult( std::queue< current_type > &que ) {
  if ( que.empty( ) ) return;
  std::stack< current_type > stack;
  while ( !que.empty( ) ) {
    stack.push( que.front( ) );
    que.pop( );
  }
  std::ofstream ofile( PATH_INPUT_RES, std::ios::binary );
  while ( !stack.empty( ) ) {
    ofile.write( reinterpret_cast< char * >( &stack.top( ) ), sizeof( current_type ) );
    stack.pop( );
  }
}

void printFile( ) {
  std::ifstream fin( PATH_INPUT_RES, std::ios::binary );
  current_type tmp;
  while ( fin ) {
    fin.read( reinterpret_cast< char * >( &tmp ), sizeof( current_type ) );
    if ( fin.good( ) ) std::cout << tmp << std::endl;
  }
}
