#include <iostream>

#include "bankomat34.h"

int main( ) {
  Bankomat34 a( 1, 50, 50000, Bankomat34::Money33( 100000 ) );
  a.Display( );
  a.SubCash( 1000 );
  a.Display( );

  //я хочу засунуть в банкомат пачку
  //чтобы положить в банкомат надо сделать сперва стопку денег
  //как и в обычной жизни
  //  Bankomat34::SpecArray MyCassete { 0 };
  //  MyCassete[ Bankomat34::NOM_1000_RUR ] = 1;
  //  MyCassete[ Bankomat34::NOM_500_RUR ] = 1;

  a.AddCash( 1000 );
  a.Display( );

  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
  a.SubCash( 10000 );
  a.Display( );
}
