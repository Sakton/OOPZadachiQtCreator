#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <memory>

template < typename T >
class Array {
public:
    static constexpr int MAX_ELEM = 100;

    explicit Array( int n = 0 );
    Array( const Array & ot );
    Array & operator=( const Array & ot );
    Array( Array && ot );
    Array & operator=( Array && ot );

    T & operator[]( int index );
    const T & operator[]( int index ) const;

    int Sz( ) const;

private:
    std::unique_ptr< T[] > ar_;
    int sz_;
};

//**********************************
template < typename T >
Array< T >::Array( int n )
    : ar_ { new T[ n ] {} }
    , sz_ { n }
{
    if ( n >= MAX_ELEM ) {
        std::cout << "ERROR";
        exit( 1 );
    }
}

template < typename T >
Array< T >::Array( const Array & ot )
{
    std::unique_ptr< T > t( new T[ ot.sz_ ] );
    for ( int i = 0; i < sz_; ++i ) {
        t[ i ] = ot.array_[ i ];
    }
    sz_ = ot.sz_;
    ar_ = std::move( t );
}

template < typename T >
Array< T > & Array< T >::operator=( const Array & ot )
{
    if ( this != &ot ) {
        std::unique_ptr< T[] > t( new T[ ot.sz_ ] );
        for ( int i = 0; i < ot.sz_; ++i ) {
            t[ i ] = ot.ar_[ i ];
        }
        sz_ = ot.sz_;
        ar_ = std::move( t );
    }
    return *this;
}

template < typename T >
Array< T >::Array( Array && ot )
{
    ar_ = std::move( ot.ar_ );
    sz_ = ot.sz_;
    ot.sz_ = 0;
}

template < typename T >
Array< T > & Array< T >::operator=( Array && ot )
{
    if ( this != &ot ) {
        ar_ = std::move( ot.ar_ );
        sz_ = ot.sz_;
        ot.sz_ = 0;
    }
    return *this;
}

template < typename T >
T & Array< T >::operator[]( int index )
{
    if ( index >= sz_ ) {
        std::cerr << "OUT OF RANGE";
        exit( 1 );
    }
    return ar_[ index ];
}

template < typename T >
const T & Array< T >::operator[]( int index ) const
{
    //return operator[]( index );
    if ( index >= sz_ ) {
        std::cerr << "OUT OF RANGE";
        exit( 1 );
    }
    return ar_[ index ];
}

template < typename T >
int Array< T >::Sz( ) const
{
    return sz_;
}

#endif // ARRAY_H
