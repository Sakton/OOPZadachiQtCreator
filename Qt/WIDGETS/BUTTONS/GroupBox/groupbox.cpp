#include "groupbox.h"

#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>

GroupBox::GroupBox( QWidget *parent ) : QWidget( parent ) {
  QGroupBox *gBox = new QGroupBox( "&Colors", this );
  QRadioButton *r1 = new QRadioButton( tr( "КРЯСНЫЙ" ) );
  r1->setChecked( true );
  QRadioButton *r2 = new QRadioButton( tr( "СИНИЙ" ) );
  QRadioButton *r3 = new QRadioButton( tr( "ЗЕЛЕНЫЙ" ) );

  QVBoxLayout *vbox = new QVBoxLayout;
  vbox->addWidget( r1 );
  vbox->addWidget( r2 );
  vbox->addWidget( r3 );

  gBox->setLayout( vbox );
}

GroupBox::~GroupBox()
{
}

