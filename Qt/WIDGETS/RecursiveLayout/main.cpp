#include <QApplication>
#include <QtWidgets>

#include "recursivelayout.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  RecursiveLayout w;

  QPushButton *pb1 = new QPushButton( "A" );
  QPushButton *pb2 = new QPushButton( "B" );
  QPushButton *pb3 = new QPushButton( "C" );
  QPushButton *pb4 = new QPushButton( "D" );

  QHBoxLayout *hbl = new QHBoxLayout;
  hbl->addWidget( pb3 );
  hbl->addWidget( pb4 );

  QVBoxLayout *vbl = new QVBoxLayout;
  vbl->addWidget( pb1 );
  vbl->addWidget( pb2 );
  vbl->addLayout( hbl );

  w.setLayout( vbl );

  w.show( );
  return a.exec();
}
