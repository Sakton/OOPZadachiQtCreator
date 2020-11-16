#include <fstream>
#include <iostream>

#include "bankaccount.h"

const std::string PATH_INPUT = "../../Serial21_40/Bank_Accounts_21/Files/input";

int main( ) {
  try {
    //    std::ofstream ofile( PATH_INPUT, std::ios::binary );

    //    std::ifstream ifile( PATH_INPUT, std::ios::binary );

    Account ac( NumberAccount( "12345" ), CodeAccount( 56789 ) );
    std::cout << ac;

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}
