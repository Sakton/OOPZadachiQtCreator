#include <QApplication>
#include <QPalette>

#include "typewidgets.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TypeWidgets w;
  // w.setWindowFlags( Qt::WindowTitleHint );
  // w.setWindowFlags( Qt::WindowCloseButtonHint );
  // w.setWindowFlags( Qt::WindowTitleHint );
  // w.setWindowFlags( Qt::WindowContextHelpButtonHint );
  // w.setWindowFlags( Qt::WindowStaysOnBottomHint );

  QPalette pal1;
  pal1.setBrush( QPalette::Background, QBrush( QPixmap( ":/resources/Кроссворд.jpg" ) ) );
  w.setPalette( pal1 );
  //  w.resize( 800, 500 );
  //  w.setAutoFillBackground( true );

  w.show( );
  return a.exec();
}
