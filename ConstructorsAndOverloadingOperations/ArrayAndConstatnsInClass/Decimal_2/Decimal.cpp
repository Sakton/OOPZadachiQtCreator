//#include "Decimal.h"
//#include <algorithm>

////констуктор порядка числа, равное 0
////инвариат обьект корректный прилюбом значении sz
////тип size_t использовать плохо, при < 0, оно огромно
////с другой стороны оно не может быть < 0, одной проверкой меньше
////если передано большое число лучше прервать программу и выкинуть исключение,
///чем инициализировать другое значени еи его испльзовать в расчетах /ошибку
///потом можно и не найти
// Decimal::Decimal( int sz ) : decm{ nullptr }, count{ 0 }, negative{ false } {
//	sz = ( 0 < sz && sz < MAX_SIZE ) ? sz : throw new std::runtime_error(
//"bad size num (ctor)" ); 	decm = new Type[ sz + 1 ]; 	for( int i = 0;
//i < sz;
//++i ) decm[ i ] = '0'; 	decm[ sz ] = '\0'; 	count = sz;
//}

////конструктор инициализации строкой - числом
////объект корректен при неверной строке
// Decimal::Decimal( const char * str ) : Decimal() {
//	size_t lenth = std::strlen( str );
//	if( lenth > MAX_SIZE ) throw new std::runtime_error( "bad size num
//(ctor)" ); //если строка большая то нет смысла брать часть, тк. то число само
//по себе больше и нужен другой тип 	if( !checkStringForCorrectness( str ) )
// throw new std::runtime_error( "bad str ctor (ctor)" ); //если строка не
//корректна то выход 	Type * t = new Type[ lenth + 1 ]; 	if( !t ) throw
//new std::runtime_error( "bad alloc memory (ctor)" ); //если память не
// выделилась выход 	int end = ( negative = ( str[ 0 ] == '-' ) ) ? 1 : 0;
////минус уменьшает проход на 1 и присвоим значение негатив в 1 операторе
//for( int i = 0, j = lenth - 1; j >= end; --j, ++i ) { //пишем переворачивая
// строку 		t[ i ] = str[ j
//];
//	}
//	int endIndex = ( negative ) ? lenth - 1 : lenth;
//	t[ endIndex ] = '\0';
//	delete[ ]decm;
//	decm = t;
//	count = endIndex;
//}

// Decimal::Decimal( const std::string & str ) : Decimal( str.c_str() ) { }
// //просто делегирую в другой конструктор

// Decimal::Decimal( const Decimal & d ) {
//	decm = new Type[ d.count + 1 ];
//	if( !decm ) throw new std::runtime_error( "bad alloc memory CpuCtor" );
//	auto dt = d.decm;
//	auto tt = decm;
//	while ( ( *tt++ = *dt++ ) )
//	    ;
//	count = d.count;
//	negative = d.negative;
//}

// std::ostream & operator << ( std::ostream & out, const Decimal & d ) {
//	out << d.ToString();
//	return out;
//}

// bool operator <= ( const Decimal & first, const Decimal & second ) {
//	return ( ( first < second ) || ( first == second ) );
//}

// bool operator >= ( const Decimal & first, const Decimal & second ) {
//	return ( first > second || first == second );
//}

// bool operator < ( const Decimal & first, const Decimal & second ) {
//	//1.сравнить 2 положительных
//	//2.разных знаков
//	//3.отрицательных
//	if( first.negative == false && second.negative == false ) {
//		return LessPoModule( first, second );
//	} else if( first.negative == true && second.negative == false ) {
//		return true;
//	} else if( first.negative == false && second.negative == true ) {
//		return false;
//	} else if( first.negative == true && second.negative == true ) {
//		return !LessPoModule( first, second );
//	}
//}

// bool operator > ( const Decimal & first, const Decimal & second ) {
//	return !( first < second );
//}

// bool operator == ( const Decimal & first, const Decimal & second ) {
//	return !( first != second );
//}

// bool operator != ( const Decimal & first, const Decimal & second ) {
//	if( ( first.count != second.count ) || first.negative != second.negative
//) return true; 	for( int i = first.count - 1; i >= 0; --i ) {
//if( first.decm[ i ] != second.decm[ i ] ) return true;
//	}
//	return false;
//	//return !(std::strcmp(reinterpret_cast<const char*>(first.decm),
// reinterpret_cast<const char*>(second.decm)) == 0);
//}

// Decimal operator - ( const Decimal & first, const Decimal & second ) {
//	Decimal loc = first;
//	loc -= second;
//	return loc;
//}

// Decimal operator - ( const Decimal & first, int x ) {
//	Decimal loc = first;
//	Decimal second( std::to_string( x ) );
//	loc -= second;
//	return loc;
//}

// Decimal operator - ( int x, const Decimal & first ) {
//	Decimal loc( std::to_string( x ) );
//	loc -= first;
//	return loc;
//}

// Decimal operator * ( const Decimal & first, const Decimal & second ) {
//	Decimal loc = first;
//	loc *= second;
//	return loc;
//}

// Decimal operator * ( const Decimal & first, int x ) {
//	Decimal loc = first;
//	Decimal second( std::to_string( x ) );
//	loc *= second;
//	return loc;
//}

// Decimal operator * ( int x, const Decimal & first ) {
//	return ( first * x );
//}

// Decimal operator / ( const Decimal & first, const Decimal & second ) {
//	Decimal loc = first;
//	loc /= second;
//	return loc;
//}

// Decimal operator / ( const Decimal & first, int x ) {
//	Decimal loc = first;
//	Decimal a( std::to_string( x ) );
//	return ( loc / a );
//}

// Decimal operator / ( int x, const Decimal & second ) {
//	Decimal a( std::to_string( x ) );
//	return ( a / second );
//}

// bool LessPoModule( const Decimal & first, const Decimal & second ) {
//	if( first.count < second.count ) return true;
//	if( first.count == second.count ) {
//		for( int i = first.count - 1; i >= 0; --i ) {
//			if( first.decm[ i ] == second.decm[ i ] ) continue;
//			else if( first.decm[ i ] < second.decm[ i ] ) return
// true; 			else if( first.decm[ i ] > second.decm[ i ] ) return
// false;
//		}
//	}
//	return false;
//}

// bool EquivalentPoModule( const Decimal & first, const Decimal & second ) {
//	if( first.count != second.count ) return false;
//	for( int i = 0; i < first.count; ++i )
//		if( first[ i ] != second[ i ] ) return false;
//	return true;
//}

// Decimal::~Decimal() {
//	delete[ ] decm;
//}

// const Decimal & Decimal::operator = ( const Decimal & d ) {
//	if( this == &d ) return *this;
//	Type * t = new Type[ d.count + 1 ];
//	// if( !t ) что делать если нет памяти
//	if( !t ) throw new std::runtime_error( "operator= error" );
//	auto tt1 = t;
//	auto tt2 = d.decm;
//	while ( ( *tt1++ = *tt2++ ) )
//	    ;
//	decm = t;
//	count = d.count;
//	negative = d.negative;
//	return *this;
//}

// Decimal & Decimal::operator += ( const Decimal & other ) {
//	//1. Если оба положительные
//	//2. Если оба отрицательные
//	//3. Разных знаков
//	if( negative == false && other.negative == false ) {
//		*this = ( *this <= other ) ? summa( other, *this ) : summa(
//*this, other ); 	} else if( negative == true && other.negative == true )
// { 		*this = ( *this < other ) ? summa( *this, other ) : summa(
//other, *this ); 		negative = true; 	} else if( negative !=
// other.negative ) { 		if( negative == true && other.negative == false
// && LessPoModule( *this, other ) ) {
//			//если само отрицательно и больше по модулю
//			*this = raznost( *this, other );
//		} else if( negative == true && other.negative == false &&
//! LessPoModule( *this, other ) ) {
//			//если само отрицательно и меньше по модулю
//			*this = raznost( other, *this );
//			negative = other.negative;
//		} else if( negative == false && other.negative == true &&
// LessPoModule( *this, other ) ) {
//			//если само положительное, а второе отрицательно но
//первое меньше по модулю 			*this = raznost( other, *this );
//negative = other.negative; 		} else if( negative == false && other.negative ==
//true &&
//! LessPoModule( *this, other ) ) {
//			//если само положительное, а второе отрицательно но
//первое больше по модулю 			*this = raznost( *this, other );
//		}
//	}
//	Trim();
//	return *this;
//}

// Decimal & Decimal::operator -= ( const Decimal & other ) {
//	//1. Если оба положительные
//	//2. Если оба отрицательные
//	//3. Разных знаков
//	if( negative == false && other.negative == false && LessPoModule( *this,
// other ) ) {
//		//оба положительные но само меньше по модулю
//		*this = raznost( other, *this );
//		negative = true;
//	} else if( negative == false && other.negative == false &&
//! LessPoModule( *this, other ) ) {
//		//оба положительные но само больше по модулю
//		*this = raznost( *this, other );
//	} else if( negative == true && other.negative == true && LessPoModule(
//*this, other ) ) {
//		//оба отрицательные но само по модулю меньше
//		*this = raznost( other, *this );
//		negative = false;
//	} else if( negative == true && other.negative == true && !LessPoModule(
//*this, other ) ) {
//		//оба отрицательные но само по модулю больше
//		*this = raznost( *this, other );
//		negative = false;
//	} else if( negative == false && other.negative == true && LessPoModule(
//*this, other ) ) {
//		//если само положительно другой отрицателен и само по модулю
//меньше другого 		*this = summa( other, *this ); 	} else if(
//negative == true && other.negative == false && LessPoModule( *this, other ) )
// {
//		//если само отрицательно другой положителен и само по модулю
//меньше другого 		*this = summa( other, *this ); 	} else if(
//negative == false && other.negative == true && !LessPoModule( *this, other ) )
// {
//		//если само положительно другой отрицателен и само по модулю
//больше другого 		*this = summa( *this, other ); 	} else if(
//negative == true && other.negative == false && !LessPoModule( *this, other ) )
// {
//		//если само отрицательно другой положителен и само по модулю
//больше другого 		*this = summa( *this, other );
//	}
//	Trim();
//	return *this;
//}

// Decimal & Decimal::operator *= ( const Decimal & other ) {
//	if( isZero() ) {
//		negative = false; //TODO очень плохо тут!!! оно должно быть не
//здесь, (если ноль то знак +) 		return *this;
//	}
//	if( other.isZero() ) {
//		*this = Decimal();
//	} else {
//		Decimal loc;
//		loc = ( *this <= other ) ? MultModules( other, *this ) :
// MultModules( *this, other ); 		loc.negative = ( negative ==
// other.negative ) ? false : true; 		*this = loc;
//	}
//	return *this;
//}

////так как тип имеет подобие int только большой размерности, дробная часть
///отбрасывается
// Decimal & Decimal::operator /= ( const Decimal & other ) {
//	// TODO: вставьте здесь оператор return
//	//1. если знаки одинаковые
//	//2. если знаки различны

//	if( other.isZero() ) throw new std::runtime_error( "Divide on Zero" );
////деление на 0 	if( isZero() || LessPoModule( *this, other ) ) { //если
///ноль
//или меньше второго возвращаем ноль 		*this = Decimal(); 	} else
//{ 		Decimal loc =
// Divide2( *this, other ); 		if( negative == true && other.negative ==
// true ) negative = false; 		else if( negative == true &&
// other.negative == false )
// negative = true; 		else if( negative == false && other.negative ==
// true ) negative = true; 		loc.negative = negative;
// *this = loc;
//	}
//	return *this;
//}

// Decimal::Type & Decimal::operator [] ( int index ) {
//	if( 0 <= index && index < count ) return decm[ count - 1 - index ];
//	else throw new std::runtime_error( "operator[]" );
//}

// const Decimal::Type & Decimal::operator [] ( int index ) const {
//	if( 0 <= index && index < count ) return decm[ count - 1 - index ];
//	else throw new std::runtime_error( "operator[]" );
//}

// size_t Decimal::Count() const {
//	return count;
//}

// std::string Decimal::ToString() const {
//	std::string loc;
//	if( negative ) loc.push_back( '-' );
//	for( int i = count - 1; i >= 0; --i ) loc.push_back( decm[ i ] );
//	return loc;
//}

// std::string Decimal::ModulToString() const {
//	std::string loc;
//	for( int i = count - 1; i >= 0; --i ) loc.push_back( decm[ i ] );
//	return loc;
//}

// bool Decimal::isZero()const {
//	for( int i = count - 1; i >= 0; --i )
//		if( decm[ i ] != '0' ) return false;
//	return true;
//}

// void Decimal::Trim() {
//	int i = count - 1;
//	for( ; i >= 1; --i ) if( decm[ i ] != '0' ) break; //если все нули, то
//последний надо оставить 	Type * t = new Type[ i + 1 + 1 ]; //индекс
//отличается от кличества на 1 и еще 1 на терминатор 	if( !t ) throw new
//std::runtime_error(
//"trim" ); 	int j = 0; 	for( ; j < i + 1; ++j ) t[ j ] = decm[ j ];
//t[ j ] =
//'\0'; 	delete[ ] decm; 	decm = t; 	count = j;
//}

////первый аргумант >= второго
// Decimal Decimal::summa( const Decimal & a, const Decimal & b )const {
//	if( a.isZero() && b.isZero() ) return Decimal();
//	Decimal loc( a.count + 1 );
//	//1. Сложить числа по размеру с меньшим
//	int perenosnoeZnachenie = 0;
//	//пока есть цифры в меньшей цифре
//	int i = 0;
//	for( ; i < b.count; ++i ) {
//		int x = CharToInt( a.decm[ i ] );
//		int y = CharToInt( b.decm[ i ] );
//		int z = x + y + perenosnoeZnachenie;
//		loc.decm[ i ] = IntToUChar( z % 10 );
//		perenosnoeZnachenie = z / 10;
//	}
//	//пока есть цифры в большей цифре
//	int j = i;
//	for( ; j < a.count; ++j ) {
//		if( perenosnoeZnachenie ) {
//			int x = CharToInt( a.decm[ j ] );
//			int z = x + perenosnoeZnachenie;
//			loc.decm[ j ] = IntToUChar( z % 10 );
//			perenosnoeZnachenie = z / 10;
//		} else {
//			loc.decm[ j ] = a.decm[ j ];
//		}
//	}
//	//если остался перенос значения
//	if( perenosnoeZnachenie ) {
//		loc.decm[ j++ ] = IntToUChar( perenosnoeZnachenie );
//	}
//	loc.decm[ j ] = '\0';
//	loc.count = j;
//	return loc;
//}

////вычислет разность по модулю (из большего модуля меньшее)
// Decimal Decimal::raznost( const Decimal & a, const Decimal & b )const {
//	if( a.isZero() || b.isZero() ) return Decimal();
//	Decimal loc( a.count + 1 );
//	int zanaytyiDesiatock = 0;
//	//проделки с меньшим
//	int i = 0;
//	for( ; i < b.count; ++i ) {
//		int x = CharToInt( a.decm[ i ] );
//		x -= zanaytyiDesiatock; //если занимали десяток вычитаем
//		zanaytyiDesiatock = 0; //и обнуляем занятый десяток
//		int y = CharToInt( b.decm[ i ] );
//		if( x < y ) zanaytyiDesiatock = 1;
//		int z = x + 10 * zanaytyiDesiatock - y;
//		loc.decm[ i ] = IntToUChar( z % 10 );
//	}
//	for( ; i < a.count; ++i ) {
//		if( zanaytyiDesiatock ) {
//			int x = CharToInt( a.decm[ i ] );
//			int z = x - zanaytyiDesiatock;
//			loc.decm[ i ] = IntToUChar( z % 10 );
//			zanaytyiDesiatock = z / 10;
//		} else {
//			loc.decm[ i ] = a.decm[ i ];
//		}
//	}
//	loc.decm[ i ] = '\0';
//	loc.count = i;
//	return loc;
//}

// Decimal Decimal::Mult10()const {
//	if( isZero() ) return Decimal();
//	Decimal loc( count + 2 );
//	loc.negative = negative;
//	loc.decm[ 0 ] = '0';
//	int i = 0;
//	int j = 1;
//	for( ; i < count; ++i, ++j ) {
//		loc.decm[ j ] = decm[ i ];
//	}
//	loc.decm[ j ] = '\0';
//	loc.count = j;
//	loc.Trim();
//	return loc;
//}

// Decimal Decimal::MultPoryadok( std::size_t x )const {
//	if( isZero() ) return Decimal();
//	Decimal loc( count + x + 1 );
//	loc.negative = negative;
//	int i = 0;
//	for( ; i < x; ++i ) loc.decm[ i ] = '0';
//	int j = 0;
//	for( ; j < count; ++j, ++i ) loc.decm[ i ] = decm[ j ];
//	loc.decm[ i ] = '\0';
//	loc.count = i;
//	loc.Trim();
//	return loc;
//}

// Decimal Decimal::MultToNumber( int multiplicator )const {
//	Decimal loc( count + 2 );
//	int dobavok = 0;
//	int i = 0;
//	for( ; i < count; ++i ) {
//		int x = CharToInt( decm[ i ] );
//		int z = x * multiplicator + dobavok;
//		loc.decm[ i ] = IntToUChar( z % 10 );
//		dobavok = z / 10;
//	}
//	loc.decm[ i++ ] = ( dobavok ) ? IntToUChar( dobavok ) : '0';
//	loc.decm[ i ] = '\0';
//	loc.count = i;
//	loc.Trim();
//	return loc;
//}

// Decimal Decimal::MultModules( const Decimal & first, const Decimal & second
// )const { 	if( first.isZero() || second.isZero() ) 		return
// Decimal(); 	Decimal
// lockRes; 	for( int i = 0; i < second.count; ++i ) { 		Decimal mul
// = first.MultToNumber( CharToInt( second.decm[ i ] ) ); 		Decimal
// mulPoryadok = mul.MultPoryadok( i ); 		lockRes += mulPoryadok;
//	}
//	return lockRes;
//}

// Decimal Decimal::ModulDecimal( const Decimal & dec ) const {
//	Decimal loc = dec;
//	loc.negative = false;
//	return loc;
//}

////
// Decimal Decimal::PickOutNum( const Decimal & delimoe, const Decimal & delitel
// )const { 	if( delimoe < delitel ) return Decimal(); 	if( delimoe ==
// delitel )
// return Decimal( delitel ); 	int i = 0; 	std::string t; 	for( ; i <
// delitel.count;
//++i ) { 		t.push_back( delimoe[ i ] );
//	}
//	if( Decimal( t ) < delitel ) {
//		t.push_back( delimoe[ i++ ] );
//	}
//	return Decimal( t );
//}

// int Decimal::NumberToMnogitel( const Decimal & pickNum, const Decimal &
// delitel )const { 	int res = 1; 	if( pickNum.isZero() ) return 0;
// Decimal mul =
// res * delitel; 	while( LessPoModule( mul, pickNum ) ||
// EquivalentPoModule( mul, pickNum ) ) {
//		++res;
//		mul = res * delitel;
//	}
//	return res - 1;
//}

////
// Decimal Decimal::Divide( const Decimal & first, const Decimal & second )const
// {
//	//1. Вычислить подчисло
//	//2. Вычислить цифру множителя
//	//3. Вычесть произведение найденной цифры на делитель скорректированный
//к нужному порядку
//	//4. Делимым становится новое число, делитель тот же
//	if( first < second || first.isZero() ) return Decimal();
//	if( first == second ) return Decimal( "1" );
//	Decimal delimoe = first;
//	std::string res;
//	while( delimoe > second ) {
//		Decimal promeg = first.PickOutNum( delimoe, second ); //находим
//подчисло 		int mnogitel = first.NumberToMnogitel( promeg, second );
////находим цифру результата 		res.push_back( IntToUChar( mnogitel ) );
//int kPoryadkaChisla = delimoe.count - promeg.count; //порядок вычитаемого
//числа, количество символов в самом числе за минусом тех что выбраны в подчисло
//Decimal vychitaemoe = Decimal( std::to_string( mnogitel ) ).MultPoryadok(
// kPoryadkaChisla ) * second; //вычитаемое из основного числа по найденной
// цифре результата с кореекцией на его порядок 		delimoe -= vychitaemoe;
//	}
//	return Decimal( res );
//}

// Decimal Decimal::Divide1( const Decimal & first, const Decimal & second )
// const { 	std::string t; 	Decimal delimoe = first; 	while( delimoe
// > second ) {
//		//Вычислить подчисло старших десятков
//		Decimal subNum = PickOutNum( first, second );
//		//Получить цифру множителя
//		int mnogitel = first.NumberToMnogitel( subNum, second );
//		t.push_back( IntToUChar( mnogitel ) );
//		delimoe = NewDelimoe( delimoe, second, subNum, mnogitel );
//		std::cout << "delimoe = " << delimoe << std::endl;

//	}
//	return Decimal( t );
//}

// Decimal Decimal::Divide2( const Decimal & delimoe, const Decimal & delitel )
// {
//	//Алгоритм состоит из 2 частей

//	if( LessPoModule( delimoe, delitel ) ) return Decimal();
//	//TODO ПРЯМОЕ ПРЕДСТАВЛЕНИЕ
//	std::string result;
//	std::string delimoeStr = delimoe.ModulToString(); //представляем делимое
//в нормльном виде как строку цифр 	std::string delitelStr =
// delitel.ModulToString(); //представляем делитель в нормльном виде как строку
//цифр 	int curIndex = delitelStr.size(); //текущий индекс окончания строки
//делимого 	std::string pickNumber = delimoeStr.substr( 0, curIndex );
////выделяем подчисло из делимого

//	if( LessPoModule( Decimal( pickNumber ), delitel ) ) { //если выделенное
//число меньше делителя то выделяем новое подчисло на 1 цифру больше
//		pickNumber.clear();
//		pickNumber = delimoeStr.substr( 0, ++curIndex );
//	}
//	while( LessPoModule( delitel, Decimal( pickNumber ) ) ||
// EquivalentPoModule( delitel, Decimal( pickNumber ) ) ) { //пока подчисла
//делимого больше делителя
//		//ТОДО должно быть сравнение на больше или равно по модулю
//		int numberDelimiter = NumberToMnogitel( Decimal( pickNumber ),
// delitel );
//		//записать множитель в ответ
//		result.push_back( IntToUChar( numberDelimiter ) );
//		//умножить делитель на найденгное число
//		//и найти разность между полученной от произведения и подчислом
//		Decimal correctionNum = numberDelimiter * ModulDecimal( delitel
//); 		Decimal ostatok = Decimal( pickNumber ) - correctionNum;
//		//Создаем новое делимое
//		std::string newDelimoe;
//		if( !ostatok.isZero() ) {
//			newDelimoe = ostatok.ModulToString();
//		}
//		while( curIndex < delimoe.ModulToString().size() && Decimal(
// newDelimoe ) < ModulDecimal( delitel ) ) {
// newDelimoe.push_back( delimoe[ curIndex++ ] ); 			if(
// LessPoModule( Decimal( newDelimoe ), delitel ) ) { 				result.push_back( '0' );
//			}
//		}
//		pickNumber = newDelimoe;
//	}

//	return Decimal( result );
//}

// Decimal Decimal::NewDelimoe( const Decimal & delimoe, const Decimal &
// delitel, const Decimal & subNumber, int numberAnswer )const {
//	//найти индекс где начинается вторая чать подчисла
//	int index1 = delimoe.count - 1;
//	int index2 = subNumber.count - 1;
//	while( index1 >= 0 && index2 >= 0 && ( delimoe.decm[ index1 ] ==
// subNumber.decm[ index2 ] ) ) {
//		--index1;
//		--index2;
//	}
//	//Вычислние разницы подчисел(без порядков)
//	Decimal x = subNumber - ( delitel * numberAnswer );
//	//слияние для получения нового делителя
//	//количество оставшихся элементов в исходном числе + количество
//полученное в подразнице 	Decimal res( ( index1 + 1 ) + x.count + 1 );
//int i = 0; //контроль индексов нового числа
//	//записываем элементы с большего числа
//	for( int n = 0; n <= index1; ++n ) res.decm[ i++ ] = delimoe.decm[ n ];
//	for( int n = 0; n < x.count; ++n ) res.decm[ i++ ] = x.decm[ n ];
//	res.count = i;
//	res.decm[ i ] = '\0';
//	res.Trim();
//	return res;
//}

// int Decimal::CharToInt( const Type symbolNum ) const {
//	return ( symbolNum - '0' );
//}

// Decimal::Type Decimal::IntToUChar( int num ) const {
//	return ( num + '0' );
//}

////проверяет строку на корректность
// bool Decimal::checkStringForCorrectness( const char * str ) const {
//	int start = ( str[ 0 ] == '-' ) ? 1 : 0;
//	int end = std::strlen( str );
//	for( int i = start; i < end; ++i ) {
//		if( !std::isdigit( str[ i ] ) ) {
//			return false;
//		}
//	}
//	return true;
//}
