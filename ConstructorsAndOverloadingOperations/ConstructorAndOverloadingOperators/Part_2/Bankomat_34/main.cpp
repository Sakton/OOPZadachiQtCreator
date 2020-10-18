#include <iostream>

#include "bankomat34.h"

int main( ) {
  Bankomat34 a( 1, 50, 50000, Bankomat34::SpecArray { 10, 10, 10, 10, 10 } );
  Display( a );
  SubCash( a, 1500 );
  Display( a );

  //я хочу засунуть в банкомат пачку
  //чтобы положить в банкомат надо сделать сперва стопку денег
  //как и в обычной жизни
  Bankomat34::SpecArray MyCassete { 0 };
  MyCassete[ Bankomat34::NOM_1000_RUR ] = 1;
  MyCassete[ Bankomat34::NOM_500_RUR ] = 1;

  AddCash( a, MyCassete );
  Display( a );

  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
  SubCash( a, 300 );
  Display( a );
}
