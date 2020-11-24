#include "stackwidget.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>

// TODO STACK WIDGET НЕ РЕШЕНО

StackWidget::StackWidget( QWidget *parent ) : QMainWindow( parent ) {
  QWidget *firstPageWidget = new QWidget;
  firstPageWidget->setPalette( QPalette( Qt::red ) );
  QWidget *secondPageWidget = new QWidget;
  secondPageWidget->setPalette( QPalette( Qt::blue ) );
  QWidget *thirdPageWidget = new QWidget;
  thirdPageWidget->setPalette( QPalette( Qt::green ) );

  QStackedWidget *stackedWidget = new QStackedWidget( this );
  stackedWidget->addWidget( firstPageWidget );
  stackedWidget->addWidget( secondPageWidget );
  stackedWidget->addWidget( thirdPageWidget );

  QVBoxLayout *layout = new QVBoxLayout( this );
  layout->addWidget( stackedWidget );
  setCentralWidget( stackedWidget );

  QComboBox *pageComboBox = new QComboBox( this );
  pageComboBox->addItem( tr( "Page 1" ) );
  pageComboBox->addItem( tr( "Page 2" ) );
  pageComboBox->addItem( tr( "Page 3" ) );
  connect( pageComboBox, QOverload< int >::of( &QComboBox::activated ), stackedWidget, &QStackedWidget::setCurrentIndex );
  stackedWidget->currentWidget( )->show( );
  stackedWidget->show( );
  pageComboBox->show( );
}

StackWidget::~StackWidget( ) {}
