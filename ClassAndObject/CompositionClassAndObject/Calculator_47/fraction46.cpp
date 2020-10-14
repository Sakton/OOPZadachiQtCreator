#include "fraction46.h"

#include <iomanip>
#include <iostream>
#include <sstream>

void Fraction46::Init( int64_t w, double f )
{
    if ( f < 0 || f > 1.0 ) {
	std::cout << "ERROR ARG FRACTIONAL < 0 || >= 10000";
	exit( 1 );
    }
    whole_.Init( std::abs( w ) );
    fractional_ = std::fabs( f );
    negative_ = ( w < 0 ) ? true : false;
}

void Fraction46::Init( const Fraction46 & fr )
{
    whole_.Init( fr.whole_ );
    fractional_ = fr.fractional_;
    negative_ = fr.negative_;
}

void Fraction46::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Fraction46::ToString( ) const
{
    //TODO подправить вывод нулей в дробной части
    std::stringstream ss;
    if ( negative_ )
	ss << '-';
    ss << whole_.ToString( ) << ",";
    ss << static_cast< int16_t >( fractional_ * ACCURACY );
    return ss.str( );
}

Fraction46 Fraction46::Add( const Fraction46 & b ) const
{
    Fraction46 loc;
    if ( negative_ == b.negative_ ) {
	loc.Init( AddModul( *this, b ) );
	loc.negative_ = negative_;
    } else {
	loc.Init( SubModul( *this, b ) );
	if ( ( LessMod( b ) && b.negative_ ) || ( b.LessMod( *this ) && negative_ ) ) {
	    loc.negative_ = true;
	}
    }
    return loc;
}

Fraction46 Fraction46::Sub( const Fraction46 & b ) const
{
    return Add( b.Revert( ) );
}

Fraction46 Fraction46::Mul( const Fraction46 & b ) const
{
    //(a + b)*(c + d)
    Fraction46 loc;

    long double res = whole_.Mid( b.whole_ ).ToInt64( );
    long double acD = whole_.ToInt64( ) * b.fractional_;
    long double bcD = b.whole_.ToInt64( ) * fractional_;
    double bdD = fractional_ * b.fractional_;
    res += ( acD + bcD + bdD );
    loc.Init( res, res - static_cast< int64_t >( res ) );
    if ( negative_ != b.negative_ )
	loc.negative_ = true;
    return loc;
}

Fraction46 Fraction46::Div( const Fraction46 & b ) const
{
    if ( b.IsZero( ) ) {
	std::cout << "ERROR DIV ZERO";
	exit( 1 );
    }
    Fraction46 loc;
    loc.Init( *this );
    return loc.Mul( b.OneDivFrac( ) );
}

Fraction46 Fraction46::AddModul( const Fraction46 & a, const Fraction46 & b ) const
{
    Fraction46 loc;
    loc.Init( a );
    loc.whole_.AddSelf( b.whole_ );
    loc.fractional_ += b.fractional_;
    if ( loc.fractional_ > 1 ) {
	loc.fractional_ -= 1;
	loc.whole_.AddSelf( 1 );
    }
    return loc;
}

Fraction46 Fraction46::SubModul( const Fraction46 & a, const Fraction46 & b ) const	   //|a| >= |b|
{
    Fraction46 first, second;
    first.Init( );
    second.Init( );
    if ( a.LessEqModul( b ) ) {
	first.Init( b );
	second.Init( a );
    } else {
	first.Init( a );
	second.Init( b );
    }
    Fraction46 loc;
    loc.Init( );
    loc.whole_.Init( first.whole_.Sub( second.whole_ ) );
    loc.fractional_ = first.fractional_ - second.fractional_;
    if ( loc.fractional_ < 0 ) {
	loc.fractional_ += 1;
	loc.whole_.SubSelf( 1 );
    }
    return loc;
}

bool Fraction46::LessMod( const Fraction46 & b ) const
{
    return whole_.Less( b.whole_ ) || ( ( whole_.Eq( b.whole_ ) ) && ( fractional_ < b.fractional_ ) );
}

bool Fraction46::EqModul( const Fraction46 & b ) const
{
    return whole_.Eq( b.whole_ ) && ( fractional_ - b.fractional_ ) < 1e-5;
}

bool Fraction46::LessEqModul( const Fraction46 & b ) const
{
    return LessMod( b ) || EqModul( b );
}

Fraction46 Fraction46::Revert( ) const
{
    Fraction46 loc;
    loc.Init( *this );
    loc.negative_ = !loc.negative_;
    return loc;
}

Fraction46 Fraction46::OneDivFrac( ) const
{
    Fraction46 loc;
    if ( whole_.ToInt64( ) > ACCURACY ) {
	loc.whole_.Init( 0 );
	loc.fractional_ = 0;
    }
    else {
	double x = whole_.ToInt64( ) + fractional_;
	x = 1 / x;
	loc.Init( x, ( x - static_cast< int64_t >( x ) ) );
    }
    loc.negative_ = negative_;
    return loc;
}

bool Fraction46::IsZero( ) const
{
    return ( whole_.ToInt64( ) ) == 0 && ( fractional_ < 1e-6 );
}

int16_t Fraction46::Fractional( ) const
{
    return static_cast< int16_t >( fractional_ * ACCURACY );
}

int64_t Fraction46::Whole( ) const
{
    return whole_.ToInt64( );
}
