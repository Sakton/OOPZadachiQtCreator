#include "car.h"
#include <iostream>

Car::Car( const std::string & name, int16_t cyl, int16_t pow )
    : name_ { name }
    , count_cylinder_ { cyl }
    , power_ { pow }
{
}

void Car::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Car::operator std::string( ) const {
  std::string type = typeid( *this ).name( );
  return "name = " + name_ + ", cyl = " + std::to_string( count_cylinder_ ) +
         ", power = " + std::to_string( power_ );
}

int16_t Car::power( ) const
{
    return power_;
}

void Car::setPower( const int16_t & power )
{
    power_ = power;
}

std::string Car::name( ) const
{
    return name_;
}

void Car::setName( const std::string & name )
{
    name_ = name;
}

int16_t Car::count_cylinder( ) const
{
    return count_cylinder_;
}

void Car::setCount_cylinder( const int16_t & count_cylinder )
{
    count_cylinder_ = count_cylinder;
}
