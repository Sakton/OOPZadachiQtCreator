#include "fractionbase.h"

#include <stdexcept>

FractionBase::FractionBase( int64_t w, int16_t f )
    : whole_ { 0 }, fractional_ { 1 } {
  if ( f < 0 || f >= 10000 ) {
    throw std::runtime_error( "ERROR ARG FRACTIONAL < 0 || >= 10000" );
  }
  whole_ = std::abs( w );
  negative = ( w < 0 ) ? true : false;
  fractional_ = std::abs( f );
}

int64_t FractionBase::getWhole( ) const { return whole_; }

void FractionBase::setWhole( const int64_t& whole ) { whole_ = whole; }

int16_t FractionBase::getFractional( ) const { return fractional_; }

void FractionBase::setFractional( const int16_t& fractional ) {
  fractional_ = fractional;
}

bool FractionBase::getNegative( ) const { return negative; }

void FractionBase::setNegative( bool value ) { negative = value; }
