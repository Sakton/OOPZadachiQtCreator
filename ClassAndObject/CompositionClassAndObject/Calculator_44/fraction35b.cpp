#include "fraction35b.h"
#include <iostream>
#include <sstream>

void Fraction35B::Init( int64_t w, int16_t f )
{
    if ( f < 0 || f >= 10000 ) {
	std::cout << "ERROR ARG FRACTIONAL < 0 || >= 10000";
	exit( 1 );
    }
    whole_ = std::abs( w );
    negative = ( w < 0 ) ? true : false;
    fractional_ = std::abs( f );
}

void Fraction35B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Fraction35B::ToString( ) const
{
    std::stringstream ss;
    if ( negative )
	ss << '-';
    ss << whole_ << ",";
    if ( 0 <= fractional_ && fractional_ < 10 ) {
	ss << "000";
    }
    else if ( 10 <= fractional_ && fractional_ < 100 ) {
	ss << "00";
    }
    else if ( 100 <= fractional_ && fractional_ < 1000 ) {
	ss << "0";
    }
    ss << fractional_;
    return ss.str( );
}

Fraction35B Fraction35B::Add( const Fraction35B & b ) const
{
    Fraction35B loc;
    loc.Init( );

    if ( negative && !b.negative ) {
	if ( Modul( *this ).Less( Modul( b ) ) ) {
	    loc = SubModul( Modul( b ), Modul( *this ) );
	}
	else if ( !Modul( *this ).Less( Modul( b ) ) ) {
	    loc = SubModul( Modul( *this ), Modul( b ) );
	    loc.negative = true;
	}
	else {
	    loc.whole_ = 0;
	    loc.fractional_ = 0;
	}
    } else if ( !negative && b.negative ) {
	if ( Modul( *this ).Less( Modul( b ) ) ) {
	    loc = SubModul( Modul( *this ), Modul( b ) );
	}
	else if ( !Modul( *this ).Less( Modul( b ) ) ) {
	    loc = SubModul( Modul( b ), Modul( *this ) );
	    loc.negative = true;
	}
	else {
	    loc.whole_ = 0;
	    loc.fractional_ = 0;
	}
    } else {
	loc = AddModul( Modul( *this ), Modul( b ) );
	loc.negative = negative;
    }

    return loc;
}

Fraction35B Fraction35B::Sub( const Fraction35B & b ) const
{
    Fraction35B loc;
    loc.Init( );
    if ( !negative && !b.negative ) {	     //оба положительные
	if ( Less( b ) ) {
	    loc = SubModul( b, *this );
	    loc.negative = true;
	} else if ( !Less( b ) ) {
	    loc = SubModul( *this, b );
	}
    } else if ( negative && b.negative ) {	  //оба отрицательные
	if ( LessMod( Modul( b ) ) ) {
	    loc = SubModul( Modul( b ), Modul( *this ) );
	} else if ( !LessMod( Modul( b ) ) ) {
	    loc = SubModul( Modul( *this ), Modul( b ) );
	    loc.negative = true;
	}
    } else {	    //знаки разные
	if ( negative && !b.negative ) {
	    loc = AddModul( Modul( *this ), Modul( b ) );
	    loc.negative = true;
	} else if ( !negative && b.negative ) {
	    loc = AddModul( Modul( *this ), Modul( b ) );
	}
    }
    return loc;
}

Fraction35B Fraction35B::Mul( const Fraction35B & b ) const
{
    Fraction35B loc;
    loc = MulModul( *this, b );

    if ( negative != b.negative ) {
	loc.negative = true;
    } else {
	loc.negative = false;
    }

    return loc;
}

Fraction35B Fraction35B::Div( const Fraction35B & b ) const
{
    //деление выдает большую погрешность на больших числах
    //неодходимо увеличивать точность самого класса
    //5555.5555 / 2222.2222 = 2,5
    //при этой точности 1/10000
    //5555.5555 / 2222.2222 = 2.2222 ( 1/2222,2222 = 0,0004 в этом случае (0,00045) )
    //но даже если округлить до 1/2222,2222 = 0,0005, то 5555.5555 / 2222.2222 = 2.7777
    //поэтому на эту операцию при данной точности надеятся нельзя
    //и в учебнике не просят ее делатть
    //  **
    //    Fraction35B loc = *this;
    //    return loc.Mul( OneDivFrac( b ) );
    //  **

    //или тупо через дабл
    double x = whole_ + ( double( fractional_ ) / 1000 );
    double y = b.whole_ + ( double( b.fractional_ ) / 1000 );
    double res = x / y;
    Fraction35B loc;
    loc.Init( res, ( res - static_cast< int64_t >( res ) ) * 10000 );
    return loc;
}

bool Fraction35B::Less( const Fraction35B & b ) const
{
    if ( negative && !b.negative ) {
	return !LessMod( b );
    } else if ( !negative && !b.negative ) {
	return LessMod( b );
    } else {
	return ( whole_ < b.whole_ );
    }
}

Fraction35B Fraction35B::AddModul( const Fraction35B & a, const Fraction35B & b ) const
{
    Fraction35B loc;
    loc.whole_ = a.whole_ + b.whole_;
    loc.fractional_ = a.fractional_ + b.fractional_;
    if ( loc.fractional_ > 10000 ) {
	loc.fractional_ -= 10000;
	++loc.whole_;
    }
    return loc;
}

Fraction35B Fraction35B::SubModul( const Fraction35B & a, const Fraction35B & b ) const
{
    Fraction35B loc;
    loc.whole_ = a.whole_ - b.whole_;
    if ( a.fractional_ < b.fractional_ ) {
	--loc.whole_;
	loc.fractional_ = a.fractional_ + 10000 - b.fractional_;
    } else {
	loc.fractional_ = a.fractional_ - b.fractional_;
    }
    return loc;
}

Fraction35B Fraction35B::MulModul( const Fraction35B & a, const Fraction35B & b ) const
{
    //(a + b)*(c + d)

    int64_t ac_t = a.whole_ * b.whole_;
    double ad_t = a.whole_ * ( double( b.fractional_ ) / 10000 );
    double bc_t = ( double( a.fractional_ ) / 10000 ) * b.whole_;
    int64_t bd_t = a.fractional_ * b.fractional_;

    Fraction35B ac;
    ac.Init( ac_t, 0 );
    Fraction35B ad;
    ad.Init( ad_t, ( ad_t - static_cast< int64_t >( ad_t ) ) * 10000 );
    Fraction35B bc;
    bc.Init( bc_t, ( bc_t - static_cast< int64_t >( bc_t ) ) * 10000 );
    Fraction35B bd;
    bd.Init( bd_t / 100000000, ( bd_t % 100000000 ) / 10000 );

    Fraction35B res = ac.Add( ad ).Add( bc ).Add( bd );
    return res;
}

Fraction35B Fraction35B::MulDesyatki( int mul ) const
{
    Fraction35B loc;
    loc.Init( );
    int doo = std::min( mul, 10000 );
    loc.whole_ = whole_ * doo + fractional_ / ( 10000 / doo );
    loc.fractional_ = ( fractional_ * doo ) % 10000;
    mul /= doo;
    loc.whole_ *= mul;
    return loc;
}

Fraction35B Fraction35B::MulOneNumber( int num ) const	      //num [0 - 9]
{
    Fraction35B loc = *this;
    loc.whole_ *= num;

    int doo = 0;
    int doo1 = 0;

    //при 6 * 9999 = 59994, максимум у short = 65536
    //поэтому приходим к такой формуле y * ( a + num - a );
    //число на сумму 2 чисел, и сразу приведением его к нормальному состоянию < 10000
    //с выделением целой части
    if ( num > 6 ) {
	doo = 6;
	doo1 = num - doo;
    } else {
	doo = num;
    }
    int t1 = loc.fractional_;
    int t2 = loc.fractional_;
    t1 *= doo;
    t2 *= doo1;
    loc.whole_ += ( t1 / 10000 );
    t1 %= 10000;
    loc.whole_ += ( t2 / 10000 );
    t2 %= 10000;
    loc.fractional_ = ( t1 + t2 );
    loc.whole_ += loc.fractional_ / 10000;
    loc.fractional_ %= 10000;

    return loc;
}

Fraction35B Fraction35B::Modul( const Fraction35B & a ) const
{
    Fraction35B loc;
    loc.Init( std::abs( a.whole_ ), a.fractional_ );
    return loc;
}

Fraction35B Fraction35B::OneDivFrac( const Fraction35B & a ) const
{
    //Вводим ограничения, если число fraction >= 10000, то при делении мы выйдем за
    //погрешность в 1/10000, и результатом будет 0
    //а при числах < 10000
    Fraction35B loc;
    loc.Init( );
    if ( a.whole_ <= 10000 ) {
	double x = a.whole_ + ( static_cast< double >( a.fractional_ ) / 10000 );
	double y = 1 / x;
	std::cout << y << std::endl;
	loc.Init( y, ( y - static_cast< int64_t >( y ) ) * 10000 );
	loc.Display( );
	loc.negative = a.negative;
    }
    return loc;
}

bool Fraction35B::LessMod( const Fraction35B & b ) const
{
    return ( std::abs( whole_ ) < std::abs( b.whole_ ) )
	|| ( ( std::abs( whole_ ) == std::abs( b.whole_ ) ) && ( fractional_ < b.fractional_ ) );
}

bool Fraction35B::EqModul( const Fraction35B & b ) const
{
    return ( std::abs( whole_ ) == std::abs( b.whole_ ) && fractional_ == b.fractional_ );
}

bool Fraction35B::GetNegative( ) const
{
    return negative;
}

int16_t Fraction35B::Fractional( ) const
{
    return fractional_;
}

int64_t Fraction35B::Whole( ) const
{
    return whole_;
}
