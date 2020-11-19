#include "mysignal.h"

MySignal::MySignal( QObject* parent ) : QObject( parent ) {}

void MySignal::sendSignal( ) {
  emit doIt( );
  emit sendString( "StringSignal" );
}
