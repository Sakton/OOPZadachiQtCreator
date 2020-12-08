#include "vgt.h"

#include <QDebug>
#include <QKeyEvent>

Vgt::Vgt(QWidget *parent)
    : QWidget(parent)
{
}

Vgt::~Vgt()
{
}

void Vgt::keyPressEvent( QKeyEvent *event ) {
  switch ( event->key( ) ) {
    case Qt::Key_Space:
      qDebug( ) << "EEEEEEE!!! press Space";
      if ( event->modifiers( ) & Qt::ShiftModifier ) {
        qDebug( ) << "SHIFT EEEEEEE!!! press Space";
      }
      break;
    default:
      QWidget::keyPressEvent( event );
  }
}

void Vgt::mousePressEvent( QMouseEvent *event ) { qDebug( ) << "MMMMMMMMME!!! press Mouse"; }
