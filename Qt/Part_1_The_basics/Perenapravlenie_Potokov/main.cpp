#include <QCoreApplication>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QtGlobal>

void messageToFile( QtMsgType type, const QMessageLogContext &context, const QString &msg );

int main(int argc, char *argv[])
{
  QCoreApplication a( argc, argv );

  //установка
  qInstallMessageHandler( messageToFile );
  //снять установку
  qInstallMessageHandler( nullptr );

  return a.exec( );
}

void messageToFile( QtMsgType type, const QMessageLogContext &context, const QString &msg ) {
  QFile file( "protocol.log" );
  if ( !file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append ) ) return;

  QString strDateTime = QDateTime::currentDateTime( ).toString( "dd.MM.yy-hh:mm" );

  QTextStream out( &file );
  switch ( type ) {
    case QtMsgType::QtCriticalMsg:
      out << strDateTime << "CRITICAL: " << msg << ", " << context.file << Qt::endl;
      break;
    case QtMsgType::QtDebugMsg:
      out << strDateTime << "DEBUG: " << msg << ", " << context.file << Qt::endl;
      break;
    case QtMsgType::QtFatalMsg:
      out << strDateTime << "FATAL: " << msg << ", " << context.file << Qt::endl;
      abort( );
    case QtMsgType::QtInfoMsg:
      out << strDateTime << "MSG: " << msg << ", " << context.file << Qt::endl;
      break;
    case QtMsgType::QtWarningMsg:
      out << strDateTime << "WARNING: " << msg << ", " << context.file << Qt::endl;
      break;
  }
}
