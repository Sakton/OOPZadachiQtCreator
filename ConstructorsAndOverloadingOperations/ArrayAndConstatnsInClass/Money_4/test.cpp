//#include "pch.h"
//#include "../Money4.h"

//TEST( Money4, Ctor ) {
//	Money4 a( "-123456789123456789123456789123456789123456789123456789,55" );
//	ASSERT_STREQ( "-123456789123456789123456789123456789123456789123456789,55", a.ToString( ).c_str( ) );
//}

//TEST( Money4, Ctor1 ) {
//	Money4 a;
//	ASSERT_STREQ( "0,00", a.ToString( ).c_str( ) );
//}

//TEST( Money4, Ctor2 ) {
//	Money4 a("0");
//	ASSERT_STREQ( "0,00", a.ToString( ).c_str( ) );
//}

//TEST( Money4, Ctor3 ) {
//	Money4 a( "0.0" );
//	ASSERT_STREQ( "0,00", a.ToString( ).c_str( ) );
//}

//TEST( Money4, Ctor4 ) {
//	Money4 a( "-" );
//	ASSERT_STREQ( "0,00", a.ToString( ).c_str( ) );
//}

//TEST( Money4, Less1 ) {
//	Money4 a( "-0.10" );
//	Money4 b;
//	ASSERT_TRUE( a < b );
//}

//TEST( Money4, Less2 ) {
//	Money4 a( "0.10" );
//	Money4 b;
//	ASSERT_TRUE( b < a );
//}

//TEST( Money4, Less3 ) {
//	Money4 a( "0.10" );
//	Money4 b;
//	ASSERT_TRUE( b < a );
//}

//TEST( Money4, Less4 ) {
//	Money4 a( "-1.00" );
//	Money4 b( "1.00" );
//	ASSERT_TRUE( a < b );
//}

//TEST( Money4, Less5 ) {
//	Money4 a( "1.00" );
//	Money4 b( "11.00" );
//	ASSERT_TRUE( a < b );
//}

//TEST( Money4, Less6 ) {
//	Money4 a( "09.00" );
//	Money4 b( "11.00" );
//	ASSERT_TRUE( a < b );
//}

//TEST( Money4, Addictional ) {
//	Money4 a( "1.0" );
//	Money4 b( "-1.0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "0,00", c.ToString().c_str() );
//}

//TEST( Money4, Addictional1 ) {
//	Money4 a( "1.0" );
//	Money4 b( "1.0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "2,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Addictional2 ) {
//	Money4 a( "-1.0" );
//	Money4 b( "1.0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Addictional3 ) {
//	Money4 a( "-2.0" );
//	Money4 b( "1.0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "-1,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Addictional4 ) {
//	Money4 a( "1.0" );
//	Money4 b( "-2.0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "-1,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Addictional5 ) {
//	Money4 a( "0" );
//	Money4 b( "0" );
//	Money4 c = a + b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Substraction ) {
//	Money4 a( "1.0" );
//	Money4 b( "1.0" );
//	Money4 c = a - b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Substraction1 ) {
//	Money4 a( "-1.0" );
//	Money4 b( "1.0" );
//	Money4 c = a - b;
//	ASSERT_STREQ( "-2,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Substraction2 ) {
//	Money4 a( "-1.0" );
//	Money4 b( "-1.0" );
//	Money4 c = a - b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Substraction3 ) {
//	Money4 a( "0" );
//	Money4 b( "0" );
//	Money4 c = a - b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult ) {
//	Money4 a( "0" );
//	Money4 b( "0" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult1 ) {
//	Money4 a( "0.01" );
//	Money4 b( "0.01" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult2 ) {
//	Money4 a( "1" );
//	Money4 b( "0.01" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,01", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult3 ) {
//	Money4 a( "1" );
//	Money4 b( "-0.01" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "-0,01", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult4 ) {
//	Money4 a( "-0.01" );
//	Money4 b( "1" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "-0,01", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult5 ) {
//	Money4 a( "-0.01" );
//	Money4 b( "-1" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,01", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult6 ) {
//	Money4 a( "-1" );
//	Money4 b( "0" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult7 ) {
//	Money4 a( "0.99" );
//	Money4 b( "0.01" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "0,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult8 ) {
//	Money4 a( "99" );
//	Money4 b( "10" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "990,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult9 ) {
//	Money4 a( "1000000" );
//	Money4 b( "1000000" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "1000000000000,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult10 ) {
//	Money4 a( "9999" );
//	Money4 b( "999" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "9989001,00", c.ToString( ).c_str( ) );
//}

//TEST( Money4, Mult11 ) {
//	Money4 a( "9.99" );
//	Money4 b( "9.9" );
//	Money4 c = a * b;
//	ASSERT_STREQ( "98,90", c.ToString( ).c_str( ) );
//}
