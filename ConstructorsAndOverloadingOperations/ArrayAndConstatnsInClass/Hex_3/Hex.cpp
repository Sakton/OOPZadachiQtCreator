#include "Hex.h"
#include <stdexcept>
#include <iostream>

const int Hex::MAX_SIZE = 100;
const Hex::TypeHexArray Hex::symbolsHex[ ]{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

Hex::Hex( ) : m_hx{ new TypeHexArray[ 1 ] }, m_count{ 1 }
{
	m_hx[ 0 ] = '0';
	//std::cout << "Ctor" << std::endl;
}

Hex::Hex( const std::string & s ) : m_hx{ nullptr }, m_count{ 0 }
{
	if ( s.size( ) > MAX_SIZE ) throw new std::runtime_error( "CTOR VERY BIG NUMBER MAX = 100 symb" );
	if ( !IsOkString( s ) ) throw new std::runtime_error( "ERROR Ctor No Ok String" );
	m_hx = new TypeHexArray[ s.size( )/* + 1 */ ];
	if ( !m_hx ) throw new std::runtime_error( "ERROR Ctor Allocated Memory" );
	m_count = s.size( );
	auto ri = s.crbegin( );
	int i = 0;
	for ( ; i < s.size( ) && ri != s.crend( ); ++i, ++ri ) {
		m_hx[ i ] = *ri;
	}
}

Hex::Hex( IntegralType decNum ) : Hex( IntegralType2Hex( decNum ) ) {
	//std::cout << "CtorNum" << std::endl;
}

Hex::Hex( const Hex & other ) : m_hx{ nullptr }, m_count{ 0 } {
	if ( other.m_count + 1 > MAX_SIZE ) throw new std::runtime_error( "CPYCTOR.count > MAX = 100 symb" );
	TypeHexArray * t = new TypeHexArray[ other.m_count /*+ 1*/ ];
	if ( !t ) throw new std::runtime_error( "cpyCtor error memory allocation" );
	for ( int i = 0; i < other.m_count; ++i ) t[ i ] = other.m_hx[ i ];
	delete[ ] m_hx;
	m_hx = t;
	m_count = other.m_count;
	//std::cout << "CpuCtor" << std::endl;
}

Hex & Hex::operator=( const Hex & other ) {
	if ( this == &other ) return *this;
	if ( other.m_count > MAX_SIZE ) throw new std::runtime_error( "OP=.count > MAX = 100 symb" );
	auto t = new TypeHexArray[ other.m_count /*+ 1*/ ];
	if ( !t ) throw new std::runtime_error( "Error Allocation operetor =" );
	for ( int i = 0; i < other.m_count; ++i ) t[ i ] = other.m_hx[ i ];
	delete[ ] m_hx;
	m_hx = t;
	m_count = other.m_count;
	//std::cout << "op=" << std::endl;
	return *this;
}

Hex::Hex( Hex && other )noexcept {
	m_hx = other.m_hx;
	other.m_hx = nullptr;
	m_count = other.m_count;
	other.m_count = 0;
	//std::cout << "MoveCtor" << std::endl;
}

Hex & Hex::operator=( Hex && other )noexcept {
	delete[ ] m_hx;
	m_hx = other.m_hx;
	other.m_hx = nullptr;
	m_count = other.m_count;
	//std::cout << "MoveOp=" << std::endl;
	return *this;
}

Hex::~Hex( ) {
	delete[ ] m_hx;
}

Hex & Hex::operator+=( const Hex & other ) {
	Hex loc;
	if ( *this <= other ) loc = AddictionNumbers( other, *this );
	else loc = AddictionNumbers( *this, other );
	return *this = loc;
}

Hex & Hex::operator-=( const Hex & other ) {
	Hex loc = *this;
	loc = SubtractNumbers( *this, other );
	return *this = loc;
}

Hex & Hex::operator*=( const Hex & other ) {
	Hex loc;
	if ( *this >= other ) {
		loc = Mult( *this, other );
	} else {
		loc = Mult( other, *this );
	}
	return *this = loc;
}

Hex & Hex::operator/=( const Hex & other ) {
	Hex loc;
	if ( *this > other ) {
		loc = Divide( *this, other );
	}
	return *this = loc;
}

std::string Hex::ToString( )const {
	std::string loc;
	for ( int i = m_count - 1; i >= 0; --i ) {
		loc.push_back( m_hx[ i ] );
	}
	return loc;
}

std::size_t Hex::Count( ) const {
	return m_count;
}

std::string & Hex::ReverseString( std::string & s ) {
	for ( int m = 0, n = s.size( ) - 1; m <= n; ++m, --n ) {
		std::swap( s[ m ], s[ n ] );
	}
	return s;
}

std::string Hex::IntegralType2Hex( IntegralType num ) const {
	std::string s;
	while ( num != 0 ) {
		s.push_back( NumToChar( num % 16 ) );
		num /= 16;
	}
	auto r = s.size( ) - 1;
	auto l = 0;
	while ( l <= r ) {
		std::swap( s[ l ], s[ r ] );
		++l; --r;
	}
	return s;
}

Hex::TypeHexArray Hex::NumToChar( int n ) const {
	char ch = ' ';
	switch ( n ) {
		case 0: ch = '0'; break;
		case 1: ch = '1'; break;
		case 2: ch = '2'; break;
		case 3: ch = '3'; break;
		case 4: ch = '4'; break;
		case 5: ch = '5'; break;
		case 6: ch = '6'; break;
		case 7: ch = '7'; break;
		case 8: ch = '8'; break;
		case 9: ch = '9'; break;
		case 10: ch = 'A'; break;
		case 11: ch = 'B'; break;
		case 12: ch = 'C'; break;
		case 13: ch = 'D'; break;
		case 14: ch = 'E'; break;
		case 15: ch = 'F'; break;
		default:
			break;
	}
	return ch;
}

int Hex::CharToNum( char ch ) const {
	int x = 0;
	switch ( ch ) {
		case '1': x = 1; break;
		case '2': x = 2; break;
		case '3': x = 3; break;
		case '4': x = 4; break;
		case '5': x = 5; break;
		case '6': x = 6; break;
		case '7': x = 7; break;
		case '8': x = 8; break;
		case '9': x = 9; break;
		case 'a':
		case 'A': x = 10; break;
		case 'b':
		case 'B': x = 11; break;
		case 'c':
		case 'C': x = 12; break;
		case 'd':
		case 'D': x = 13; break;
		case 'e':
		case 'E': x = 14; break;
		case 'f':
		case 'F': x = 15; break;

		default:
			break;
	}
	return x;
}

bool Hex::IsOkString( const std::string & s ) {
	for ( auto el : s ) {
		if ( !( ( '0' <= el && el <= '9' ) || ( 'A' <= el && el <= 'F' ) || ( 'a' <= el && el <= 'f' ) ) )
			return false;
	}
	return true;
}

Hex::HexPair Hex::Sum2Num( TypeHexArray first, TypeHexArray second )const {
	int f = CharToNum( first );
	int s = CharToNum( second );
	int res = f + s;
	return ToHexMaxInt255( res );
}

Hex::HexPair Hex::Sum3Num( TypeHexArray first, TypeHexArray second, TypeHexArray third ) const {
	int a = CharToNum( first );
	int b = CharToNum( second );
	int c = CharToNum( third );
	return ToHexMaxInt255( a + b + c );
}

Hex::HexPair Hex::ToHexMaxInt255( int f )const {
	HexPair loc;
	int x = f % 16;
	f = f / 16;
	loc.second = NumToChar( x );
	loc.first = NumToChar( f );
	return loc;
}

Hex::HexPair Hex::Sub2Num( TypeHexArray first, TypeHexArray second ) const {
	HexPair loc;
	TypeHexArray perechod = '0';
	int x = CharToNum( first );
	int y = CharToNum( second );
	int res = 0;
	if ( x < y ) {
		res = 16 + x - y;
		loc.second = NumToChar( res );
		loc.first = NumToChar( 16 - 1 ); //
	} else {
		res = x - y;
		loc.second = NumToChar( res );
		loc.first = NumToChar( 0 );
	}
	return loc;
}

void Hex::TrimZero( ) {
	std::string loc;
	if ( m_hx[ m_count - 1 ] == '0' ) { //если в конце 0 (а это начало числа), то лишние нули есть, и их надо удалять
		int i = m_count - 1;
		for ( ; i >= 1 && m_hx[ i ] == '0'; --i ); //посчитаем сколько надо место-индексов для нового массива, до предпоследнего
		TypeHexArray * t = new TypeHexArray[ i + 1 ]; //+1 поправка на переход от индексов к количеству
		m_count = i + 1;
		for ( ; i >= 0; --i ) {
			t[ i ] = m_hx[ i ];
		}
		delete[ ] m_hx;
		m_hx = t;
	}
}

Hex Hex::SubtractNumbers( const Hex & first, const Hex & second ) const {
	//алгоритм вычитания из 2 частей
	//Вычитается всегда из первого второе
	//1. Вычитание пока есть символы чисел у любого из аргументов ф-ии
	std::string loc;
	TypeHexArray perehod = '0';
	int i = 0;
	for ( ; i < first.m_count && i < second.m_count; ++i ) {
		TypeHexArray x = first.m_hx[ i ];
		TypeHexArray y = second.m_hx[ i ];
		if ( perehod != '0' )
			x = NumToChar( CharToNum( x ) - 1 );
		HexPair xp = Sub2Num( x, y );
		loc.push_back( xp.second );
		if ( xp.first == 'F' ) perehod = '1';
		else perehod = '0';
	}
	//2. Когда символы кончились
	//2.1 Символов нет у вычитаемого
	if ( second.m_count <= i ) {
		for ( int j = i; j < first.m_count; ++j ) {
			if ( perehod != 0 ) {
				HexPair xp = Sub2Num( first.m_hx[ j ], perehod );
				loc.push_back( xp.second );
				if ( xp.first == 'F' ) {
					perehod = '1';
				} else {
					perehod = '0';
				}
			} else {
				loc.push_back( first.m_hx[ j ] );
			}
		}
	} else if ( first.m_count <= i ) { //2.2 Символов нет у уменьшаемого
		perehod = 'F';
		for ( int j = i; j < second.m_count; ++j ) {
			HexPair xp = Sub2Num( perehod, second.m_hx[ j ] );
			loc.push_back( xp.second );
			//perehod = xp.first;
		}
	}

	if ( perehod != '0' )
		loc.push_back( perehod );

	ReverseString( loc );

	Hex tmp{ loc };
	tmp.TrimZero( );
	return tmp;
}

Hex::HexPair Hex::Mult2Numbers( TypeHexArray a, TypeHexArray b )const {
	return ToHexMaxInt255( CharToNum( a ) * CharToNum( b ) );
}

Hex Hex::MultToOneNumber( const Hex & a, TypeHexArray symbol )const {
	//1. узнать произведение числа на порядковое число
	//2. если есть цифра для переноса сложить с получившимся произведением
	//3. младший разряд записать в ответ, старший в цифру переноса
	//4. Выполнять до тех пор пока есть символы в умножаемом числе
	//5. Если после цикла (после перемножения всех значащих цифр) есть цифра переноса то записать ее ответ в старший разряд
	std::string loc;
	TypeHexArray perehod = '0';
	int symbolInt = CharToNum( symbol );
	for ( int i = 0; i < a.m_count; ++i ) {
		int aLoc = CharToNum( a.m_hx[ i ] );
		int res = aLoc * symbolInt + CharToNum( perehod );
		HexPair t = ToHexMaxInt255( res );
		loc.push_back( t.second );
		perehod = t.first;
	}
	if ( perehod != '0' )
		loc.push_back( perehod );
	ReverseString( loc );
	return Hex{ loc };
}

Hex Hex::Mult10( const Hex & a )const {
	std::string loc = a.ToString( );
	loc.push_back( '0' );
	return Hex( loc );
}

Hex Hex::Mult10xX( const Hex & a, int n )const {
	std::string loc = a.ToString( );
	for ( int i = 0; i < n; ++i )
		loc.push_back( '0' );
	return Hex( loc );
}

Hex Hex::Mult( const Hex & a, const Hex & b )const { //a > b
	//1. Умножить на число получить результат и сохранить в локальеной переменной хранящем сумму 1 порядок
	//2. Умножить второе число
	//3. Сделать поправку на порядок (домножить на 10!!!) или сдвинуть на 1 влево и дописать ноль
	//4. Сложить с суммой и сохранить итог
	//5. Вернуть сумму
	Hex resSum;
	for ( int i = 0; i < b.m_count; ++i ) {
		Hex t = MultToOneNumber( a, b.m_hx[ i ] );
		t = Mult10xX( t, i );
		resSum += t;
	}
	return resSum;
}

Hex Hex::PickOutPodchislo( const Hex & delimoe, const Hex & delitel )const {
	//TODO доделать тут
	std::string loc;
	int i = delimoe.m_count - 1;
	int j = delitel.m_count - 1;
	for ( ; j >= 0; --i, --j ) {
		loc.push_back( delimoe.m_hx[ i ] );
	}
	//ReverseString( loc );
	if ( Hex( loc ) < delitel ) {
		//ReverseString( loc );
		loc.push_back( delimoe.m_hx[ i ] );
		//ReverseString( loc );
	}
	return Hex( loc );
}

Hex::TypeHexArray Hex::SearchOneNum( const Hex & delimoe, const Hex & delitel )const {
	//Использовать бинарный поиск, ищем в массиве символов для Hex - symbolsHex[];
	int left = 0;
	int right = 15;
	TypeHexArray res = symbolsHex[ 0 ];
	//как как точное значение не вычисляется, созможна ситуация когда проверяемое число лежит между значений произведения делителя и множителя, и происходит зацикливание, не может приблизится к проверяемому числу
	//то необходим прерыватель цикла
	//в худшем случае бинарный поиск будет выполнятся log(16) = 4 раза
	int k = 4;
	while ( left <= right && k >= 0 ) {
		//		if ( MultToOneNumber( delimoe, mid ) == delitel ) res = mid;
		int mid = ( left + right ) / 2; //Начинаем с серединки
		res = symbolsHex[ mid ]; //сохраняем значение сразу, так как достаточно и приближения к искомому
		if ( MultToOneNumber( delitel, res ) < delimoe ) {
			left = mid;
		} else if ( MultToOneNumber( delitel, res ) > delimoe ) {
			right = mid;
		} else if ( MultToOneNumber( delitel, res ) == delimoe ) {
			break;
		}
		--k;
	}
	return res;
}

Hex Hex::Divide( const Hex & delimoe, const Hex & delitel ) const {
	if ( delitel == Hex{} ) throw new std::runtime_error( "Divide to Zero" );
	std::string resStr;
	//1 Часть. Начало деления, выделить число, получить первую цифру частного, сохранить. Вычислить остаток.
	//2 Часть. К остатку добавить число из делимого - это новое выделенное число. посторять пока новое выделенное число не 
	// станет меньше делителя
	int i = 0;
	Hex podchislo = PickOutPodchislo( delimoe, delitel );
	i = podchislo.m_count; //счетчик индекса делимого, начальное значение - размер подчисла
	//while( i )
	while ( podchislo > delitel ) { //пока подчисло больше делителя

		TypeHexArray symbol = SearchOneNum( podchislo, delitel ); //находим цифру частного
		resStr.push_back( symbol ); //сохраняем
		Hex chastnoe = podchislo - MultToOneNumber( delitel, symbol ); //вычитаем
		std::string temp = chastnoe.ToString( ); //преобразование в строку
		podchislo = Hex( temp ); 
		while ( i < delimoe.m_count && podchislo < delitel ) { //пока есть символы в делителе и подчисло меньше делителя
			//формируем его снова и снова. (для случаев когда частное == 0 ну или почти 0, мало )
			temp.push_back( delimoe.ToString( )[ i++ ] );//сносим в строку символ от делителя
			podchislo = Hex( temp );//формируем новое частное
		}
	}
	return Hex( resStr );
}

Hex Hex::AddictionNumbers( const Hex & first, const Hex & second ) const {
	std::string loc;
	int i = 0;
	int j = 0;
	TypeHexArray perechod = '0';
	for ( ; i < second.m_count; ++i, ++j ) {
		HexPair res = Sum3Num( first.m_hx[ j ], second.m_hx[ i ], perechod );
		loc.push_back( res.second );
		perechod = res.first;
	}
	if ( j < first.m_count ) {
		for ( ; j < first.m_count; ++j ) {
			HexPair res = Sum2Num( first.m_hx[ j ], perechod );
			loc.push_back( res.second );
			perechod = res.first;
		}
	}
	if ( perechod != '0' ) loc.push_back( perechod );

	ReverseString( loc );
	Hex res{ loc };
	res.TrimZero( );
	return res;
}

bool operator<( const Hex & first, const Hex & second ) {
	if ( first.m_count < second.m_count ) return true;
	if ( first.m_count == second.m_count ) {
		for ( int i = first.m_count - 1; i >= 0; --i ) {
			if ( std::toupper( first.m_hx[ i ] ) < std::toupper( second.m_hx[ i ] ) ) return true; //привести к регистру одному
			else if ( std::toupper( first.m_hx[ i ] ) > std::toupper( second.m_hx[ i ] ) ) return false;
		}
	}
	return false;
}

bool operator>( const Hex & first, const Hex & second ) {
	return !( first < second );
}

bool operator>=( const Hex & first, const Hex & second ) {
	return ( first > second || first == second );
}

bool operator<=( const Hex & first, const Hex & second ) {
	return ( first < second || first == second );
}

bool operator==( const Hex & first, const Hex & second ) {
	if ( first.m_count != second.m_count ) return false;
	else {
		/*
		for ( int i = first.m_count - 1; i >= 0; --i ) {
			if ( first.m_hx[ i ] != second.m_hx[ i ] ) return false;
		}
		*/
		int i = first.m_count - 1;
		for ( ; i >= 0 && first.m_hx[ i ] == second.m_hx[ i ]; --i );
		return -1 == i;
	}
	//return true;
}

bool operator!=( const Hex & first, const Hex & second ) {
	return !( first == second );
}

Hex operator+( const Hex & first, const Hex & second ) {
	Hex loc = first;
	loc += second;
	return loc;
}

Hex operator-( const Hex & first, const Hex & second ) {
	Hex loc = first;
	loc -= second;
	return loc;
}

Hex operator*( const Hex & first, const Hex & second ) {
	Hex loc = first;
	loc *= second;
	return loc;
}

Hex operator/( const Hex & first, const Hex & second ) {
	Hex loc = first;
	loc /= second;
	return loc;
}
