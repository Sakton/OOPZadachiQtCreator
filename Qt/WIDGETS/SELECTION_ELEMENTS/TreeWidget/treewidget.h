#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QMainWindow>

class TreeWidget : public QMainWindow
{
  Q_OBJECT

 public:
  TreeWidget(QWidget *parent = nullptr);
  ~TreeWidget();
};
#endif // TREEWIDGET_H
