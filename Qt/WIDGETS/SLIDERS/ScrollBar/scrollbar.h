#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QWidget>

class ScrollBar : public QWidget
{
  Q_OBJECT

 public:
  ScrollBar(QWidget *parent = nullptr);
  ~ScrollBar();
};
#endif // SCROLLBAR_H
