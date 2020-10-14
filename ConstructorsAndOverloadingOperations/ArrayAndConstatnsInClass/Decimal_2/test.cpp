#include "pch.h"
#include "..\Decimal.h"


/*
Значения сравниваются с помощью операторов сравнения.

ASSERT_EQ(ожидаемое, реальное); — проверка, что реальное значение точно равно ожидаемой величине
ASSERT_NE(ожидаемое, реальное); — проверка, что реальное значение не равно ожидаемой величине
ASSERT_LT(ожидаемое, реальное); — проверка, что ожидаемое значение < реальная величина
ASSERT_LE(ожидаемое, реальное); — проверка, что ожидаемое значение <= реальная величина
ASSERT_GT(ожидаемое, реальное); — проверка, что ожидаемое значение > реальная величина
ASSERT_GE(ожидаемое, реальное); — проверка, что ожидаемое значение >= реальная величина
*/


TEST( DecimalClass, Ctor_0 ) {
	Decimal d;
	ASSERT_EQ( 1, d.Count() );
}

TEST( DecimalClass, Ctor_Str ) {
	Decimal d;
	ASSERT_EQ( "0", d.ToString() );
}

TEST( DecimalClass, Ctor_Str_MAX_LEN1 ) {
	ASSERT_ANY_THROW( Decimal d( "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" ););
}

TEST( DecimalClass, Ctor_Str_MAX_LEN2 ) {
	Decimal d( 99 );
	std::string testS;
	for( int i = 0; i < 99; ++i ) testS.push_back( '0' );
	ASSERT_EQ( testS, d.ToString() );
}

TEST( DecimalClass, Ctor_Str_MAX_LEN3 ) {
	ASSERT_ANY_THROW( Decimal d( 100 ) );
}

TEST( DecimalClass, Ctor_Str_MAX_LEN5 ) {
	std::string s;
	for( int i = 0; i < 99; ++i ) {
		s.push_back( '9' );
	}
	Decimal d( s );
	ASSERT_EQ( s, d.ToString() );
}

TEST( DecimalClass, Ctor_STD_String ) {
	Decimal d;
	ASSERT_STREQ( "0", d.ToString().c_str() );
}

TEST( DecimalClass, Ctor_STD_String1 ) {
	Decimal d( "123456" );
	ASSERT_STREQ( "123456", d.ToString().c_str() );
}

TEST( DecimalClass, CopyCtor ) {
	Decimal a( "-123456" );
	Decimal b = a;
	ASSERT_EQ( a, b );
}

TEST( DecimalClass, operatorLess ) {
	Decimal a( "-1" );
	Decimal b( "0" );
	ASSERT_LT( a, b );
}

TEST( DecimalClass, operatorLess1 ) {
	Decimal a{ "0" };
	Decimal b{ "1" };
	ASSERT_LT( a, b );
}

TEST( DecimalClass, operatorLess2 ) {
	Decimal a{ "-10" };
	Decimal b{ "-5" };
	ASSERT_LT( a, b );
}

TEST( DecimalClass, operatorLess3 ) {
	Decimal a{ "5" };
	Decimal b{ "10" };
	ASSERT_LT( a, b );
}

TEST( DecimalClass, operatorLess4 ) {
	Decimal a{ "104" };
	Decimal b{ "123" };
	ASSERT_LT( a, b );
}

TEST( DecimalClass, operatorPlusSelf ) {
	Decimal a( "1" );
	Decimal b( "1" );
	a += b;
	ASSERT_STREQ( "2", a.ToString().c_str() );
}

TEST( DecimalClass, operatorPlusSelf1 ) {
	Decimal a( "-1" );
	Decimal b( "-1" );
	a += b;
	ASSERT_STREQ( "-2", a.ToString().c_str() );
}

TEST( DecimalClass, operatorPlusSelf2 ) {
	Decimal a( "1" );
	Decimal b( "-3" );
	a += b;
	ASSERT_STREQ( "-2", a.ToString().c_str() );
}

TEST( DecimalClass, operatorPlusSelf3 ) {
	Decimal a( "1" );
	Decimal b( "-1" );
	a += b;
	ASSERT_STREQ( "0", a.ToString().c_str() );
}


TEST( DecimalClass, operatorPlusSelf4 ) {
	Decimal a( "1000" );
	Decimal b( "-1000" );
	a += b;
	ASSERT_STREQ( "0", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf ) {
	Decimal a( "1" );
	Decimal b( "-3" );
	a -= b;
	ASSERT_STREQ( "4", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf1 ) {
	Decimal a( "-1" );
	Decimal b( "-1" );
	a -= b;
	ASSERT_STREQ( "0", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf2 ) {
	Decimal a( "1" );
	Decimal b( "-10" );
	a -= b;
	ASSERT_STREQ( "11", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf3 ) {
	Decimal a( "1" );
	Decimal b( "10" );
	a -= b;
	ASSERT_STREQ( "-9", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf4 ) {
	Decimal a( "1" );
	Decimal b( "-10" );
	a -= b;
	ASSERT_STREQ( "11", a.ToString().c_str() );
}

TEST( DecimalClass, operatorMinusSelf5 ) {
	Decimal a( "-1000" );
	Decimal b( "-1000" );
	a -= b;
	ASSERT_STREQ( "0", a.ToString().c_str() );
}

TEST( DecimalClass, Mult10 ) {
	Decimal a( "1" );
	Decimal b = a.Mult10();
	ASSERT_STREQ( "10", b.ToString().c_str() );
}

TEST( DecimalClass, Mult10_2 ) {
	Decimal a( "-1" );
	Decimal b = a.Mult10();
	ASSERT_STREQ( "-10", b.ToString().c_str() );
}

TEST( DecimalClass, Mult10_3 ) {
	Decimal a( "0" );
	Decimal b = a.Mult10();
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, Mult10_4 ) {
	Decimal a( "999" );
	Decimal b = a.Mult10();
	ASSERT_STREQ( "9990", b.ToString().c_str() );
}

TEST( DecimalClass, MultXX_1 ) {
	Decimal a( "1" );
	Decimal b = a.MultPoryadok( 3 );
	ASSERT_STREQ( "1000", b.ToString().c_str() );
}

TEST( DecimalClass, MultXX_2 ) {
	Decimal a( "-1" );
	Decimal b = a.MultPoryadok( 3 );
	ASSERT_STREQ( "-1000", b.ToString().c_str() );
}

TEST( DecimalClass, MultXX_3 ) {
	Decimal a( "0" );
	Decimal b = a.MultPoryadok( 3 );
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultXX_4 ) {
	Decimal a( "999" );
	Decimal b = a.MultPoryadok( 3 );
	ASSERT_STREQ( "999000", b.ToString().c_str() );
}

TEST( DecimalClass, MultToNum ) {
	Decimal a( "999" );
	Decimal b = a.MultToNumber( 9 );
	ASSERT_STREQ( "8991", b.ToString().c_str() );
}

TEST( DecimalClass, MultToNum1 ) {
	Decimal a( "1" );
	Decimal b = a.MultToNumber( 1 );
	ASSERT_STREQ( "1", b.ToString().c_str() );
}

TEST( DecimalClass, MultToNum2 ) {
	Decimal a( "1" );
	Decimal b = a.MultToNumber( 0 );
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultToNum3 ) {
	Decimal a( "123456789" );
	Decimal b = a.MultToNumber( 0 );
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules ) {
	Decimal a( "999" );
	Decimal b( "99" );
	b *= a;
	ASSERT_STREQ( "98901", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules1 ) {
	Decimal a( "-999" );
	Decimal b( "99" );
	b *= a;
	ASSERT_STREQ( "-98901", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules2 ) {
	Decimal a( "999" );
	Decimal b( "-99" );
	b *= a;
	ASSERT_STREQ( "-98901", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules3 ) {
	Decimal a( "999" );
	Decimal b( "-99" );
	b *= a;
	ASSERT_STREQ( "-98901", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules4 ) {
	Decimal a( "0" );
	Decimal b( "-99" );
	b *= a;
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules5 ) {
	Decimal a( "-999" );
	Decimal b( "0" );
	b *= a;
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules6 ) {
	Decimal a( "999" );
	Decimal b( "-0" );
	b *= a;
	ASSERT_STREQ( "0", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules7 ) {
	Decimal a( "123456789" );
	Decimal b( "123456789" );
	b *= a;
	ASSERT_STREQ( "15241578750190521", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules8 ) {
	Decimal a( "-123456789" );
	Decimal b( "123456789" );
	b *= a;
	ASSERT_STREQ( "-15241578750190521", b.ToString().c_str() );
}

TEST( DecimalClass, MultModules9 ) {
	Decimal a( "123456789" );
	Decimal b( "-123456789" );
	b *= a;
	ASSERT_STREQ( "-15241578750190521", b.ToString().c_str() );
}

Decimal fact( int n ) {
	Decimal loc( "1" );
	for( int i = n; i > 0; --i ) {
		Decimal t( std::to_string( i ) );
		loc *= t;
	}
	return loc;
}

TEST( DecimalClass, Factorial ) {
	Decimal b = fact( 30 );
	ASSERT_STREQ( "265252859812191058636308480000000", b.ToString().c_str() );
}

TEST( DecimalClass, opLess ) {
	Decimal a( "123123" );
	Decimal b( "99999" );
	ASSERT_LT( b, a );
}

TEST( DecimalClass, opLess1 ) {
	Decimal a( "99999" );
	Decimal b( "99999" );
	ASSERT_LE( b, a );
}

TEST( DecimalClass, opLess2 ) {
	Decimal a( "99999" );
	Decimal b( "99999" );
	ASSERT_GE( a, b );
}

TEST( DecimalClass, opLess3 ) {
	Decimal a( "9999" );
	Decimal b( "99999" );
	ASSERT_GT( b, a );
}

TEST( DecimalClass, opLess4 ) {
	Decimal a( "899" );
	Decimal b( "998" );
	ASSERT_GT( b, a );
}
TEST( DecimalClass, opLess5 ) {
	Decimal a( "104" );
	Decimal b( "123" );
	ASSERT_GT( b, a );
}

TEST( DecimalClass, Divide ) {
	Decimal a( "1000" );
	Decimal b( "10" );
	Decimal c = a / b;
	ASSERT_STREQ( "100", c.ToString().c_str() );
}

TEST( DecimalClass, Divide1 ) {
	Decimal a = fact( 30 );
	Decimal b( "10000000" );
	Decimal c = a / b;
	ASSERT_STREQ( "26525285981219105863630848", c.ToString().c_str() );
}

TEST( DecimalClass, Divide2 ) {
	Decimal a( "-1000" );
	Decimal b( "10" );
	Decimal c = a / b;
	ASSERT_STREQ( "-100", c.ToString().c_str() );
}

TEST( DecimalClass, Divide3 ) {
	Decimal a( "1000" );
	Decimal b( "-10" );
	Decimal c = a / b;
	ASSERT_STREQ( "-100", c.ToString().c_str() );
}

TEST( DecimalClass, Divide4 ) {
	Decimal a( "-1000" );
	Decimal b( "-10" );
	Decimal c = a / b;
	ASSERT_STREQ( "100", c.ToString().c_str() );
}

TEST( DecimalClass, Divide5 ) {
	Decimal a( "-1000" );
	int b = -10;
	Decimal c = a / b;
	ASSERT_STREQ( "100", c.ToString().c_str() );
}

TEST( DecimalClass, Divide6 ) {
	int a = -1000;
	Decimal b( "-10" );
	Decimal c = a / b;
	ASSERT_STREQ( "100", c.ToString().c_str() );
}