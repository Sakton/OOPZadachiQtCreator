#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>

class QListWidgetItem;

class ListWidget : public QWidget {
  Q_OBJECT

 public:
  ListWidget(QWidget *parent = nullptr);
  ~ListWidget( );

 public slots:
  void slotItemClicked( );
};
#endif // LISTWIDGET_H
