#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QWidget>

class LineEdit : public QWidget
{
  Q_OBJECT

 public:
  LineEdit(QWidget *parent = nullptr);
  ~LineEdit();
};
#endif // LINEEDIT_H
