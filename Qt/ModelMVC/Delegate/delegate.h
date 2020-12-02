#ifndef DELEGATE_H
#define DELEGATE_H

#include <QWidget>

class Delegate : public QWidget
{
  Q_OBJECT

 public:
  Delegate(QWidget *parent = nullptr);
  ~Delegate();
};
#endif // DELEGATE_H
