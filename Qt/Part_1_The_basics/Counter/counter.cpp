#include "counter.h"

#include <QDebug>

Counter::Counter( QObject* parent, int32_t v ) : QObject( parent ), m_value { v } {}

Counter::~Counter()
{
}

void Counter::slotInc( ) {
  qDebug( ) << "Counter::slotInc( )";
  emit counterChanged( ++m_value, 100 );
  if ( m_value == 5 ) emit goodbye( );
}
