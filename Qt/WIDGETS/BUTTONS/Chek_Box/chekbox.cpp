#include "chekbox.h"

#include <QCheckBox>
#include <QVBoxLayout>

ChekBox::ChekBox( QWidget *parent ) : QWidget( parent ) {
  QCheckBox *normal = new QCheckBox( tr( "&ОПРЕДЕЛЕННЫЙ ФЛАЖЕК" ) );
  normal->setChecked( true );
  QCheckBox *tristate = new QCheckBox( tr( "&НЕОПРЕДЕЛЕННЫЙ ФЛАЖЕК" ) );
  tristate->setTristate( true );
  tristate->setCheckState( Qt::PartiallyChecked );

  QVBoxLayout *l = new QVBoxLayout;
  l->addWidget( normal );
  l->addWidget( tristate );

  setLayout( l );
}

ChekBox::~ChekBox()
{
}

