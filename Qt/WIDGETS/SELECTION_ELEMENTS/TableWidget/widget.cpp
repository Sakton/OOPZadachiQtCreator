#include "widget.h"

#include <QTableWidget>

Widget::Widget( QWidget *parent ) : QWidget( parent ) {
  int n = 3;
  QTableWidget *tab = new QTableWidget( n, n, this );
  tab->resize( 500, 200 );

  QStringList lst;
  lst << "First"
      << "Second"
      << "Third";

  tab->setHorizontalHeaderLabels( lst );
  tab->setVerticalHeaderLabels( lst );
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      tab->setItem( i, j, new QTableWidgetItem( QString( "%1, %2" ).arg( i ).arg( j ) ) );
    }
  }
}

Widget::~Widget()
{
}

