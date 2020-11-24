#include "stackwidget.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>

// TODO STACK WIDGET НЕ РЕШЕНО

void StackWidget::innt( int x ) { qDebug( ) << "x = " << x; }

StackWidget::StackWidget( QWidget *parent ) : QWidget( parent ) {
  setAutoFillBackground( true );
  resize( 800, 400 );
  setPalette( Qt::gray );
  QWidget *firstPageWidget = new QWidget( );
  firstPageWidget->setPalette( Qt::red );
  QWidget *secondPageWidget = new QWidget( );
  secondPageWidget->setPalette( Qt::blue );
  QWidget *thirdPageWidget = new QWidget( );
  thirdPageWidget->setPalette( Qt::green );

  QStackedWidget *stackedWidget = new QStackedWidget( this );
  stackedWidget->setWindowTitle( "QStackedWidget" );
  stackedWidget->resize( QSize( 600, 300 ) );
  stackedWidget->setPalette( Qt::gray );
  stackedWidget->addWidget( firstPageWidget );
  stackedWidget->addWidget( secondPageWidget );
  stackedWidget->addWidget( thirdPageWidget );

  QVBoxLayout *layout = new QVBoxLayout( );
  layout->addWidget( stackedWidget );

  setLayout( layout );

  QComboBox *pageComboBox = new QComboBox( this );
  pageComboBox->addItem( tr( "Page 1" ) );
  pageComboBox->addItem( tr( "Page 2" ) );
  pageComboBox->addItem( tr( "Page 3" ) );
  connect( pageComboBox, QOverload< int >::of( &QComboBox::activated ), stackedWidget,
           QOverload< int >::of( &QStackedWidget::setCurrentIndex ) );

  connect( pageComboBox, QOverload< int >::of( &QComboBox::activated ), this, QOverload< int >::of( &StackWidget::innt ) );

  stackedWidget->currentWidget( )->show( );
  stackedWidget->show( );
  pageComboBox->show( );
}

StackWidget::~StackWidget( ) {}
