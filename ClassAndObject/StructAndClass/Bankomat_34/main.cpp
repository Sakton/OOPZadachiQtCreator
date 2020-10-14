#include "bankomat34b.h"
#include <iostream>

int main( )
{
    Bankomat34B a;
    a.Init( 1, 50, 50000, Bankomat34B::SpecArray { 10, 10, 10, 10, 10 } );
    a.Display( );
    a.SubCash( 1500 );
    a.Display( );

    //я хочу засунуть в банкомат пачку
    //чтобы положить в банкомат надо сделать сперва стопку денег
    //как и в обычной жизни
    Bankomat34B::SpecArray MyCassete { 0 };
    MyCassete[ Bankomat34B::NOM_1000_RUR ] = 1;
    MyCassete[ Bankomat34B::NOM_500_RUR ] = 1;

    a.AddCash( MyCassete );
    a.Display( );

    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
    a.SubCash( 300 );
    a.Display( );
}
