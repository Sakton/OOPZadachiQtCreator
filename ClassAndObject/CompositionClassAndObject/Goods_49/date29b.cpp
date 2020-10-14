#include "date29b.h"
#include <iostream>
#include <regex>
#include <sstream>

void Date29B::Init( int16_t y, int16_t m, int16_t d )
{
    if ( y < 0 || m < 0 || d < 0 ) {
	std::cout << "ERROR ARG";
	exit( 1 );
    }
    y_ = y;
    m_ = m;
    d_ = d;
}

void Date29B::Init( const std::string & dt )
{
    std::regex t( R"((\d{2})\.(\d{2})\.(\d{4}))" );
    std::smatch res;
    if ( !std::regex_match( dt, res, t ) ) {
	std::cout << "ERROR ARG STR";
	exit( 1 );
    }

    int y = std::stoi( res[ 3 ] );
    int m = std::stoi( res[ 2 ] );
    int d = std::stoi( res[ 1 ] );

    Init( y, m, d );
}

void Date29B::Init( const Date29B & dt )
{
    Init( dt.y_, dt.m_, dt.d_ );
}

void Date29B::Read( )
{
    //***
}

void Date29B::Display( ) const
{
    std::cout << ToString( );
}

std::string Date29B::ToString( ) const
{
    std::stringstream ss;
    ss << "\"";
    if ( d_ < 10 )
	ss << '0';
    ss << d_ << ".";
    if ( m_ < 10 )
	ss << '0';
    ss << m_ << "." << y_ << "\"";
    return ss.str( );
}

Date29B Date29B::AddDay( int days ) const
{
    Date29B t = *this;
    //Переменная отвечает за проверку високосности в году прибытия
    //если будут переходы через года то високосность учтется в годовой корректировке
    //поэтому ее считать в корректировке по месяцам не надо
    bool yearChanged = ( days > 365 );
    days += t.d_;

    while ( days >= 365 ) {
	//WARNING тут была ошибка в порядке следования проверки на високосность!!!
	if ( t.IsVisokosny( ) )
	    --days;
	++t.y_;
	//Год меняется и текущий уже не високосный!!! копится ошибка дней по високосным годам!!!
	//	if ( t.IsVisokosny( ) )
	//	    --days;
	days -= 365;
    }

    int countDayInMonth = monats[ t.m_ - 1 ];
    if ( ( t.m_ - 1 ) == 1 && t.IsVisokosny( ) && !yearChanged )
	++countDayInMonth;

    while ( days > countDayInMonth ) {
	days -= countDayInMonth;
	if ( ++t.m_ == 13 ) {
	    t.m_ = 1;
	    ++t.y_;
	}
	countDayInMonth = monats[ t.m_ - 1 ];
    }
    t.d_ = days;

    return t;
}

Date29B Date29B::SubDay( int days ) const
{
    Date29B t = *this;

    int index = t.m_ - 1;
    if ( index < 0 )
	index = 11;

    days += ( monats[ index ] - t.d_ ); //загвоздка тут
    bool yearChanged = ( days > 365 );

    if ( days >= 365 ) {
	if ( t.IsVisokosny( ) && t.m_ >= 3 ) {
	    --days;
	}
	--t.y_;
	days -= 365;
    }

    while ( days >= monats[ index ] ) {
	days -= monats[ index ];
	if ( index == 1 && t.IsVisokosny( ) && !yearChanged )
	    --days;
	if ( !--t.m_ ) {
	    t.m_ = 12;
	    --t.y_;
	}
	index = t.m_ - 1;
    }

    t.d_ = monats[ index ] - days;

    return t;
}

int16_t Date29B::Interval( const Date29B & other ) const
{
    //считаем что дата other - последующая всегда
    //тоесть интервал от меньшего времени к большему
    int startY = y_;
    int endY = other.y_;
    if ( startY > endY )
	std::swap( startY, endY );
    //    for ( int i = startY;  )
    int coutYears = endY - startY - 1;
    int countVisokosnyLet = coutYears / 4;
    //крайние года не попадают в интервал
    int res = countVisokosnyLet * 366 + ( coutYears - countVisokosnyLet ) * 365;

    //MONATS
    if ( y_ != other.y_ ) {
	for ( int i = m_ + 1; i < 12; ++i ) {
	    res += monats[ i ];
	    if ( i == 1 && IsVisokosny( ) )
		++res;
	}
	for ( int i = 0; i <= other.m_; ++i ) {
	    res += monats[ i ];
	    if ( i == 1 && IsVisokosny( ) )
		++res;
	}
    } else {
	for ( int i = m_ + 1; i < other.m_; ++i ) {
	    res += monats[ i ];
	    if ( i == 1 && IsVisokosny( ) )
		++res;
	}
    }

    //DAYS
    if ( m_ != other.m_ ) {
	res += ( monats[ m_ - 1 ] - d_ ) + other.d_;
    } else {
	res += other.d_ - d_;
    }

    return res;
}

bool Date29B::IsVisokosny( ) const
{
    return ( ( y_ % 4 == 0 ) || ( ( y_ % 100 == 0 ) && ( y_ % 400 == 0 ) ) );
}

int16_t Date29B::Year( ) const
{
    return y_;
}

void Date29B::setYear( const int16_t & y )
{
    y_ = y;
}

int16_t Date29B::Month( ) const
{
    return m_;
}

void Date29B::setMonth( const int16_t & m )
{
    m_ = m;
}

int16_t Date29B::Day( ) const
{
    return d_;
}

void Date29B::setDay( const int16_t & d )
{
    d_ = d;
}
