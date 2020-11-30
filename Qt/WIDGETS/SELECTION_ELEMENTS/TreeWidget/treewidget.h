#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

class TreeWidget : public QWidget {
  Q_OBJECT

 public:
  TreeWidget(QWidget *parent = nullptr);
  ~TreeWidget();

 public slots:
  void slotTree( );
};
#endif // TREEWIDGET_H
