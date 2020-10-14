#ifndef FACTORY_H
#define FACTORY_H
#include "circle.h"
#include "rectangle.h"
#include "trapezium.h"

//ПАТТЕРН АБСТРАКТНАЯ ФАБРИКА - тут можно создавать классыс
//параметрами!!!!!!!!!!!!

class Factory {
 public:
  Factory( ) {}
  Figure* MakeCirkle( double r ) { return new Circle( r ); }
  Figure* MakeRect( double a, double b ) { return new Rectangle( a, b ); }
  Figure* MakeTrapezium( double a, double b, double c, double d, double h ) {
    return new Trapezium( a, b, c, d, h );
  }
};

// class CircleFactory : public Factory {
// public:
//  Figure *create( ) override { return new Circle( ); }
//};

// class RectFactory : public Factory {
// public:
//  Figure *create( ) override { return new Rectangle( ); }
//};

// class TrapeziumFactory : public Factory {
// public:
//  Figure *create( ) override { return new Trapezium( ); }
//};

#endif // FACTORY_H
