#include <fstream>
#include <iostream>

#include "bankaccount.h"

const std::string PATH_INPUT = "../../Serial21_40/Bank_Accounts_21/Files/input";

int main( ) {
  try {
    // std::ofstream ofile( PATH_INPUT, std::ios::binary );
    //    Account ac( NumberAccount( "12345" ), CodeAccount( 56789 ), Family( "Petrov" ), SummAccount( 569874.25 ),
    //                DateAccount( Day( 23 ), Month::Mar( ), Year( 2000 ) ), Procent( 7.95 ) );
    //    ac.save( ofile );
    //    ofile.close( );

    // std::ifstream ifile( PATH_INPUT, std::ios::binary );
    //    Account tt;
    //    if ( tt.read( ifile ) ) {
    //      std::cout << tt;
    //    } else {
    //      std::cout << "NO READ";
    //    }

    BankAccounts< Account > ba;
    ba.push_back( Account( NumberAccount( "00001" ), CodeAccount( 10000 ), Family( "famOne" ), SummAccount( 100000 ),
                           DateAccount( Day( 10 ), Month::Apr( ), Year( 2020 ) ), Procent( 5 ) ) );
    ba.push_back( Account( NumberAccount( "00002" ), CodeAccount( 10001 ), Family( "famTwo" ), SummAccount( 100001 ),
                           DateAccount( Day( 11 ), Month::Aug( ), Year( 2021 ) ), Procent( 5.5 ) ) );
    ba.push_back( Account( NumberAccount( "00003" ), CodeAccount( 10002 ), Family( "famTree" ), SummAccount( 100002 ),
                           DateAccount( Day( 12 ), Month::Dec( ), Year( 2022 ) ), Procent( 5.9 ) ) );
    ba.push_back( Account( NumberAccount( "00004" ), CodeAccount( 10003 ), Family( "famFor" ), SummAccount( 100003 ),
                           DateAccount( Day( 13 ), Month::Jan( ), Year( 2023 ) ), Procent( 6.3 ) ) );
    ba.push_back( Account( NumberAccount( "00005" ), CodeAccount( 10004 ), Family( "famFive" ), SummAccount( 100004 ),
                           DateAccount( Day( 14 ), Month::Mar( ), Year( 2024 ) ), Procent( 6.7 ) ) );

    // std::cout << ba;
    std::ofstream ofile( PATH_INPUT, std::ios::binary );
    if ( ba.save( ofile ) ) {
      std::cout << "OK" << std::endl;
    } else {
      std::cout << "NO OK" << std::endl;
    }
    ofile.close( );

    BankAccounts< Account > bb;
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );
    //    bb.addAccount( Account( ) );

    std::ifstream ifile( PATH_INPUT, std::ios::binary );
    bb.read( ifile );
    ifile.close( );
    std::cout << bb;

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}
