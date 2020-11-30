#include "listwidget.h"

#include <QDebug>
#include <QListWidget>

ListWidget::ListWidget( QWidget *parent ) : QWidget( parent ) {
  QListWidget *listw = new QListWidget( this );
  listw->setViewMode( QListWidget::ViewMode::ListMode );
  //  listw->addItem( "1111" );
  //  listw->addItem( "2222" );
  //  listw->addItem( "3333" );
  //  listw->addItem( "4444" );
  //  listw->addItem( "5555" );
  for ( int i = 0; i < 10; ++i ) {
    QString str( 3, i + 'a' );
    QListWidgetItem *t = new QListWidgetItem( str );
    t->setFlags( Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled );
    listw->addItem( t );
  }

  connect( listw, QOverload< QListWidgetItem * >::of( &QListWidget::itemClicked ), this, QOverload<>::of( &ListWidget::slotItemClicked ) );
  resize( 400, 500 );
}

ListWidget::~ListWidget()
{
}

void ListWidget::slotItemClicked( ) { qDebug( ) << "Tezasdcas"; }
