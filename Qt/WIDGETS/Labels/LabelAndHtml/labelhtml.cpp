#include "labelhtml.h"

#include <QLabel>

const QString PATH = "E:\\CPP\\MyProects\\OOPZadachiCreatorQt\\OOPZadachiQtCreator\\Qt\\15487.png";

LabelHtml::LabelHtml( QWidget *parent ) : QWidget( parent ) {
  QLabel *label = new QLabel(
      "<Нl><<CENTER>QLabel - HTML Demo</CENTER></Нl>"
      "<H2><CENTER>Image</CENTER><H2>"
      "<CENTER><IMG BORDER=\"0\" SRC=\"E:\\CPP\\MyProects\\OOPZadachiCreatorQt\\OOPZadachiQtCreator\\Qt\\15487.png\"></CENTER>"
      "<H2><CENТER>List</CENТER><H2>"
      "<OL><LI>One</LI>"
      "<LI>Two</LI>"
      "<LI>Three</LI>"
      "</OL>"
      "<H2><CENTER>Font Style</CENTER><H2>"
      "<CENTER><FONT COLOR=RED>"
      "<B>Bold</B>, <I>Italic</I>, <U>Underline</U>"
      "</FONT></CENTER>"
      "<H2><CENTER>TaЬle</CENTER></H2>"
      "<CENTER> <ТАВLЕ>"
      "<TR BGCOLOR=#ffOOff>"
      "<TD>l,l</TD><TD>l,2</TD><TD>l,3</TD><TD>l,4</TD>"
      "</TR>"
      "<TR BGCOLOR=YELLOW>"
      "<TD>2,1</TD><TD>2,2</TD><TD>2,3</TD><TD>2,4</TD>"
      "</TR>"
      "<TR BGCOLOR=#OOfOOO>"
      "<TD>3,1</TD><TD>3,2</TD><TD>3,3</TD><TD>3,4</TD>"
      "</TR>"
      "</ТАВLЕ> </CENTER>",
      this );
  label->setTextFormat( Qt::TextFormat::RichText );
  label->show( );
}

LabelHtml::~LabelHtml()
{
}

