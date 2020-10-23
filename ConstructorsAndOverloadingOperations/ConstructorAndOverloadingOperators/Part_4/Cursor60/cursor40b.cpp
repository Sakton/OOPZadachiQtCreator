#include "cursor40b.h"

#include <iostream>

Cursor40B::Cursor40B( uint16_t c_x, uint16_t c_y, Cursor40B::VID vid,
                      Cursor40B::CURSOR_SIZE c_s, bool vsbl )
    : x_ { c_x },
      y_ { c_y },
      vid_ { vid },
      c_size_ { c_s },
      visible_ { vsbl } {}

void Cursor40B::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Cursor40B::ToString( ) const {
  std::string res;
  res = "Cursor: \n";
  res += +"X: " + std::to_string( x_ ) + "\n" + "Y: " + std::to_string( y_ ) +
         "\n";
  switch ( vid_ ) {
    case VID::HORIZONTAL:
      res += "Vid: HORIZONTAL \n";
      break;
    case VID::VERTICAL:
      res += "Vid: VERTICAL \n";
      break;
  }

  switch ( c_size_ ) {
    case CURSOR_SIZE::SZ1:
      res += "size: 1 \n";
      break;
    case CURSOR_SIZE::SZ2:
      res += "size: 2 \n";
      break;
    case CURSOR_SIZE::SZ3:
      res += "size: 3 \n";
      break;
  }

  return res;
}

uint16_t Cursor40B::x( ) const { return x_; }

void Cursor40B::setX( const uint16_t & x )
{
    x_ = x;
}

uint16_t Cursor40B::y( ) const
{
    return y_;
}

void Cursor40B::setY( const uint16_t & y )
{
    y_ = y;
}

Cursor40B::VID Cursor40B::vid( ) const
{
    return vid_;
}

void Cursor40B::setVid( const VID & vid )
{
    vid_ = vid;
}

bool Cursor40B::visible( ) const
{
    return visible_;
}

void Cursor40B::setVisible( bool visible )
{
    visible_ = visible;
}

Cursor40B::CURSOR_SIZE Cursor40B::c_size( ) const { return c_size_; }

void Cursor40B::setC_size( const CURSOR_SIZE &c_size ) { c_size_ = c_size; }
