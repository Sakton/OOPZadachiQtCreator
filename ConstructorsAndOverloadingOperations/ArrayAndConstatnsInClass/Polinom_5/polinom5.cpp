#include "polinom5.h"
#include <iostream>

Polinom5::Polinom5( int n )
    : data_ { new double[ n ] }
    , size_ { n }
{
    if ( n < 0 || n > MAX_IND ) {
        std::cout << "ERROR SIZE";
        exit( 1 );
    }
    for ( int i = 0; i < n; ++i ) {
        data_[ i ] = 0;
    }
}

Polinom5::Polinom5( const std::vector< double > & v )
    : Polinom5( v.size( ) )
{
    int i = 0;
    for ( auto el : v )
        ( *this )[ i++ ] = el;
}

Polinom5::Polinom5( const double array[], int n )
    : Polinom5( n )
{
    for ( int i = 0; i < n; ++i )
        ( *this )[ i ] = array[ i ];
}

Polinom5::Polinom5( std::unique_ptr< double[] > & arr, int n )
    : data_( std::move( arr ) )
    , size_ { n }
{
}

Polinom5::Polinom5( const Polinom5 & oth )
{
    std::unique_ptr< double[] > cpy( new double[ oth.size_ ] );
    for ( int i = 0; i < oth.size_; ++i ) {
        cpy[ i ] = oth.data_[ i ];
    }
    data_ = std::move( cpy );
    size_ = oth.size_;
}

Polinom5::Polinom5( Polinom5 && oth ) noexcept
{
    data_ = std::move( oth.data_ );
    size_ = oth.size_;
    oth.size_ = 0;
}

Polinom5 & Polinom5::operator=( const Polinom5 & oth )
{
    if ( this != &oth ) {
        std::unique_ptr< double[] > cpu( new double[ oth.size_ ] );
        for ( int i = 0; i < oth.size_; ++i ) {
            data_[ i ] = oth.data_[ i ];
        }
        data_ = std::move( cpu );
        size_ = oth.size_;
    }
    return *this;
}

Polinom5 & Polinom5::operator=( Polinom5 && oth ) noexcept
{
    if ( this != &oth ) {
        data_ = std::move( oth.data_ );
        size_ = oth.size_;
    }
    return *this;
}

Polinom5 & Polinom5::operator*=( const Polinom5 & other )
{
    std::unique_ptr< double[] > res( new double[ size_ + other.size_ ] { 0 } );
    for ( int i = 0; i < size_; ++i ) {
        for ( int j = 0; j < other.size_; ++j ) {
            res[ i + j ] += data_[ i ] * other.data_[ j ];
        }
    }
    size_ += other.size_;
    data_ = std::move( res );
    return *this;
}

void Polinom5::Read( )
{
    std::cout << "enter coefficients pri X starting out in zero x-element" << std::endl;
    int count = 0;
    do {
        std::cout << "enter cofficient at x^" << ( size_ - 1 - count ) << std::endl;
        std::cin >> ( *this )[ count++ ];
    } while ( count < size_ );
}

void Polinom5::Display( ) const
{
    for ( int i = 0; i < size_; ++i ) {
        if ( size_ - 1 - i )
            std::cout << ( *this )[ i ] << "*(x^" << ( size_ - 1 - i ) << ") + ";
        else
            std::cout << ( *this )[ i ];
    }
}

const double & Polinom5::operator[]( int ind ) const
{
    return data_[ size_ - 1 - ind ];
}

long double Polinom5::Estimation( double x ) const
{
    long double result = 0;
    long double powArg = 1;
    for ( int i = 0; i < size_; ++i ) {
        //result += data_[ i ] * FastPow( x, i );
        result += data_[ i ] * powArg;
        //улучшение вместо вычисления степени раз за разом, копим степень на каждой итерации
        //домножая на x
        powArg *= x;
    }
    return result;
}

Polinom5 Polinom5::Differentiation( )
{
    std::unique_ptr< double[] > diff_array( new double[ size_ - 1 ] );
    for ( int i = 0; i < size_ - 1; ++i ) {
        diff_array[ i ] = DiffOne( data_[ i + 1 ], i + 1 ); //не дойдет до 0-й степени
    }
    Polinom5 res( diff_array, size_ - 1 );
    return res;
}

Polinom5 Polinom5::Integration( )
{
    if ( size_ + 1 > MAX_IND ) {
        std::cout << "ERROR SIZE INTEGRAL";
        exit( 1 );
    }
    std::unique_ptr< double[] > integ_array( new double[ size_ + 1 ] );
    integ_array[ 0 ] = 1;
    for ( int i = 0; i < size_; ++i ) {
        integ_array[ i + 1 ] = IntegrOne( data_[ i ], i + 1 );
    }
    Polinom5 res( integ_array, size_ + 1 );
    return res;
}

double Polinom5::FastPow( double x, int y ) const
{
    if ( y == 0 )
        return 1;
    if ( y % 2 == 0 )
        return FastPow( x * x, y / 2 );
    else
        return x * FastPow( x, y - 1 );
}

double Polinom5::DiffOne( double coeff, int stepen )
{
    return coeff * stepen;
}

double Polinom5::IntegrOne( double coeff, int stepen )
{
    return ( stepen == 0 ) ? coeff : coeff / stepen;
}

double & Polinom5::operator[]( int ind )
{
    return data_[ size_ - 1 - ind ];
}
