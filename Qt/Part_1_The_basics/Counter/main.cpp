#include <QApplication>
#include <QObject>
#include <QtWidgets>

#include "counter.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Counter w;
  QLabel lbl( "0" );
  lbl.setAlignment( Qt::AlignCenter );

  QPushButton cmd( "ADD" );
  cmd.move( 500, 500 );
  lbl.show( );
  cmd.show( );

  QObject::connect( &cmd, &QPushButton::clicked, &w, &Counter::slotInc );

  return a.exec( );
}
