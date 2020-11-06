#include "man6.h"
#include <iostream>

Man6::Man6( const std::string& name, int16_t age, std::string sex,
            int16_t weight )
    : name_ { name }, age_ { age }, sex_ { sex }, weight_ { weight } {}

void Man6::Display( ) const { std::cout << std::string( *this ) << std::endl; }

Man6::operator std::string( ) const {
  return name_ + ", age: " + std::to_string( age_ ) + ", sex: " + sex_ +
         ", weight: " + std::to_string( weight_ );
}

std::string Man6::name( ) const { return name_; }

void Man6::setName( const std::string& name ) { name_ = name; }

int16_t Man6::age( ) const { return age_; }

void Man6::setAge( const int16_t& age ) { age_ = age; }

std::string Man6::sex( ) const { return sex_; }

void Man6::setSex( const std::string& sex ) { sex_ = sex; }

int16_t Man6::weight( ) const { return weight_; }

void Man6::setWeight( const int16_t& weight ) { weight_ = weight; }
