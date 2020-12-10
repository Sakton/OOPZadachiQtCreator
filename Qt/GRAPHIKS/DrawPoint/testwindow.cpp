#include "testwindow.h"

#include <QtCore/qmath.h>

#include <QPainter>

TestWindow::TestWindow(QWidget *parent)
    : QWidget(parent)
{
}

TestWindow::~TestWindow()
{
}

void TestWindow::paintEvent( QPaintEvent * /*event*/ ) {
  QPainter painter( this );
  painter.setRenderHint( QPainter::Antialiasing );
  painter.setPen( QPen( Qt::black, 10 ) );
  int n = 8;
  for ( int i = 0; i < n; ++i ) {
    qreal fAnfle = ::qDegreesToRadians( 360.0 * i / n );
    qreal x = 300 + ::cos( fAnfle ) * 50;
    qreal y = 200 + ::sin( fAnfle ) * 50;
    painter.drawPoint( QPointF( x, y ) );
  }

  QPen t = painter.pen( );
  painter.setPen( QPen( Qt::red, 3 ) );
  painter.drawLine( QPoint( 10, 10 ), QPoint( 300, 200 ) );
  painter.setPen( t );
}
