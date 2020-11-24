#include <QApplication>
#include <QStackedWidget>
#include <QtWidgets>
#include <memory>

#include "stackwidget.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );

  StackWidget w;

  //  QWidget *firstPageWidget = new QWidget( );
  //  firstPageWidget->setPalette( QPalette( Qt::red ) );
  //  QWidget *secondPageWidget = new QWidget( );
  //  secondPageWidget->setPalette( QPalette( Qt::blue ) );
  //  QWidget *thirdPageWidget = new QWidget( );
  //  thirdPageWidget->setPalette( QPalette( Qt::green ) );

  //  std::unique_ptr< QStackedWidget > stackedWidget( new QStackedWidget );
  //  stackedWidget->setWindowTitle( "QStackedWidget" );
  //  stackedWidget->resize( QSize( 600, 300 ) );
  //  stackedWidget->setPalette( Qt::gray );
  //  stackedWidget->addWidget( firstPageWidget );
  //  stackedWidget->addWidget( secondPageWidget );
  //  stackedWidget->addWidget( thirdPageWidget );

  //  stackedWidget->show( );

  //  QPushButton push( "PUSH" );
  //  push.show( );

  //  QObject::connect( &push, QOverload< bool >::of( &QPushButton::clicked ), stackedWidget.get( ),
  //                    QOverload< int >::of( &QStackedWidget::setCurrentIndex ) );

  w.show( );

  return a.exec( );
}
