#include "fazzynumber31b.h"
#include <iostream>
#include <sstream>

void FazzyNumber31B::Init( double e1, double x, double e2 )
{
    e1_ = e1;
    x_ = x;
    e2_ = e2;
}

void FazzyNumber31B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string FazzyNumber31B::ToString( ) const
{
    std::stringstream ss;
    ss << "( " << x_ << "-" << std::abs( e1_ ) << ", "
       << x_ << ", "
       << x_ << "+" << std::abs( e1_ ) << " )";
    return ss.str( );
}

//FazzyNumber31B FazzyNumber31B::Add( const FazzyNumber31B & oth ) const
//{
//}
