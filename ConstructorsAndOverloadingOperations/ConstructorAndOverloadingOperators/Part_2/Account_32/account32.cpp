#include "account32.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

Account32::Account32( const std::string& name, const std::string& acc,
                      double proc, double summ )
    : name_ { }, accountNum_ { }, procent_ { 0 }, summa_ { 0 } {
  //�������� ���� ������
  name_ = name;
  accountNum_ = acc;
  procent_ = proc;
  summa_ = summ;
}

Account32::operator std::string( ) const {
  std::stringstream ss;
  ss << "   Name: " << name_ << std::endl
     << "Account: " << accountNum_ << std::endl
     << "Procent: " << procent_ << std::endl
     << std::fixed << std::setprecision( 2 ) << "  Summa: " << summa_
     << std::endl;
  return ss.str( );
}

void Display( const Account32& ac ) {
  std::cout << static_cast< std::string >( ac ) << std::endl;
}

std::string name( const Account32& ac ) { return ac.name_; }

void setName( Account32& ac, const std::string& name ) { ac.name_ = name; }

void AddSumm( Account32& ac, double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  ac.summa_ += sm;
}

void SubSumm( Account32& ac, double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  ac.summa_ -= sm;
}

void AddProcent( Account32& ac ) { ac.summa_ += ac.summa_ * ac.procent_ / 100; }

double ToDollar( const Account32& ac, double cours ) {
  return ac.summa_ / cours;
}

double ToEuro( const Account32& ac, double cours ) { return ac.summa_ / cours; }

std::string ToChislitelnoe( const Account32& ac ) {
  int64_t rur = ac.summa_;
  int16_t cop = ( ac.summa_ - rur ) * 100;

  std::string res = ParseThousand( ac, rur );
  res += ParseSotni( ac, rur );

  if ( cop ) {
    res += " ������, ";
    res += ParseSotni( ac, cop );
    res += " ������";
  } else {
    res += " ������";
  }

  return res;
}

std::string Sotni( int chislo ) {
  switch ( chislo ) {
    case 100:
      return "���";
    case 200:
      return "������";
    case 300:
      return "������";
    case 400:
      return "���������";
    case 500:
      return "�������";
    case 600:
      return "��������";
    case 700:
      return "�������";
    case 800:
      return "���������";
    case 900:
      return "���������";
    default:
      return "";
  }
}

std::string Desyatki( int chislo ) {
  switch ( chislo ) {
    case 10:
      return "������";
    case 11:
      return "�����������";
    case 12:
      return "����������";
    case 13:
      return "����������";
    case 14:
      return "������������";
    case 15:
      return "����������";
    case 16:
      return "�����������";
    case 17:
      return "�����������";
    case 18:
      return "�������������";
    case 19:
      return "������������";
    case 20:
      return "��������";
    case 30:
      return "��������";
    case 40:
      return "�����";
    case 50:
      return "���������";
    case 60:
      return "����������";
    case 70:
      return "���������";
    case 80:
      return "����������";
    case 90:
      return "���������";
    default:
      return "";
  }
}

std::string Edinitsy( int chislo ) {
  switch ( chislo ) {
    case 1:
      return "����";
    case 2:
      return "���";
    case 3:
      return "���";
    case 4:
      return "������";
    case 5:
      return "����";
    case 6:
      return "�����";
    case 7:
      return "����";
    case 8:
      return "������";
    case 9:
      return "������";
    default:
      return "";
  }
}

std::string ParseSotni( const Account32&, int chislo ) {
  chislo %= 1000;
  std::stack< std::string > st;
  if ( 10 <= ( chislo % 100 ) && ( chislo % 100 ) <= 20 ) {
    st.push( Desyatki( chislo % 100 ) );
  } else if ( ( chislo % 100 ) <= 10 ) {
    st.push( Edinitsy( chislo % 10 ) );
  } else {
    st.push( Edinitsy( chislo % 10 ) );
    st.push( Desyatki( chislo % 100 - chislo % 10 ) );
  }
  st.push( Sotni( ( chislo / 100 ) * 100 ) );
  std::string res;
  while ( !st.empty( ) ) {
    res += st.top( );
    res += " ";
    st.pop( );
  }
  return res;
}

std::string ParseThousand( const Account32& ac, int chislo ) {
  if ( chislo < 1000 ) return { };
  std::string res = ParseSotni( ac, chislo / 1000 );
  if ( ( chislo / 1000 ) % 10 == 1 ) {
    auto it = res.find( "����" );
    res.replace( it, it + 3, "����" );
  }
  if ( ( chislo / 1000 ) % 10 == 2 ) {
    auto it = res.find( "���" );
    res.replace( it, it + 3, "��� " );
  }
  if ( 1000 <= chislo && chislo < 1000000 ) {
    switch ( ( chislo / 1000 ) % 10 ) {
      case 1:
        res += "������ ";
        break;
      case 2:
      case 3:
      case 4:
        res += "������ ";
        break;
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0:
        res += "����� ";
        break;
    }
  }
  return res;
}
