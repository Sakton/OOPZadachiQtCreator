#include "polinom.h"

Polinom::Polinom( int n )
    : Array< double >( n )
{
    if ( n < 0 || n > MAX_ELEM ) {
        std::cout << "ERROR SIZE";
        exit( 1 );
    }
    for ( int i = 0; i < n; ++i ) {
        ( *this )[ i ] = 0;
    }
}

Polinom::Polinom( const std::vector< double > & v )
    : Polinom( v.size( ) )
{
    int i = 0;
    for ( auto el : v )
        ( *this )[ i++ ] = el;
}

Polinom::Polinom( const double array[], int n )
    : Polinom( n )
{
    for ( int i = 0; i < n; ++i )
        ( *this )[ i ] = array[ i ];
}

Polinom::Polinom( std::unique_ptr< double[] > & arr, int n )
    : Polinom( n )
{
    for ( int i = 0; i < n; ++i )
        ( *this )[ i ] = arr[ i ];
}

Polinom::Polinom( const Polinom & oth )
{
    ( *this ) = oth;
}

Polinom::Polinom( Polinom && oth ) noexcept
{
    ( *this ) = oth;
}

Polinom & Polinom::operator=( const Polinom & oth )
{
    if ( this != &oth ) {
        Array::operator=( oth );
    }
    return *this;
}

Polinom & Polinom::operator=( Polinom && oth ) noexcept
{
    if ( this != &oth ) {
        Array::operator=( oth );
    }
    return *this;
}

Polinom & Polinom::operator*=( const Polinom & other )
{
    Polinom t( Sz( ) + other.Sz( ) );
    for ( int i = 0; i < Sz( ); ++i ) {
        for ( int j = 0; j < other.Sz( ); ++j ) {
            t[ i + j ] += ( *this )[ i ] * other[ j ];
        }
    }
    *this = t;
    return *this;
}

void Polinom::Read( )
{
    std::cout << "enter coefficients pri X starting out in zero x-element" << std::endl;
    int count = 0;
    do {
        std::cout << "enter cofficient at x^" << ( Sz( ) - 1 - count ) << std::endl;
        std::cin >> ( *this )[ count++ ];
    } while ( count < Sz( ) );
}

void Polinom::Display( ) const
{
    for ( int i = 0; i < Sz( ); ++i ) {
        if ( Sz( ) - 1 - i )
            std::cout << ( *this )[ i ] << "*(x^" << ( Sz( ) - 1 - i ) << ") + ";
        else
            std::cout << ( *this )[ i ];
    }
}

const double & Polinom::operator[]( int ind ) const
{
    return Array::operator[]( Sz( ) - 1 - ind );
}

long double Polinom::Estimation( double x ) const
{
    long double result = 0;
    long double powArg = 1;
    for ( int i = 0; i < Sz( ); ++i ) {
        result += ( *this )[ i ] * powArg;
        //улучшение вместо вычисления степени раз за разом, копим степень на каждой итерации
        //домножая на x
        powArg *= x;
    }
    return result;
}

Polinom Polinom::Differentiation( )
{
    std::unique_ptr< double[] > diff_array( new double[ Sz( ) - 1 ] );
    for ( int i = 0; i < Sz( ) - 1; ++i ) {
        diff_array[ i ] = DiffOne( ( *this )[ i + 1 ], i + 1 ); //не дойдет до 0-й степени
    }
    Polinom res( diff_array, Sz( ) - 1 );
    return res;
}

Polinom Polinom::Integration( )
{
    if ( Sz( ) + 1 > MAX_ELEM ) {
        std::cout << "ERROR SIZE INTEGRAL";
        exit( 1 );
    }
    std::unique_ptr< double[] > integ_array( new double[ Sz( ) + 1 ] );
    integ_array[ 0 ] = 1;
    for ( int i = 0; i < Sz( ); ++i ) {
        integ_array[ i + 1 ] = IntegrOne( ( *this )[ i ], i + 1 );
    }
    Polinom res( integ_array, Sz( ) + 1 );
    return res;
}

double Polinom::FastPow( double x, int y ) const
{
    if ( y == 0 )
        return 1;
    if ( y % 2 == 0 )
        return FastPow( x * x, y / 2 );
    else
        return x * FastPow( x, y - 1 );
}

double Polinom::DiffOne( double coeff, int stepen )
{
    return coeff * stepen;
}

double Polinom::IntegrOne( double coeff, int stepen )
{
    return ( stepen == 0 ) ? coeff : coeff / stepen;
}

double & Polinom::operator[]( int ind )
{
    return Array::operator[]( Sz( ) - 1 - ind );
}
