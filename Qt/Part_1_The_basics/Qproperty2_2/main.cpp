#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QString>
#include <QVariant>

#include "myclass.h"

int main( int argc, char *argv[] ) {
  QCoreApplication a( argc, argv );

  MyClass *myobj = new MyClass( );
  myobj->setProperty( "readOnly", QVariant( true ) );
  myobj->setProperty( "name", QVariant( "newString" ) );

  qDebug( ) << "prop readonly = " << myobj->property( "readOnly" ).toBool( );

  const QMetaObject *meta = myobj->metaObject( );
  for ( int i = 0; i < meta->propertyCount( ); ++i ) {
    const QMetaProperty mp = meta->property( i );
    qDebug( ) << "Ptype = " << mp.type( );
    qDebug( ) << "Pname = " << mp.name( );
    qDebug( ) << "Pval: = " << myobj->property( mp.name( ) );
  }

  return a.exec( );
}
