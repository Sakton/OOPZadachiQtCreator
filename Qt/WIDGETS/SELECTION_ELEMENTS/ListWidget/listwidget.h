#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>

class ListWidget : public QWidget
{
  Q_OBJECT

 public:
  ListWidget(QWidget *parent = nullptr);
  ~ListWidget();
};
#endif // LISTWIDGET_H
