#ifndef STARTMENUBUTTON_H
#define STARTMENUBUTTON_H

#include <QWidget>

class StartMenuButton : public QWidget
{
  Q_OBJECT

 public:
  explicit StartMenuButton( QWidget *parent = nullptr );
  ~StartMenuButton();
};
#endif // STARTMENUBUTTON_H
