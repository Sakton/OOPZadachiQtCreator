#include "frame.h"

#include <QFrame>
#include <QStackedWidget>

Frame::Frame( QFrame *parent ) : QFrame( parent ) {
  setAutoFillBackground( true );
  setLineWidth( 10 );
  setFrameStyle( QFrame::Box | QFrame::Plain );
  setPalette( Qt::red );

  QFrame *center = new QFrame( this );
  center->setGeometry( geometry( ) );
  center->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  center->setLineWidth( 3 );
  center->setPalette( Qt::blue );
  // center->show( );

  //  QStackedWidget stacked( this );
  //  stacked.setGeometry( geometry( ) );
  //  stacked.addWidget( center );
  //  stacked.setCurrentWidget( center );
}

Frame::~Frame( ) {}
