#include <QApplication>
#include <QTextEdit>

#include "syntax.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );

  QTextEdit text( "11 sdfsdfs 11 sfwerfwe 33 sdfsf" );

  Syntax syn( text.document( ) );

  text.show( );
  return a.exec( );
}
