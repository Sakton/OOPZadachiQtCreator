#include "baseaccount.h"

#include <iomanip>
#include <iostream>
#include <sstream>

BaseAccount::BaseAccount( const std::string& name, const std::string& acc,
                          double proc, double summ )
    : name_ { }, accountNum_ { }, procent_ { 0 }, summa_ { 0 } {
  //проверки всех данных
  name_ = name;
  accountNum_ = acc;
  procent_ = proc;
  summa_ = summ;
}

std::string BaseAccount::getName( ) const { return name_; }

void BaseAccount::setName( const std::string& name ) { name_ = name; }

std::string BaseAccount::getAccountNum( ) const { return accountNum_; }

void BaseAccount::setAccountNum( const std::string& accountNum ) {
  accountNum_ = accountNum;
}

double BaseAccount::getProcent( ) const { return procent_; }

void BaseAccount::setProcent( double procent ) { procent_ = procent; }

double BaseAccount::getSumma( ) const { return summa_; }

void BaseAccount::setSumma( double summa ) { summa_ = summa; }

void Display( const BaseAccount& ac ) {
  std::cout << ToString( ac ) << std::endl;
}
std::string ToString( const BaseAccount& ac ) {
  std::stringstream ss;
  ss << "   Name: " << ac.name_ << std::endl
     << "Account: " << ac.accountNum_ << std::endl
     << "Procent: " << ac.procent_ << std::endl
     << std::fixed << std::setprecision( 2 ) << "  Summa: " << ac.summa_
     << std::endl;
  return ss.str( );
}
