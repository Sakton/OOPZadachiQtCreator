#include "student.h"
#include <iostream>

Student::Student( const std::string & name, int16_t age, std::string sex, int16_t weight, int16_t year )
    : Man6( name, age, sex, weight )
    , year_ { year }
{
}

void Student::Display( ) const
{
    std::cout << std::string( *this ) << std::endl;
}

Student & Student::operator=( const Man6 & oth )
{
    this->Man6::operator=( oth );
    return *this;
}

Student::operator std::string( ) const
{
    return this->Man6::operator std::string( ) + ", years: " + std::to_string( year_ );
}

int16_t Student::year( ) const
{
    return year_;
}

void Student::setYear( const int16_t & year )
{
    year_ = year;
}
