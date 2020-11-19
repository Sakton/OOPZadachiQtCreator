#include <QCoreApplication>

#include "mysignal.h"
#include "myslot.h"

int main(int argc, char *argv[])
{
  QCoreApplication a( argc, argv );

  MySignal sign( &a );
  MySlot slot( &a );

  QObject::connect( &sign, &MySignal::doIt, &slot, &MySlot::slot );
  QObject::connect( &sign, &MySignal::sendString, &slot, &MySlot::stringSlot );

  sign.sendSignal( );

  return a.exec( );
}
