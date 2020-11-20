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
  // QObject::connect( &w, SIGNAL( counterChanged( int ) ), &lbl, SLOT( setNum( int ) ) );
  // TODO slot-signal
  QObject::connect( &w, static_cast< void ( Counter::* )( int, int ) >( &Counter::counterChanged ), &lbl,
                    static_cast< void ( QLabel::* )( int ) >( &QLabel::setNum ) );
  QObject::connect( &w, &Counter::goodbye, &a, &QApplication::quit );

  return a.exec( );
}
