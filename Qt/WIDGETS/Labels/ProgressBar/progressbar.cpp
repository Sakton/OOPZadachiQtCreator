#include "progressbar.h"

#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>

ProgressBar::ProgressBar( QWidget *parent ) : QWidget( parent ), progress_ { nullptr }, step { 50 } {
  progress_ = new QProgressBar;
  QPushButton *btn_next = new QPushButton( "&NEXT" );
  connect( btn_next, QOverload< bool >::of( &QPushButton::clicked ), this, QOverload<>::of( &ProgressBar::plus ) );
  QPushButton *btn_prev = new QPushButton( "&PREV" );
  connect( btn_prev, QOverload< bool >::of( &QPushButton::clicked ), this, QOverload<>::of( &ProgressBar::minus ) );

  QHBoxLayout *lt = new QHBoxLayout;
  lt->addWidget( progress_ );
  lt->addWidget( btn_next );
  lt->addWidget( btn_prev );

  setLayout( lt );
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::plus( ) { progress_->setValue( ++step ); }

void ProgressBar::minus( ) { progress_->setValue( --step ); }
