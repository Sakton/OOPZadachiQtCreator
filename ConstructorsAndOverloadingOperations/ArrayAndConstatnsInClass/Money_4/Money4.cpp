#include "Money4.h"
#include <cstring>
#include <stdexcept>

Money4::Money4( const std::string & s ) : m_arr{ nullptr }, m_size{ 0 }, m_negative{ false } {
	//std::cout << "ctor " << std::endl;
	if ( IsValidSize( s.size( ) ) && IsValidString( s ) ) {
		std::string local = s;
		NormaliseString( local ); //точек больше нет, всегда 2 знака после запятой
		m_size = local.size( ) - 1; //место на разделитель
		if ( local[ 0 ] == '-' ) {
			--m_size;
			m_negative = true;
		}
		m_arr = new int16_t[ m_size ]; //TODO без проверки на выделение памяти
		int j = 0;
		for ( std::string::const_reverse_iterator i = local.crbegin( ); i != local.crend( ); ++i ) {
			if ( *i != ',' && *i != '-' ) {
				m_arr[ j++ ] = ( *i - '0' );
			}
		}
	} //иначе исключение
}

Money4::Money4( int16_t sz ) :m_arr{ nullptr }, m_size{ 0 }, m_negative{ false } {
	if ( 0 < sz && sz < MAX_LEN ) {
		m_size = sz;
		m_arr = new int16_t[ sz ];
		for ( int i = 0; i < m_size; ++i )
			m_arr[ i ] = 0;
	}
	else {
		throw std::runtime_error( "LENTH ERROR" );
	}
}

Money4::Money4( int16_t arr[ ], int sz, int begin, int end )
	: m_arr{ nullptr }, m_size{ 0 }, m_negative{ false }
{
	m_size = end - begin + 1;
	m_arr = new int16_t[ m_size ];
	int j = 0;
	for ( int i = begin; i < end; ++i) {
		m_arr[ j++ ] = arr[ i ];
	}
	m_arr[ j ] = 0;
}

Money4::~Money4( ) {
	delete[ ] m_arr;
}

Money4::Money4( const Money4 & rhs )
	: m_arr{ nullptr }, m_size{ 0 }, m_negative{ false }
{
	std::cout << "ctor copy" << std::endl;
	delete[ ] m_arr;
	m_arr = new int16_t[ rhs.m_size ];
	copyArr( m_arr, rhs.m_arr, rhs.m_size );
	m_size = rhs.m_size;
	m_negative = rhs.m_negative;
}

Money4::Money4( Money4 && rhs )noexcept
	: m_arr{ rhs.m_arr }, m_size{ rhs.m_size }, m_negative{ rhs.m_negative } {
	std::cout << "ctor move" << std::endl;
	rhs.m_arr = nullptr;
	rhs.m_size = 0;
}

Money4 & Money4::operator = ( const Money4 & rhs ) {
	if ( this != &rhs ) {
		std::cout << "copy op" << std::endl;
		delete[ ] m_arr;
		m_arr = new int16_t[ rhs.m_size ];
		copyArr( m_arr, rhs.m_arr, rhs.m_size );
		m_size = rhs.m_size;
		m_negative = rhs.m_negative;
	};
	return *this;
}

Money4 & Money4::operator=( Money4 && rhs ) noexcept {
	if ( this != &rhs ) {
		std::cout << "op move" << std::endl;
		delete[ ] m_arr;
		m_arr = rhs.m_arr;
		rhs.m_arr = nullptr;
		m_size = rhs.m_size;
		rhs.m_size = 0;
		m_negative = rhs.m_negative;
	}
	return *this;
}

int16_t & Money4::operator[]( int index )
{
	if ( ( m_size - 1 ) < index || index < 0 ) {
		throw std::runtime_error( "BAD INDEX []" );
	}
	int x = m_size - 1 - index;
	return m_arr[ m_size - 1 - index ];
}

Money4 & Money4::operator+=( const Money4 & rhs ) {
	if ( m_negative == rhs.m_negative ) { //если знаки одинаковы
		if ( rhs <= *this ) {
			*this = addingModules( *this, rhs );
			//m_negative = rhs.m_negative;
		}
		else {
			*this = addingModules( rhs, *this );
		}
	}
	else {
		if ( m_negative && ( Modul( rhs ) < Modul( *this ) ) ) {
			*this = substractionModules( *this, rhs );
			m_negative = true;
		}
		else if ( !m_negative && ( Modul( rhs ) < Modul( *this ) ) ) {
			*this = substractionModules( *this, rhs );
		}
		else if ( rhs.m_negative && ( Modul( *this ) < Modul( rhs ) ) ) {
			*this = substractionModules( rhs, *this );
			m_negative = true;
		}
		else if ( !rhs.m_negative && ( Modul( *this ) < Modul( rhs ) ) ) {
			*this = substractionModules( rhs, *this );
		}
		else {
			*this = Money4( );
		}
	}
	return *this;
}

Money4 & Money4::operator-=( const Money4 & rhs ) {
	if ( m_negative == rhs.m_negative ) {
		if ( rhs < *this ) {
			*this = substractionModules( *this, rhs );
		}
		else if ( *this > rhs ) {
			*this = substractionModules( rhs, *this );
			m_negative = !m_negative;
		}
		else {
			*this = Money4( );
		}
	}
	else {
		if ( Modul( rhs ) <= Modul( *this ) ) {
			*this = addingModules( *this, rhs );
		}
		else {
			*this = addingModules( rhs, *this );
			m_negative = !m_negative;
		}
	}
	return *this;
}

Money4 & Money4::operator*=( const Money4 & rhs ) {
	if ( rhs == Money4( ) || *this == Money4( ) )
		return *this = Money4( );
	if ( this->m_negative == rhs.m_negative ) //если знаки одинаковы
	{
		if ( *this <= rhs ) {
			*this = MultModules( rhs, *this );
		}
		else {
			*this = MultModules( *this, rhs );
		}
	}
	else {
		if ( Modul( *this ) <= Modul( rhs ) ) {
			*this = MultModules( rhs, *this );
		}
		else {
			*this = MultModules( *this, rhs );
		}
		m_negative = true;
	}
	return *this;
}

Money4 & Money4::operator/=( const Money4 & rhs )
{

	return *this;
}

std::string Money4::ToString( ) const {
	std::string res;
	if ( m_negative ) res = "-";
	if ( m_arr != nullptr && m_size > 0 ) {
		for ( int i = m_size - 1; i >= 0; --i ) {
			if ( i == 1 )
				res.push_back( ',' );
			res.push_back( m_arr[ i ] + '0' );
		}
	}
	return res;
}

int16_t Money4::Size( ) const {
	return m_size;
}

void Money4::TrimZero( ) {
	while ( ( m_arr[ m_size - 1 ] == 0 ) && ( m_size > 3 ) ) {
		--m_size;
	}
}

void Money4::DeleteNegative( ) {
	m_negative = false;
}

void Money4::NormaliseString( std::string & s ) {
	if ( !s.size( ) || ( ( s.size( ) == 1 ) && ( !std::isdigit( s[ 0 ] ) ) ) )
		s = "0,00";
	else {
		int pos = s.find( '.' );
		if ( pos == std::string::npos ) {
			pos = s.find( ',' );
		}
		if ( pos == std::string::npos ) {
			s += ",00";
		}
		else {
			s[ pos ] = ',';
			if ( s.size( ) - 1 - pos == 1 ) {
				s.push_back( '0' );
			}
			if ( s.size( ) - 1 - pos == 2 ) {
				s += "00";
			}
			if ( s.size( ) - 1 - pos > 2 ) {
				//округления не делать, это отдельная песниа
				while ( s.size( ) - 1 - pos > 2 ) {
					s.pop_back( );
				}
			}
		}
	}
}

bool Money4::IsValidString( const std::string & s )const {
	if ( s.size( ) > 0 ) {
		//if ( s.size( ) == 1 && !std::isdigit( s[ 0 ] ) ) return false;
		std::string::const_iterator i = s.cbegin( );
		if ( *i == '-' ) ++i;
		for ( ; i != s.cend( ); ++i ) { //проверяем на цифры, но может быть точка или запятая
			if ( !std::isdigit( *i ) && *i != '.' && *i != ',' ) return false;
		}
	}
	else {
		return false;
	}
	return true;
}

bool Money4::IsValidSize( int sz )const {
	return ( 0 < sz && sz <= 100 );
}

void Money4::copyArr( int16_t to[ ], int16_t from[ ], int sz ) {
	for ( int i = 0; i < sz; ++i )
		to[ i ] = from[ i ];
}

Money4 Money4::Modul( const Money4 & lhs )const {
	Money4 loc = lhs;
	loc.m_negative = false;
	return loc;
}

Money4 Money4::addingModules( const Money4 & lhs, const Money4 & rhs ) const {
	Money4 loc( lhs.m_size + 1 );
	loc.m_negative = lhs.m_negative; //присваиваем знак большего элемента
	int16_t perenos = 0;
	int i = 0; //индес прохода по массиву в локальном объекте
	//меньший или равный индекс у правого
	for ( ; i < rhs.m_size; ++i ) {
		int16_t a = lhs.m_arr[ i ];
		int16_t b = rhs.m_arr[ i ];
		int16_t res = a + b + perenos;
		if ( res >= 10 ) {
			perenos = 1;
			res -= 10;
		}
		else {
			perenos = 0;
		}
		loc.m_arr[ i ] = res;
	}
	for ( ; i < lhs.m_size; ++i ) {
		int16_t a = lhs.m_arr[ i ];
		int16_t res = a + perenos;
		if ( res >= 10 ) {
			perenos = 1;
			res -= 10;
		}
		else {
			perenos = 0;
		}
		loc.m_arr[ i ] = res;
	}
	if ( perenos )
		loc.m_arr[ i ] = perenos;
	else
		loc.m_arr[ i ] = 0;
	loc.TrimZero( ); //TODO НЕ ПОНЯТНАЯ СЕМАНТИКА ПЕРЕНОСА ТУТ
	return loc;
}

Money4 Money4::substractionModules( const Money4 & lhs, const Money4 & rhs ) const {
	Money4 loc( lhs.m_size );
	int16_t perenos = 0;
	int i = 0;
	for ( ; i < rhs.m_size; ++i ) {
		int16_t a = lhs.m_arr[ i ];
		int16_t b = rhs.m_arr[ i ];
		int16_t c = a - perenos - b;
		if ( c < 0 ) {
			c += 10;
			perenos = 1;
		}
		else {
			perenos = 0;
		}
		loc.m_arr[ i ] = c;
	}
	for ( ; i < lhs.m_size; ++i ) {
		int16_t a = lhs.m_arr[ i ];
		int16_t c = a - perenos;
		if ( c < 0 ) {
			c += 10;
			perenos = 1;
		}
		else {
			perenos = 0;
		}
		loc.m_arr[ i ] = c;
	}
	loc.TrimZero( );
	return loc;
}

/*
Money4 Money4::MultOneNumber( const Money4 & umnogaemoe, int16_t mnogitel, int16_t poryadok )const
{
	Money4 tmp( Size( ) + poryadok );
	int16_t perenos = 0;
	int j = poryadok - 1;
	for ( int i = 0; i < m_size; ++i ) {
		int16_t a = m_arr[ i ];
		int16_t x = a * mnogitel + perenos;
		tmp.m_arr[ j++ ] = x % 10;
		perenos = x / 10;
	}
	if ( perenos ) {
		tmp.m_arr[ j ] = perenos;
	}
	tmp.TrimZero( );
	return tmp;
}
*/

Money4 Money4::MultOneNumber( const Money4 & umnogaemoe, int16_t mnogitel ) const
{
	Money4 tmp( Size( ) + 1 );
	int16_t perenos = 0;
	int j = 0;
	for ( int i = 0; i < m_size; ++i ) {
		int16_t a = umnogaemoe.m_arr[ i ];
		int16_t x = a * mnogitel + perenos;
		tmp.m_arr[ j++ ] = x % 10;
		perenos = x / 10;
	}
	if ( perenos ) {
		tmp.m_arr[ j ] = perenos;
	}
	tmp.TrimZero( );
	return tmp;
}

Money4 Money4::MultModules( const Money4 & umnogaemoe, const Money4 & mnogitel ) const
{
	Money4 res;
	for ( int i = 0; i < mnogitel.m_size; ++i ) {
		Money4 t = MultOneNumber( umnogaemoe, mnogitel.m_arr[ i ] );
		res += MiltTo_10x( t, i );
	}
	res.PopravkaMult( );
	res.TrimZero( );
	return res;
}

Money4 Money4::MiltTo_10x( const Money4 & umnogaemoe, int16_t poryadok )const
{
	Money4 tmp( umnogaemoe.Size( ) + poryadok );
	//i - отвечает за перемещение по tmp
	//j - по umnogaemoe
	for ( int i = poryadok, j = 0; j < umnogaemoe.Size( ); ++j, ++i ) {
		tmp.m_arr[ i ] = umnogaemoe.m_arr[ j ];
	}
	tmp.TrimZero( );
	return tmp;
}

void Money4::PopravkaMult( )
{
	int i = 0; //отвечает за вставку
	int j = i + 2; //отвечает за считывание
	for ( ; j < m_size; ++i, ++j ) m_arr[ i ] = m_arr[ j ];
	for ( ; i < m_size; ++i ) m_arr[ i ] = 0;
}

Money4 Money4::DivideModules( const Money4 & delimoe, const Money4 & delitel )
{
	//


	//ПЛАН:
	 //в цикле пока индекс на число в массиве на станет равным нулю п.7

	//1. Выделить из числа подчисло, тогоже порядка
	//2. Если подчисло меньше делимого, то выделить подчисло снова на порядок больше
	//3. Начать поиск множитела, в цикле умножать до тех пор пока произведение не станет больше делителя
	//тогда предыдущее число и будет одним из числа частного
	//4. Вычислить произведение делимого на найденное число делителя ( лучше хранить предыдущее число )
	//5. Найти остаток от разности выделенного подчисла и найденного произведения
	//6. Добавлять к остатку числа из делимого пока новое подчисло не станет больше делителя ( предыдущее значение - искомое )

	//7. Это все проделывать пока не закончатся сносимые числа


	return Money4( );
}

std::ostream & operator<<( std::ostream & out, const Money4 & rhs ) {
	out << rhs.ToString( );
	return out;
}

Money4 operator+( const Money4 & lhs, const Money4 & rhs ) {
	Money4 loc = lhs;
	loc += rhs;
	return loc;
}

Money4 operator-( const Money4 & lhs, const Money4 & rhs ) {
	Money4 loc = lhs;
	loc -= rhs;
	return loc;
}

Money4 operator*( const Money4 & lhs, const Money4 & rhs )
{
	Money4 loc = lhs;
	loc *= rhs;
	return loc;
}

bool operator<( const Money4 & lhs, const Money4 & rhs ) {
	if ( lhs.m_negative && !rhs.m_negative ) return true;
	if ( lhs.m_size < rhs.m_size ) return true;
	//если длины строк равны можно сраанить их лексикографически
	if ( ( lhs.m_size == rhs.m_size ) && ( lhs.ToString( ) < rhs.ToString( ) ) ) return true;
	return false;
}

bool operator>( const Money4 & lhs, const Money4 & rhs )
{
	return !( lhs < rhs ) && !( lhs == rhs );
}

bool operator<=( const Money4 & lhs, const Money4 & rhs ) {
	return ( ( lhs < rhs ) || ( lhs == rhs ) );
}

bool operator==( const Money4 & lhs, const Money4 & rhs ) {
	return ( ( lhs.m_negative == rhs.m_negative ) && ( lhs.ToString( ) == rhs.ToString( ) ) );
}
