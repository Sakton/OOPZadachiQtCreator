#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QWidget>

class GroupBox : public QWidget {
  Q_OBJECT

 public:
  GroupBox(QWidget *parent = nullptr);
  ~GroupBox();
};
#endif // GROUPBOX_H
