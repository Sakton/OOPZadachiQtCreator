#include "object.h"

#include <iostream>

int Object::COUNT = 0;

Object::Object( ) {
  ++COUNT;
  std::cout << COUNT << std::endl;
}

Object::~Object( ) {
  --COUNT;
  std::cout << COUNT << std::endl;
}

int Object::getCOUNT( ) { return COUNT; }
