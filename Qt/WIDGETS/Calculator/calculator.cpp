#include "calculator.h"

#include <QGridLayout>
#include <QLCDNumber>

Calculator::Calculator( QWidget *parent ) : QWidget( parent ), tablo { nullptr } {
  tablo = new QLCDNumber;
  QGridLayout *grid = new QGridLayout;
  grid->addWidget( tablo, 0, 0, 0, 4 );
}

Calculator::~Calculator()
{
}

