#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>

class QSlider;

class Slider : public QWidget
{
  Q_OBJECT

 public:
  Slider(QWidget *parent = nullptr);
  ~Slider();
};
#endif // SLIDER_H
