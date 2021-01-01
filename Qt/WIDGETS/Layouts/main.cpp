#include <QApplication>
#include <QtWidgets>

#include "layouts.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  Layouts w;

  QPushButton *b1 = new QPushButton( "A" );
  QPushButton *b2 = new QPushButton( "B" );
  QPushButton *b3 = new QPushButton( "C" );

  //  QBoxLayout *box = new QBoxLayout( QBoxLayout::LeftToRight );
  QBoxLayout *box = new QBoxLayout( QBoxLayout::RightToLeft );

  //  box->addWidget( b1, 1 );
  //  box->addWidget( b2, 2 );
  //  box->addWidget( b3, 3 );

  // с растяжками
  box->addStretch( );  //это
  box->addWidget( b1 );
  box->addWidget( b2 );
  box->addWidget( b3 );
  box->addStretch( );

  w.setLayout( box );
  w.resize( 450, 40 );

  w.show( );
  return a.exec( );
}
