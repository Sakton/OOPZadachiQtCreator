#include "lsd.h"

#include <QLCDNumber>
#include <QSpinBox>
#include <QVBoxLayout>

LSD::LSD( QWidget *parent ) : QWidget( parent ), lsd_ { nullptr } {
  lsd_ = new QLCDNumber( 2, this );
  lsd_->setMode( QLCDNumber::Hex );
  QSpinBox *spin = new QSpinBox;

  connect( spin, QOverload< int >::of( &QSpinBox::valueChanged ), lsd_, QOverload< int >::of( &QLCDNumber::display ) );

  QVBoxLayout *box = new QVBoxLayout;
  box->addWidget( lsd_ );
  box->addWidget( spin );
  setLayout( box );
}

LSD::~LSD()
{
}

