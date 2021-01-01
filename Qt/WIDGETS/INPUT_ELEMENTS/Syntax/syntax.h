#ifndef SYNTAX_H
#define SYNTAX_H

#include <QSyntaxHighlighter>

class QTextDocument;

class Syntax : public QSyntaxHighlighter {
  Q_OBJECT

 public:
  Syntax( QTextDocument *parent = nullptr );
  ~Syntax( );

 protected:
  enum { NormalState = -1, InsideCStyleComments, InsideCString };
  void highlightBlock( const QString &str ) override;
  QString getKeyWord( int i, const QString &s ) const;

 private:
  // QTextDocument *docum_;
  QStringList keyWords_;
};
#endif // SYNTAX_H
