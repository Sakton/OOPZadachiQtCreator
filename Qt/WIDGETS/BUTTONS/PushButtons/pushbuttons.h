#ifndef PUSHBUTTONS_H
#define PUSHBUTTONS_H

#include <QWidget>

class PushButtons : public QWidget
{
  Q_OBJECT

 public:
  PushButtons(QWidget *parent = nullptr);
  ~PushButtons();
};
#endif // PUSHBUTTONS_H
