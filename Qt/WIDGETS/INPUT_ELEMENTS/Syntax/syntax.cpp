#include "syntax.h"

#include <QDebug>
#include <algorithm>

Syntax::Syntax( QTextDocument *parent ) : QSyntaxHighlighter( parent ) {
  keyWords_ << "if"
            << "bool"
            << "int"
            << "void"
            << "double"
            << "float"
            << "char"
            << "const"
            << "virtual"
            << "for"
            << "emit"
            << "connect";
}

Syntax::~Syntax()
{
}

void Syntax::highlightBlock( const QString &str ) {
  int nState = previousBlockState( );
  int nStart = 0;
  for ( int i = 0; i < str.size( ); ++i ) {
    if ( nState == InsideCStyleComments ) {  //если состояние: - внутри коммента
      if ( str.mid( i, 2 ) == "*/" ) {       //обнаружить конец коммита
        nState = NormalState;                //переход в нормальное состояние
        setFormat( nStart, i - nStart + 2, Qt::darkGray );
        ++i;                                   //компенсация 1 символа
      } else if ( nState == InsideCString ) {  //если состояние: - внутри строки
        if ( str.mid( i, 1 ) == "\"" || str.mid( i, 1 ) == "\'" ) {
          if ( str.mid( i - 1, 2 ) != "\\\"" || str.mid( i - 1, 2 ) != "\\\'" ) {
            // FIXME потом, все просто
          }
        }
      }
    }
  }
}

// void Syntax::highlightBlock( const QString &text ) {}

// void Syntax::highlightBlock( const QString &text ) {
//  //  for ( int i = 0; i < text.size( ); ++i ) {
//  //    if ( text.at( i ).isNumber( ) ) {
//  //      setFormat( i, 1, Qt::red );
//  //    }
//  //  }

//  int cur = 0;
//  for ( auto &el : text ) {
//    if ( el.isNumber( ) ) setFormat( cur, 1, Qt::red );
//    ++cur;
//  }
//}
