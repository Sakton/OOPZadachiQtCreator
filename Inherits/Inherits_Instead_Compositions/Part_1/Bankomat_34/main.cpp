#include <iostream>

#include "bankomatprivate.h"
//#include "bankomatpublic.h"

int main( ) {
  //  try {
  //    BankomatPublic a( 1, 50, 50000,
  //                      BankomatPublic::SpecArray { 10, 10, 10, 10, 10 } );
  //    Display( a );
  //    a.SubCash( 1500 );
  //    Display( a );

  //    //я хочу засунуть в банкомат пачку
  //    //чтобы положить в банкомат надо сделать сперва стопку денег
  //    //как и в обычной жизни
  //    BankomatPublic::SpecArray MyCassete { 0 };
  //    MyCassete[ BankomatPublic::NOM_1000_RUR ] = 1;
  //    MyCassete[ BankomatPublic::NOM_500_RUR ] = 1;

  //    a.AddCash( MyCassete );
  //    Display( a );

  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //    a.SubCash( 300 );
  //    Display( a );
  //  } catch ( std::out_of_range &e ) {
  //    std::cerr << e.what( );
  //  } catch ( std::runtime_error &e ) {
  //    std::cerr << e.what( );
  //  } catch ( ... ) {
  //    std::cerr << "OTHER EXCEPTION";
  //  }

  //********************************************

  try {
    BankomatPrivate a( 1, 50, 50000,
                       BankomatPrivate::SpecArray { 10, 10, 10, 10, 10 } );
    Display( a );
    a.SubCash( 1500 );
    Display( a );

    //я хочу засунуть в банкомат пачку
    //чтобы положить в банкомат надо сделать сперва стопку денег
    //как и в обычной жизни
    BankomatPrivate::SpecArray MyCassete { 0 };
    MyCassete[ BankomatPrivate::NOMINALS::NOM_1000_RUR ] = 1;
    MyCassete[ BankomatPrivate::NOMINALS::NOM_500_RUR ] = 1;

    a.AddCash( MyCassete );
    Display( a );

    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
    a.SubCash( 300 );
    Display( a );
  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( );
  } catch ( ... ) {
    std::cerr << "OTHER EXCEPTION";
  }
}
