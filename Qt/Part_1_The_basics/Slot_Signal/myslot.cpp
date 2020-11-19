#include "myslot.h"

#include <QDebug>

MySlot::MySlot(QObject *parent) : QObject(parent)
{
  
}

void MySlot::slot( ) {
  qDebug( ) << "my Slot";
  qDebug( ) << "sender = " << sender( )->objectName( );
}

void MySlot::stringSlot( const QString &str ) { qDebug( ) << "MySlot::stringSlot:: " << str; }
