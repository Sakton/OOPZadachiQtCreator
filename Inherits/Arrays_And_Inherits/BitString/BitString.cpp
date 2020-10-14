#include "BitString.h"
#include <cstring>

BitString::BitString( int n )
    : Array< Type >( n )
{
    for ( int i = 0; i < n; ++i ) {
        ( *this )[ i ] = '0';
    }
}

BitString::BitString( const std::string & str )
    : Array< Type >( str.size( ) )
{
    //удаляем первые нули
    if ( IsOkString( str ) ) {
        if ( IsOkString( str ) ) {
            for ( int i = str.size( ) - 1; i >= 0; --i ) {
                ( *this )[ i ] = str[ i ];
            }
        } else {
            for ( int i = str.size( ) - 1; i >= 0; --i ) {
                ( *this )[ i ] = '0';
            }
        }
    }
}

BitString::BitString( const BitString & other )
{
    Array::operator=( other );
}

BitString & BitString::operator=( const BitString & other )
{
    if ( this != &other ) {
        Array::operator=( other );
    }
    return *this;
}

size_t BitString::Size( )
{
    return Array::MAX_ELEM;
}

BitString & BitString::operator<<=( int n )
{
    if ( n < Sz( ) ) {
        int i = 0; //отвечает за отсчет сначала
        int j = n; //отвечает за отсчет с позиции n на сколько смещаем (-1 отсчет с 0)
        //перемещаем вперед с позиции отступа
        for ( ; j < Sz( ); ++i, ++j ) {
            this->operator[]( i ) = this->operator[]( j ); //так работает !!!????
        }
        //добиваем в конец нули
        for ( ; i < Sz( ); ++i ) {
            ( *this )[ i ] = '0';
        }
    } else if ( n < MAX_ELEM && n > Sz( ) ) {
        //если сдвигаем на большее число чем есть
        //новое хранилище
        //unsigned char * t = new unsigned char[ n + 1 ];
        BitString t( n + 1 );
        int i = 0;
        for ( ; i < Sz( ); ++i ) {
            t[ i ] = ( *this )[ i ];
        }
        for ( ; i < n; ++i ) {
            t[ i ] = '0';
        }
    }
    return *this;
}

BitString & BitString::operator>>=( int n )
{
    if ( n < Sz( ) ) {
        int i = Sz( ) - 1; //позиция конца строки
        int j = Sz( ) - 1 - n; //позиция элемента сдвига
        for ( ; j >= 0; --j, --i ) {
            ( *this )[ i ] = ( *this )[ j ];
        }
        for ( ; i >= 0; --i ) {
            ( *this )[ i ] = '0';
        }
    }
    return *this;
}

BitString & BitString::operator~( )
{
    for ( int i = 0; i < Sz( ); ++i )
        ( *this )[ i ] = ( ( *this )[ i ] == '0' ) ? '1' : '0';
    return *this;
}

BitString & BitString::operator|=( const BitString & other )
{
    //так как нет указаний как логически складывать с начала или конца строк, то делаю как с числами представленными битовой строкой
    for ( int i = Sz( ) - 1, j = other.Sz( ) - 1; i >= 0 && j >= 0; --i, --j ) {
        ( *this )[ i ] = ( ( *this )[ i ] == '1' || other[ j ] == '1' ) ? '1' : '0';
    }
    return *this;
}

BitString & BitString::operator&=( const BitString & other )
{
    for ( int i = Sz( ) - 1, j = other.Sz( ) - 1; i >= 0 && j >= 0; --i, --j ) {
        ( *this )[ i ] = ( ( *this )[ i ] == '1' && other[ j ] == '1' ) ? '1' : '0';
    }
    return *this;
}

BitString & BitString::operator^=( const BitString & other )
{
    for ( int i = Sz( ) - 1, j = other.Sz( ) - 1; i >= 0 && j >= 0; --i, --j ) {
        ( *this )[ i ] = ( ( *this )[ i ] != other[ j ] ) ? '1' : '0';
    }
    return *this;
}

void BitString::Display( )
{
    std::cout << static_cast< std::string >( *this ) << std::endl;
}

BitString::operator std::string( ) const
{
    std::string res;
    for ( int i = 0; i < Sz( ); ++i ) {
        res.push_back( ( *this )[ i ] );
    }
    return res;
}

bool BitString::IsOkString( const std::string & str ) {
	for ( auto s : str ) {
		if ( ( s != '0' ) && ( s != '1' ) ) {
			return false;
		}
	}
	return true;
}

size_t BitString::Count( ) const
{
    return Sz( );
}

BitString operator>>( const BitString & other, int n ) {
	BitString loc = other;
	loc >>= n;
	return loc;
}

BitString operator<<( const BitString & other, int n ) {
	BitString loc = other;
	loc <<= n;
	return loc;
}

BitString operator|( const BitString & first, const BitString & second ) {
	BitString loc = first;
	loc |= second;
	return loc;
}

BitString operator&( const BitString & first, const BitString & second ) {
	BitString loc = first;
	loc &= second;
	return loc;
}

BitString operator^( const BitString & first, const BitString & second ) {
	BitString loc = first;
	loc ^= second;
	return loc;
}

std::ostream & operator<<( std::ostream & out, const BitString & other )
{
    if ( other.Count( ) > 0 ) {
        out << other << " count:" << other.Count( );
    } else {
        out << "NULL BTS";
    }
    return out;
}

std::istream & operator>>( std::istream & in, BitString & other )
{
    //    char ch = ' ';
    //    int k = 0;
    //    in.get( ch );
    //    while ( ( ch == '0' || ch == '1' ) && k < BitString::MAX_ELEM ) {
    //        other[ k++ ] = ch;
    //        in.get( ch );
    //    }
    //    if ( !k )
    //        in.setstate( in.failbit );
    //    other.count = k;
    //    other.bitStr[ k ] = '\0';
    return in;
}
