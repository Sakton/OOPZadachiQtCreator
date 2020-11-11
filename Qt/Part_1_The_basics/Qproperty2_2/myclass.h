#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>

class MyClass : public QObject {
  Q_OBJECT
  Q_PROPERTY( bool readOnly READ isReadOnly WRITE setReadOnly )
  Q_PROPERTY( QString name READ isName WRITE setName )

 public:
  MyClass( QObject *pobj = nullptr ) : QObject( pobj ), m_breadOnly { false }, m_name { "1" } {}
  bool isReadOnly( ) { return m_breadOnly; }
  void setReadOnly( bool bReadOnly ) { m_breadOnly = bReadOnly; }
  QString isName( ) const { return m_name; }
  void setName( QString name ) { m_name = name; }

 private:
  bool m_breadOnly;
  QString m_name;
};

#endif // MYCLASS_H
