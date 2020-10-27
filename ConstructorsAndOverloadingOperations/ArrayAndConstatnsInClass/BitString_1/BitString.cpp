//#include "BitString.h"
//#include <cstring>

//// const size_t BitString::MAX = 100;
//// TODO РЕШЕНО НЕ ВЕРНО В ТУПУЮ

// BitString::BitString( size_t n ) : bitStr{ nullptr }, count{ 0 } {
//	std::cout << "ctor1" << std::endl;
//	n = ( n < MAX - 1 ) ? n : MAX;
//	count = n;
//	bitStr = new unsigned char [ n + 1 ];
//	for ( size_t i = 0; i < n; ++i )
//		bitStr [ i ] = '0';
//	bitStr [ n ] = '\0';
//}

// BitString::BitString( const std::string & str ) : bitStr{ nullptr }, count{ 0
// } { 	std::cout << "ctor2" << std::endl;
//	//удаляем первые нули
//	int lenStr = 0;
//	if ( IsOkString( str ) ) {
//		lenStr = str.size( );
//		size_t n = 0;
//		n = ( n < MAX ) ? n : MAX;
//		count = n;
//		bitStr = new unsigned char [ n + 1 ];
//		if ( IsOkString( str ) ) {
//			for ( int i = n - 1; i >= 0; --i ) {
//				bitStr [ i ] = str [ i ];
//			}
//		}
//		else {
//			for ( int i = n - 1; i >= 0; --i ) {
//				bitStr [ i ] = '0';
//			}
//		}
//		bitStr [ n ] = '\0';
//        }
//}

// BitString::~BitString( ) {
//	delete[ ] bitStr;
//}

// BitString::BitString( const BitString & other ) {
//	std::cout << "copy ctor" << std::endl;
//	bitStr = new unsigned char [ other.Count( ) + 1 ];
//	for ( size_t i = 0; i < other.Count( ); i++ ) {
//		bitStr [ i ] = other.bitStr [ i ];
//	}
//	bitStr [ other.Count( ) ] = '\0';
//	count = other.count;
//}

// BitString & BitString::operator=( const BitString & other ) {
//	if ( this == &other ) return *this;
//	unsigned char * t = new unsigned char [ other.count + 1 ];
//	std::copy( other.bitStr, other.bitStr + other.count, t );
//	delete[ ] bitStr;
//	bitStr = t;
//	count = other.count;
//}

// size_t BitString::Size( ) {
//	return MAX;
//}

// const BitString & BitString::operator<<=( int n ) {
//	if ( n < count ) {
//		int i = 0; //отвечает за отсчет сначала
//		int j = n; //отвечает за отсчет с позиции n на сколько смещаем
//(-1 отсчет с 0)
//		//перемещаем вперед с позиции отступа
//		for ( ; j < count; ++i, ++j ) {
//			bitStr [ i ] = bitStr [ j ];
//		}
//		//добиваем в конец нули
//		for ( ; i < count; ++i ) {
//			bitStr [ i ] = '0';
//		}
//	}
//	else if ( n < MAX && n > count ) {
//		//если сдвигаем на большее число чем есть
//		//новое хранилище
//		unsigned char * t = new unsigned char [ n + 1 ];
//		int i = 0;
//		for ( ; i < count; ++i ) {
//			t [ i ] = bitStr [ i ];
//		}
//		for ( ; i < n; ++i ) {
//			t [ i ] = '0';
//		}
//		t [ n ] = '\0';
//		delete[ ] bitStr;
//		bitStr = t;
//		count = n;
//	}
//	return *this;
//}

// const BitString & BitString::operator>>=( int n ) {
//	if ( n < count ) {
//		int i = count - 1; //позиция конца строки
//		int j = count - 1 - n; //позиция элемента сдвига
//		for ( ; j >= 0; --j, --i ) {
//			bitStr [ i ] = bitStr [ j ];
//		}
//		for ( ; i >= 0; --i ) {
//			bitStr [ i ] = '0';
//		}
//	}
//	return *this;
//}

// const BitString & BitString::operator~( ) {
//	for ( int i = 0; i < count; ++i )
//		bitStr [ i ] = ( bitStr [ i ] == '0' ) ? '1' : '0';
//	return *this;
//}

// const BitString & BitString::operator |= ( const BitString & other ) {
//	//так как нет указаний как логически складывать с начала или конца
//строк, то делаю как с числами представленными битовой строкой 	for ( int
//i =
// count - 1, j = other.count - 1; i >= 0 && j >= 0; --i, --j ) {
// bitStr [ i ] = ( bitStr [ i ] == '1' || other.bitStr [ j ] == '1' ) ? '1' :
//'0';
//	}
//	return *this;
//}

// const BitString & BitString::operator &= ( const BitString & other ) {
//	for ( int i = count - 1, j = other.count - 1; i >= 0 && j >= 0; --i, --j
//) { 		bitStr [ i ] = ( bitStr [ i ] == '1' && other.bitStr [ j ] ==
//'1' ) ? '1' : '0';
//	}
//	return *this;
//}

// const BitString & BitString::operator ^= ( const BitString & other ) {
//	for ( int i = count - 1, j = other.count - 1; i >= 0 && j >= 0; --i, --j
//) { 		bool pr = ( bitStr [ i ] == '0' && other.bitStr [ j ] == '1' )
//|| ( bitStr
//[ i ] == '1' && other.bitStr [ j ] == '0' ); 		bitStr [ i ] = ( (
//bitStr [ i ]
//== '0' && other.bitStr [ j ] == '1' ) || ( bitStr [ i ] == '1' && other.bitStr
//[ j ] == '0' ) ) ? '1' : '0';
//	}
//	return *this;
//}

// unsigned char & BitString::operator[]( size_t ind ) {
//	//if( ind > count ) {
//	//	// выброс исключения (или на откуп программисту)
//	//}
//	return bitStr [ ind ];
//}

// const unsigned char & BitString::operator[]( size_t ind ) const {
//	return bitStr [ ind ];
//}

// std::string BitString::ToString( )
//{
//	return std::string( reinterpret_cast< const char * >( bitStr ) );
//}

////std::string BitString::DecimalPresentation( )
////{
////	std::string s;
////	int k = 1;
////	summ = 0;
////	for ( int i = 0; i < count; ++i ) {
////		int x = ( bitStr [ i ] - '0' ) * k;
////		k *= 2;
////
////	}
////	return s;
////}

// bool BitString::IsOkString( const std::string & str ) {
//	for ( auto s : str ) {
//		if ( ( s != '0' ) && ( s != '1' ) ) {
//			return false;
//		}
//	}
//	return true;
//}

// size_t BitString::Count( ) const {
//	return count;
//}

// BitString operator>>( const BitString & other, int n ) {
//	BitString loc = other;
//	loc >>= n;
//	return loc;
//}

// BitString operator<<( const BitString & other, int n ) {
//	BitString loc = other;
//	loc <<= n;
//	return loc;
//}

// BitString operator|( const BitString & first, const BitString & second ) {
//	BitString loc = first;
//	loc |= second;
//	return loc;
//}

// BitString operator&( const BitString & first, const BitString & second ) {
//	BitString loc = first;
//	loc &= second;
//	return loc;
//}

// BitString operator^( const BitString & first, const BitString & second ) {
//	BitString loc = first;
//	loc ^= second;
//	return loc;
//}

// std::ostream & operator<<( std::ostream & out, const BitString & other ) {
//	if ( other.Count( ) > 0 ) {
//		out << other.bitStr << " count:" << other.count;
//	}
//	else {
//		out << "NULL BTS";
//	}
//	return out;
//}

// std::istream & operator>>( std::istream & in, BitString & other ) {
//	char ch = ' ';
//	int k = 0;
//	in.get( ch );
//	while ( ( ch == '0' || ch == '1' ) && k < BitString::MAX ) {
//		other.bitStr [ k++ ] = ch;
//		in.get( ch );
//	}
//	if ( !k ) in.setstate( in.failbit );
//	other.count = k;
//	other.bitStr [ k ] = '\0';
//	return in;
//}
