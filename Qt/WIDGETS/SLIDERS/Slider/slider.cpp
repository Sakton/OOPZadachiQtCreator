#include "slider.h"

#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

Slider::Slider( QWidget *parent ) : QWidget( parent ) {
  QSlider *psldr = new QSlider( Qt::Horizontal );
  psldr->setRange( 0, 9 );
  psldr->setPageStep( 2 );
  psldr->setValue( 3 );
  psldr->setTickInterval( 2 );
  psldr->setTickPosition( QSlider::TicksBelow );

  QLabel *label = new QLabel( "3" );
  label->setAlignment( Qt::AlignCenter );

  connect( psldr, QOverload< int >::of( &QSlider::valueChanged ), label, QOverload< int >::of( &QLabel::setNum ) );

  QVBoxLayout *layer = new QVBoxLayout;
  layer->addWidget( label );
  layer->addWidget( psldr );

  setLayout( layer );
}

Slider::~Slider()
{
}

