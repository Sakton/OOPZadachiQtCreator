#include <QApplication>
#include <QTreeWidget>

#include "treewidget.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  TreeWidget w;
  w.show( );

  //  QTreeWidget *wgt = new QTreeWidget;
  //  QStringList list;
  //  list << "Folder"
  //       << "Used Space";
  //  wgt->setHeaderLabels( list );
  //  wgt->setSortingEnabled( true );

  //  QTreeWidgetItem *pwgtItem = new QTreeWidgetItem( wgt );
  //  pwgtItem->setText( 0, "Local Disk(C)" );

  //  QTreeWidgetItem *pewgtItemDir = nullptr;
  //  for ( int i = 0; i < 20; ++i ) {
  //    pewgtItemDir = new QTreeWidgetItem( pwgtItem );
  //    pewgtItemDir->setText( 0, "Directory" + QString::number( i ) );
  //    pewgtItemDir->setText( 1, QString::number( i ) + "MB" );
  //  }
  //  pwgtItem->setExpanded( true );
  //  wgt->resize( 350, 310 );

  //  wgt->show( );

  return a.exec( );
}
