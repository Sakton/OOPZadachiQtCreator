#include "pch.h"
#include "../Hex.h"

TEST( HexTest, HexCtor ) {
	Hex a;
	ASSERT_STREQ( "0", a.ToString( ).c_str( ) );
}

TEST( HexTest, HexCtor2 ) {
	Hex a( "ABCDEF123456" );
	ASSERT_STREQ( "ABCDEF123456", a.ToString( ).c_str( ) );
}

TEST( HexTest, HexCtor3 ) {
	Hex a( "ABCDEF123456" );
	Hex b = a;
	ASSERT_STREQ( "ABCDEF123456", b.ToString( ).c_str( ) );
}

TEST( HexTest, OkStr ) {
	Hex a;
	ASSERT_TRUE( a.IsOkString( "ABCDEF123456789" ) );
}

TEST( HexTest, OkStr1 ) {
	Hex a;
	ASSERT_FALSE( a.IsOkString( "ABCDEF123456789G" ) );
}

TEST( HexTest, CopyCtor ) {
	Hex a( "ABCDEF123456789" );
	Hex b = a;
	a = Hex( "0" );
	ASSERT_STREQ( "ABCDEF123456789", b.ToString( ).c_str( ) );
}

TEST( HexTest, Op ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "0" );
	b = a;
	ASSERT_STREQ( "ABCDEF123456789", b.ToString( ).c_str( ) );
}

TEST( HexTest, Less ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "ABCDEF12345678" );
	ASSERT_LT( b, a );
}

TEST( HexTest, Less1 ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "9BCDEF123456789" );
	ASSERT_LT( b, a );
}

TEST( HexTest, Better ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "9BCDEF123456789" );
	ASSERT_GT( a, b );
}

TEST( HexTest, Better1 ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "ABCDEF12345678" );
	ASSERT_GT( a, b );
}

TEST( HexTest, Equalitet ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "ABCDEF123456789" );
	ASSERT_EQ( a, b );
}

TEST( HexTest, NoEqualitet ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "9BCDEF123456789" );
	ASSERT_NE( a, b );
}

TEST( HexTest, LessOrEqual ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "9BCDEF123456789" );
	ASSERT_LE( b, a );
}

TEST( HexTest, LessOrEqual1 ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "ABCDEF123456789" );
	ASSERT_GE( b, a );
}

TEST( HexTest, BetterOrEqual ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "9BCDEF123456789" );
	ASSERT_GE( a, b );
}

TEST( HexTest, BetterOrEqual1 ) {
	Hex a( "ABCDEF123456789" );
	Hex b( "ABCDEF123456789" );
	ASSERT_GE( a, b );
}

TEST( HexTest, Add ) {
	Hex a( "1" );
	Hex b( "1" );
	b += a;
	ASSERT_STREQ( "2", b.ToString( ).c_str( ) );
}

TEST( HexTest, Add1 ) {
	Hex a( "F" );
	Hex b( "F" );
	b += a;
	ASSERT_STREQ( "1E", b.ToString( ).c_str( ) );
}

TEST( HexTest, Add2 ) {
	Hex a( "ADD" );
	Hex b( "ADD" );
	b += a;
	ASSERT_STREQ( "15BA", b.ToString( ).c_str( ) );
}

TEST( HexTest, Add3 ) {
	Hex a( "ADDDDDDDA" );
	Hex b( "ADDA" );
	b += a;
	ASSERT_STREQ( "ADDDE8BB4", b.ToString( ).c_str( ) );
}

TEST( HexTest, Add4 ) {
	Hex a( "ADDA" );
	Hex b( "ADDDDDDDA" );
	b += a;
	ASSERT_STREQ( "ADDDE8BB4", b.ToString( ).c_str( ) );
}

TEST( HexTest, Sub ) {
	Hex a( "ABCDEF" );
	Hex b( "1" );
	Hex c = b - a;
	ASSERT_STREQ( "F543212", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub1 ) {
	Hex a( "ABCDEF" );
	Hex b( "1" );
	Hex c = a - b;
	ASSERT_STREQ( "ABCDEE", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub2 ) {
	Hex a( "ABCDEF" );
	Hex b( "ABCDEF" );
	Hex c = a - b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub3 ) {
	Hex a( "1" );
	Hex b( "1" );
	Hex c = a - b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub4 ) {
	Hex a( "0" );
	Hex b( "0" );
	Hex c = a - b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub5 ) {
	Hex a( "2" );
	Hex b( "1" );
	Hex c = a - b;
	ASSERT_STREQ( "1", c.ToString( ).c_str( ) );
}

TEST( HexTest, Sub6 ) {
	Hex a( "F" );
	Hex b( "E" );
	Hex c = a - b;
	ASSERT_STREQ( "1", c.ToString( ).c_str( ) );
}

TEST( HexTest, Throw ) {
	//Hex( "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" );
	ASSERT_THROW( Hex( "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" ),
				  std::runtime_error*); //102 элемента
}

TEST( HexTest, Add5 ) {
	Hex a( "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" );
	Hex b( "1" );
	Hex c = a + b;
	ASSERT_STREQ (
	"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
		c.ToString().c_str()
	);
	ASSERT_EQ( 100, c.Count() );
}

TEST( HexTest, Mult ) {
	Hex a( "CBA" );
	Hex b( "AAA" );
	Hex c = a * b;
	ASSERT_STREQ( "87B784", c.ToString().c_str() );
}

TEST( HexTest, Mult1 ) {
	Hex a( "0" );
	Hex b( "AAA" );
	Hex c = a * b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Mult2 ) {
	Hex a( "CBA" );
	Hex b( "0" );
	Hex c = a * b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Mult3 ) {
	Hex a( "CBA" );
	Hex b( "1" );
	Hex c = a * b;
	ASSERT_STREQ( "CBA", c.ToString( ).c_str( ) );
}

TEST( HexTest, Mult4 ) {
	Hex a( "1" );
	Hex b( "CBA" );
	Hex c = a * b;
	ASSERT_STREQ( "CBA", c.ToString( ).c_str( ) );
}

TEST( HexTest, Div ) {
	Hex a( "87384" );
	Hex b( "AAA" );
	Hex c = a / b;
	ASSERT_STREQ( "CA", c.ToString().c_str() );
}

TEST( HexTest, Div1 ) {
	Hex a( "AAA" );
	Hex b( "87384" );
	Hex c = a / b;
	ASSERT_STREQ( "0", c.ToString( ).c_str( ) );
}

TEST( HexTest, Div2 ) {
	Hex a( "1" );
	Hex b( "0" );
	Hex c;
	ASSERT_THROW( c = a / b, std::runtime_error * );
}