#include <QCoreApplication>
#include <QDebug>
#include <QObject>

int main(int argc, char *argv[])
{
  QCoreApplication a( argc, argv );

  QObject *root = new QObject;
  QObject *pobj1 = new QObject( root );
  QObject *pobj2 = new QObject( root );
  QObject *pobj3 = new QObject( pobj1 );
  QObject *pobj4 = new QObject( pobj1 );
  QObject *pobj5 = new QObject( pobj2 );
  QObject *pobj6 = new QObject( pobj2 );
  QObject *pobj7 = new QObject( pobj3 );
  QObject *pobj8 = new QObject( pobj3 );

  root->setObjectName( "rootObject" );
  pobj1->setObjectName( "object_1" );
  pobj2->setObjectName( "object_2" );
  pobj3->setObjectName( "object_3" );
  pobj4->setObjectName( "object_4" );
  pobj5->setObjectName( "object_5" );
  pobj6->setObjectName( "object_6" );
  pobj7->setObjectName( "object_7" );
  pobj8->setObjectName( "object_8" );

  for ( auto i = pobj8; i; i = i->parent( ) ) {
    qDebug( ) << i->objectName( );
    for ( int j = 0; j < i->children( ).size( ); ++j ) qDebug( ) << "    " << i->children( ).at( j )->objectName( );
  }

  //  std::stack< QObject * > st;
  //  while ( !st.empty( ) ) {
  //  }

  qDebug( ) << "find " << root->findChild< QObject * >( "object_8" )->objectName( );
  qDebug( ) << "find " << root->findChild< QObject * >( "object_7" )->objectName( );
  qDebug( ) << "find " << root->findChild< QObject * >( "object_1" )->objectName( );

  QList< QObject * > res = root->findChildren< QObject * >( );
  qDebug( ) << res;
  qDebug( ) << "\n\n-------------- root->dumpObjectInfo( ): ---------------- ";
  root->dumpObjectInfo( );
  qDebug( ) << "\n\n --------------- root->dumpObjectTree( ): ----------------";
  root->dumpObjectTree( );

  return a.exec( );
}
