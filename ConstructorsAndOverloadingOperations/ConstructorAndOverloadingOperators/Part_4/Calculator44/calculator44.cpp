#include "calculator44.h"

#include <iostream>
#include <stack>

#include "fraction35.h"

// double Calculator44::operator( )( const std::string &expr ) {
//  // 1. Делаем постфиксную запись
//  std::stack< std::string > st_;
//  char cur_znak = ' ';
//  for ( auto it = expr.cbegin( ); it != expr.cend( ); ++it ) {
//    if ( *it == '(' ) continue;
//    if ( std::isdigit( *it ) ) {
//      std::string num;
//      while ( std::isdigit( *it ) ) {
//        num.push_back( *it++ );
//      }
//      st_.push( num );
//    }
//    if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
//      cur_znak = *it;
//    }
//    if ( *it == ')' ) {
//      std::string num = st_.top( );
//      st_.pop( );
//      std::string res = st_.top( );
//      st_.pop( );
//      res += " " + num + " " + cur_znak + " ";
//      st_.push( res );
//    }
//  }

//  std::string res = st_.top( );
//  st_.pop( );
//  std::cout << res << std::endl;

//  std::stack< Fraction35B > stack_;
//  return 0;
//}

double Calculator44::operator( )( const std::string &expr ) {
  return Raschet( Postfix( expr ) );
}
