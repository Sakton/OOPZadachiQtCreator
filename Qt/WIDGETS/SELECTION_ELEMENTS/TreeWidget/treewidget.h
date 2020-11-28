#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

class TreeWidget : public QWidget {
  Q_OBJECT

 public:
  TreeWidget(QWidget *parent = nullptr);
  ~TreeWidget();
};
#endif // TREEWIDGET_H
