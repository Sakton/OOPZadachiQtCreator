#include "calculator.h"

#include <QDebug>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <algorithm>

Calculator::Calculator( QWidget *parent ) : QWidget( parent ), tablo_ { nullptr } {
  tablo_ = new QLCDNumber;
  tablo_->setSegmentStyle( QLCDNumber::SegmentStyle::Filled );
  tablo_->setMinimumSize( 150, 50 );
  tablo_->setDigitCount( 20 );
  QGridLayout *grid = new QGridLayout( this );
  grid->addWidget( tablo_, 0, 0, 1, LEN );
  grid->addWidget( createButton( "CE" ), 1, 3 );
  QString symbols( "789/456*123-0.=+" );
  int k = 0;
  for ( int i = 0; i < LEN; ++i ) {
    for ( int j = 0; j < LEN; ++j ) {
      grid->addWidget( createButton( symbols.at( ( k++ ) % ( LEN * LEN ) ) ), i + 2, j );
    }
  }

  setLayout( grid );
}

Calculator::~Calculator()
{
}

QPushButton *Calculator::createButton( const QString &str ) {
  QPushButton *btn = new QPushButton( str );
  btn->setMinimumSize( 40, 40 );
  connect( btn, QOverload< bool >::of( &QPushButton::clicked ), this, QOverload<>::of( &Calculator::slotsButtonClicked ) );
  return btn;
}

void Calculator::slotsButtonClicked( ) {
  QString text = static_cast< QPushButton * >( sender( ) )->text( );
  if ( "CE" == text ) {
    stack_.clear( );
    strDisplay_.clear( );
    tablo_->display( "0" );
  }
  if ( "0" <= text && text <= "9" ) {
    strDisplay_ += text;
    tablo_->display( strDisplay_ );
  }
  if ( !strDisplay_.isEmpty( ) && ( "." == text ) ) {
    if ( std::find( strDisplay_.cbegin( ), strDisplay_.cend( ), "." ) == strDisplay_.cend( ) ) {
      strDisplay_ += text;
      tablo_->display( strDisplay_ );
    }
  }
  if ( "+" == text || "-" == text || "*" == text || "/" == text ) {
    stack_.push( strDisplay_ );
    stack_.push( text );
    strDisplay_.clear( );
  }
  if ( "=" == text ) {
    if ( stack_.isEmpty( ) ) {
      tablo_->display( "0" );
      return;
    }

    if ( !strDisplay_.isEmpty( ) ) {
      stack_.push( strDisplay_ );
      strDisplay_.clear( );
    }
    calculate( );
    tablo_->display( stack_.top( ) );
    stack_.clear( );
  }
}

void Calculator::calculate( ) {
  QString arg1 = stack_.top( );
  stack_.pop( );
  QString op = stack_.top( );
  stack_.pop( );
  QString arg2 = stack_.top( );
  stack_.pop( );
  double a = arg1.toDouble( );
  double b = arg2.toDouble( );
  if ( op == "+" ) {
    stack_.push( QString::number( a + b ) );
  }
  if ( op == "-" ) {
    stack_.push( QString::number( a - b ) );
  }
  if ( op == "*" ) {
    stack_.push( QString::number( a * b ) );
  }
  if ( op == "/" ) {
    stack_.push( QString::number( b / a ) );
  }
}
