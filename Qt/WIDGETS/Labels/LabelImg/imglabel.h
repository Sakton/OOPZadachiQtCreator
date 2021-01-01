#ifndef IMGLABEL_H
#define IMGLABEL_H

#include <QWidget>

class ImgLabel : public QWidget
{
  Q_OBJECT

 public:
  ImgLabel(QWidget *parent = nullptr);
  ~ImgLabel();
};
#endif // IMGLABEL_H
