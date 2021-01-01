#include "saves.h"

#include <QTextDocumentWriter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtPrintSupport/QPrinter>

Saves::Saves( QWidget *parent ) : QWidget( parent ) {
  resize( 800, 400 );

  QTextEdit *textEdit = new QTextEdit( "This is a <b>TEST</b>" );

  QVBoxLayout *bl = new QVBoxLayout;
  bl->addWidget( textEdit );

  setLayout( bl );

  QTextDocumentWriter writer;
  writer.setFormat( "odf" );
  writer.setFileName(
      "E:/CPP/MyProects/OOPZadachiCreatorQt/OOPZadachiQtCreator/Qt/WIDGETS/INPUT_ELEMENTS/SaveFileTexts/Files/odffile.odf" );
  writer.write( textEdit->document( ) );

  QPrinter printer;
  printer.setResolution( QPrinter::PrinterMode::HighResolution );
  printer.setOutputFileName(
      "E:/CPP/MyProects/OOPZadachiCreatorQt/OOPZadachiQtCreator/Qt/WIDGETS/INPUT_ELEMENTS/SaveFileTexts/Files/pdfpdf.pdf" );
  printer.setOutputFormat( QPrinter::OutputFormat::PdfFormat );
  textEdit->document( )->print( &printer );
}

Saves::~Saves()
{
}

