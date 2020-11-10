//#include "widget.h"
//#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  QLabel lbl( "Hello World" );
  lbl.show( );
  //  Widget w;
  //  w.show();
  return a.exec();
}
