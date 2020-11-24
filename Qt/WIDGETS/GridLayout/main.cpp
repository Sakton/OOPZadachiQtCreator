#include <QApplication>
#include <QtWidgets>

#include "gridlay.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  GridLay w;

  QPushButton *bp1 = new QPushButton( "A" );
  QPushButton *bp2 = new QPushButton( "B" );
  QPushButton *bp3 = new QPushButton( "C" );
  QPushButton *bp4 = new QPushButton( "D" );

  QGridLayout *grid = new QGridLayout;
  grid->setContentsMargins( QMargins( 30, 30, 30, 30 ) );
  grid->setSpacing( 15 );

  grid->addWidget( bp1, 0, 0 );
  grid->addWidget( bp2, 0, 1 );
  grid->addWidget( bp3, 1, 0 );
  grid->addWidget( bp4, 1, 1 );

  w.setLayout( grid );

  w.show( );
  return a.exec();
}
