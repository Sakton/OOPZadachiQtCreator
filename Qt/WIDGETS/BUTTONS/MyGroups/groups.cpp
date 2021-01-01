#include "groups.h"

#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

Groups::Groups( QWidget *parent )
    : QGroupBox( "InCtor", parent ), chb_ { nullptr }, red_ { nullptr }, blue_ { nullptr }, green_ { nullptr } {
  resize( 500, 300 );
  setCheckable( true );
  setChecked( true );

  red_ = new QRadioButton( "&RED" );
  blue_ = new QRadioButton( "&BLUE" );
  green_ = new QRadioButton( "&GREEN" );
  green_->setChecked( true );

  connect( red_, QOverload< bool >::of( &QRadioButton::clicked ), this, QOverload<>::of( &Groups::slotChekRadio ) );
  connect( blue_, QOverload< bool >::of( &QRadioButton::clicked ), this, QOverload<>::of( &Groups::slotChekRadio ) );
  connect( green_, QOverload< bool >::of( &QRadioButton::clicked ), this, QOverload<>::of( &Groups::slotChekRadio ) );

  chb_ = new QCheckBox( "&Light" );
  connect( chb_, QOverload< bool >::of( &QCheckBox::clicked ), this, QOverload<>::of( &Groups::slotChekRadio ) );

  QPushButton *pbtn = new QPushButton( "&Exit" );
  connect( pbtn, QOverload< bool >::of( &QPushButton::clicked ), this, QOverload<>::of( &Groups::slotChekRadio ) );

  QVBoxLayout *lt = new QVBoxLayout( this );
  lt->addWidget( red_ );
  lt->addWidget( blue_ );
  lt->addWidget( green_ );
  lt->addWidget( chb_ );
  lt->addWidget( pbtn );

  setLayout( lt );

  slotChekRadio( );
}

Groups::~Groups()
{
}

void Groups::slotChekRadio( ) {
  QPalette pal = palette( );
  int nLight = chb_->isChecked( ) ? 80 : 150;
  if ( red_->isChecked( ) ) {
    pal.setColor( QPalette::ColorRole::Background, QColor( Qt::red ).darker( nLight ) );
  }
  if ( blue_->isChecked( ) ) {
    pal.setColor( QPalette::ColorRole::Background, QColor( Qt::blue ).darker( nLight ) );
  }
  if ( green_->isChecked( ) ) {
    pal.setColor( QPalette::ColorRole::Background, QColor( Qt::green ).darker( nLight ) );
  }
  setPalette( pal );
}
