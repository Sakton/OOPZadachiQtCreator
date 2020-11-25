#include "scrollbar.h"

#include <QLCDNumber>
#include <QScrollBar>
#include <QVBoxLayout>

ScrollBar::ScrollBar( QWidget *parent ) : QWidget( parent ) {
  QLCDNumber *plcd = new QLCDNumber( 4 );
  QScrollBar *pscrol = new QScrollBar( Qt::Horizontal );

  connect( pscrol, QOverload< int >::of( &QScrollBar::valueChanged ), plcd, QOverload< int >::of( &QLCDNumber::display ) );

  QVBoxLayout *lay = new QVBoxLayout;
  lay->addWidget( plcd );
  lay->addWidget( pscrol );

  setLayout( lay );
}

ScrollBar::~ScrollBar()
{
}

