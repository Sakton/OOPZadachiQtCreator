#include "dial.h"

#include <QDial>
#include <QProgressBar>
#include <QVBoxLayout>

Dial::Dial( QWidget *parent ) : QWidget( parent ) {
  QDial *dial = new QDial;
  dial->setRange( 0, 100 );
  dial->setNotchesVisible( true );
  QProgressBar *pb = new QProgressBar;

  connect( dial, QOverload< int >::of( &QDial::valueChanged ), pb, QOverload< int >::of( &QProgressBar::setValue ) );
  QVBoxLayout *bl = new QVBoxLayout;
  bl->addWidget( dial );
  bl->addWidget( pb );

  setLayout( bl );
}

Dial::~Dial()
{
}

