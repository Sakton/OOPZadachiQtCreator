#ifndef LSD_H
#define LSD_H

#include <QWidget>

class QLCDNumber;

class LSD : public QWidget {
  Q_OBJECT

 public:
  LSD(QWidget *parent = nullptr);
  ~LSD( );

 private:
  QLCDNumber *lsd_;
};
#endif // LSD_H
