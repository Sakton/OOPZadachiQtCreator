#include <QApplication>
#include <QScrollArea>

#include "scrolarea.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ScrolArea w;

  QScrollArea sc;
  sc.setWidget( &w );

  // w.show( );
  sc.show( );
  return a.exec();
}
