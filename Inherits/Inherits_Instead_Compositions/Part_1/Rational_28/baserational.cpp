#include "baserational.h"

#include <iostream>

BaseRational::BaseRational( int32_t x, int16_t y ) : chis_ { 1 }, znam_ { 1 } {
    if ( y == 0 ) {
        std::cout << "ERROR DIV ZERO" << std::endl;
        exit( 1 );
    }
    if ( x < 0 && y < 0 ) {
        x = -x;
        y = -y;
    }
    chis_ = x;
    znam_ = y;
    reduce( );
}

void BaseRational::reduce( ) {
    int aa = std::abs( chis_ );
    int bb = std::abs( znam_ );

    while ( bb ) {
        int t = aa % bb;
        aa = bb;
        bb = t;
    }
    // NOD - in aa;
    chis_ /= aa;
    znam_ /= aa;
}

int32_t BaseRational::znam( ) const { return znam_; }

void BaseRational::setZnam( const int32_t& znam ) { znam_ = znam; }

int32_t BaseRational::chis( ) const { return chis_; }

void BaseRational::setChis( const int32_t& chis ) { chis_ = chis; }

std::string ToString( const BaseRational& rt ) {
    return std::to_string( rt.chis_ ) + "/" + std::to_string( rt.znam_ );
}

void Display( const BaseRational& rt ) {
    std::cout << ToString( rt ) << std::endl;
}
