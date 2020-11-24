#include <QApplication>
#include <QtWidgets>

#include "horisontallayout.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  HorisontalLayout w;

  QPushButton *pb1 = new QPushButton( "A" );
  QPushButton *pb2 = new QPushButton( "B" );
  QPushButton *pb3 = new QPushButton( "C" );

  // QHBoxLayout *lay = new QHBoxLayout;
  QVBoxLayout *lay = new QVBoxLayout;
  lay->setContentsMargins( QMargins( 50, 50, 50, 50 ) );
  lay->setSpacing( 20 );
  lay->addWidget( pb1 );
  lay->addWidget( pb2 );
  lay->addWidget( pb3 );

  w.setLayout( lay );

  w.show( );
  return a.exec( );
}
