#include "fraction.h"
#include <iostream>
#include <iterator>

Fraction::Fraction( int szCel, int szDrob )
{
    cel.reserve( szCel );
    drb.reserve( szDrob );
}

Fraction::Fraction( const std::string & c, const std::string & d )
    : Fraction( c.size( ), d.size( ) )
{
    std::copy( c.rbegin( ), c.rend( ), std::back_inserter( cel ) );
    std::copy( d.cbegin( ), d.cend( ), std::back_inserter( drb ) );

    //    std::copy( cel.cbegin( ), cel.cend( ), std::ostream_iterator< char >( std::cout, ", " ) );
    //    std::cout << std::endl;
    //    std::copy( drb.cbegin( ), drb.cend( ), std::ostream_iterator< char >( std::cout, ", " ) );
}

Fraction::Fraction( Fraction && oth ) noexcept
{
    cel = std::move( oth.cel );
    drb = std::move( oth.drb );
    oth.cel.clear( );
    oth.drb.clear( );
}

Fraction & Fraction::operator=( Fraction && oth ) noexcept
{
    if ( this != &oth ) {
        cel = std::move( oth.cel );
        drb = std::move( oth.drb );
        oth.cel.clear( );
        oth.drb.clear( );
    }
    return *this;
}
