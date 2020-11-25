#ifndef DIAL_H
#define DIAL_H

#include <QWidget>

class Dial : public QWidget
{
  Q_OBJECT

 public:
  Dial(QWidget *parent = nullptr);
  ~Dial();
};
#endif // DIAL_H
