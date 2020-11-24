#ifndef GRIDLAY_H
#define GRIDLAY_H

#include <QWidget>

class GridLay : public QWidget
{
  Q_OBJECT

 public:
  GridLay(QWidget *parent = nullptr);
  ~GridLay();
};
#endif // GRIDLAY_H
