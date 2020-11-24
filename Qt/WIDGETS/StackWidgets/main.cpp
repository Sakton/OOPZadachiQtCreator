#include "stackwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  StackWidget w;

  w.show( );
  return a.exec( );
}
