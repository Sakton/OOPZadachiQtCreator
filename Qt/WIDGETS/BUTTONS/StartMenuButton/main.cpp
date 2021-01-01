#include <QApplication>
#include <QMenu>
#include <QPushButton>

#include "startmenubutton.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  //  StartMenuButton w;
  //  w.show();

  QPushButton *btn = new QPushButton( QPushButton::tr( "&МЕНЮ" ) );
  QMenu *m = new QMenu( btn );

  m->addAction( "Action1" );
  m->addAction( "Action2" );
  m->addAction( "Quit", &a, QOverload<>::of( &QApplication::quit ) );

  btn->setMenu( m );

  btn->show( );

  return a.exec( );
}
