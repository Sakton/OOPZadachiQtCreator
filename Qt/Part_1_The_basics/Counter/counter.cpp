#include "counter.h"

Counter::Counter( QObject* parent, int32_t v ) : QObject( parent ), m_value { v } {}

Counter::~Counter()
{
}

void Counter::slotInc( ) {
  emit counterChanged( m_value++ );
  if ( m_value == 5 ) emit goodbye( );
}
