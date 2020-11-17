#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "bankaccount.h"

const std::string PATH_INPUT = "../../Serial21_40/Bank_Accounts_21/Files/input";

void generateAccount( BankAccounts< Account > &ba, int n );

int main( ) {
  try {

    BankAccounts< Account > ba;
    generateAccount( ba, 5 );
    std::cout << ba;
    std::cout << "*****************************************" << std::endl;
    // ba.sort( []( const Account &a, const Account &b ) { return a.code( ).id( ) < b.code( ).id( ); } );
    ba.sort( []( const Account &a, const Account &b ) { return a.num( ).number( ) < b.num( ).number( ); } );
    // std::cout << ba;
    auto res = ba.searchLinear_if( []( const Account &a ) { return a.code( ).id( ) < 10000; } );
    while ( !res.empty( ) ) {
      std::cout << "****\n" << res.front( );
      std::cout << std::endl;
      res.pop( );
    }

    //    std::ofstream ofile( PATH_INPUT, std::ios::binary );
    //    if ( ba.save( ofile ) ) {
    //      std::cout << "OK" << std::endl;
    //    } else {
    //      std::cout << "NO OK" << std::endl;
    //    }
    //    ofile.close( );

    //    BankAccounts< Account > bb;

    //    std::ifstream ifile( PATH_INPUT, std::ios::binary );
    //    bb.read( ifile );
    //    ifile.close( );
    //    std::cout << bb;

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}

void generateAccount( BankAccounts< Account > &ba, int n ) {
  srand( std::time( nullptr ) );
  for ( int i = 0; i < n; ++i )
    ba.push_back( Account( NumberAccount( std::to_string( std::rand( ) % 100000 ) ), CodeAccount( std::rand( ) % 100000 ),
                           Family( "famFive" ), SummAccount( std::rand( ) % 100000 ),
                           DateAccount( Day( std::rand( ) % 31 ), Month::Mar( ), Year( 2024 ) ), Procent( 6.7 ) ) );
}
