#include "trapezium.h"

#include <iostream>

Trapezium::Trapezium( double a, double b, double c, double d, double h )
    : a_ { a }, b_ { b }, c_ { c }, d_ { d }, h_ { h } {
  std::cout << "i'm trapezium" << std::endl;
}

double Trapezium::Area( ) { return ( a_ + b_ ) * h_ / 2; }

double Trapezium::Perimeter( ) { return a_ + b_ + c_ + d_; }
