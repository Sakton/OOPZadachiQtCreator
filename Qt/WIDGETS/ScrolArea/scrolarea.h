#ifndef SCROLAREA_H
#define SCROLAREA_H

#include <QMainWindow>

class ScrolArea : public QMainWindow
{
  Q_OBJECT

 public:
  ScrolArea(QWidget *parent = nullptr);
  ~ScrolArea();
};
#endif // SCROLAREA_H
