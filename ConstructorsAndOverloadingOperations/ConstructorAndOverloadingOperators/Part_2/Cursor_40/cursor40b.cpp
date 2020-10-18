#include "cursor40b.h"

uint16_t Cursor40B::x( ) const
{
    return x_;
}

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

int16_t Cursor40B::size( ) const
{
    return size_;
}

void Cursor40B::setSize( const int16_t & size )
{
    size_ = size;
}

bool Cursor40B::visible( ) const
{
    return visible_;
}

void Cursor40B::setVisible( bool visible )
{
    visible_ = visible;
}
