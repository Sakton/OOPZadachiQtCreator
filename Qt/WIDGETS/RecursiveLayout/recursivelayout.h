#ifndef RECURSIVELAYOUT_H
#define RECURSIVELAYOUT_H

#include <QWidget>

class RecursiveLayout : public QWidget {
  Q_OBJECT

 public:
  RecursiveLayout(QWidget *parent = nullptr);
  ~RecursiveLayout();
};
#endif // RECURSIVELAYOUT_H
