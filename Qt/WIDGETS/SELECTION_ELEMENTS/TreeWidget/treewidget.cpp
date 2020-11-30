#include "treewidget.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QTreeWidget>

TreeWidget::TreeWidget( QWidget *parent ) : QWidget( parent ) {
  QTreeWidget *wgt = new QTreeWidget( this );
  QStringList list;
  list << "Folder"
       << "Used Space";
  wgt->setHeaderLabels( list );
  wgt->setSortingEnabled( true );

  QTreeWidgetItem *pwgtItem = new QTreeWidgetItem( wgt );
  pwgtItem->setText( 0, "Local Disk(C)" );

  QTreeWidgetItem *pewgtItemDir = nullptr;
  for ( int i = 1; i < 20; ++i ) {
    pewgtItemDir = new QTreeWidgetItem( pwgtItem );
    pewgtItemDir->setText( 0, "Directory" + QString::number( i ) );
    pewgtItemDir->setText( 1, QString::number( i ) + "MB" );
  }
  pwgtItem->setExpanded( true );
  resize( 350, 310 );

  connect( wgt, QOverload< QTreeWidgetItem *, int >::of( &QTreeWidget::itemClicked ), this, QOverload<>::of( &TreeWidget::slotTree ) );

  //  QHBoxLayout *box = new QHBoxLayout( this );
  //  box->addWidget( wgt );
  //  setLayout( box );

  QTreeWidgetItemIterator it( wgt, QTreeWidgetItemIterator::All );
  while ( *( ++it ) ) {
    qDebug( ) << ( *it )->text( 0 );
  }
}

TreeWidget::~TreeWidget( ) {}

void TreeWidget::slotTree( ) { qDebug( ) << "slotTree"; }
