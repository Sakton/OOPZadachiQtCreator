#pragma once
#include <string>
#include <iostream>
//представление числа в массиве с младшего разряда (наоборот)
//числа могут быть отрицательные
//представление внутри класса - строка перевернута
//варианты : + +; - -; + -; - +; |+| > |-|; |+| < |-|

/*
	TODO ИТОГО: 1. Код ужасен
		    2. Требуется рефакторинг
		    3. Много лишних ходов (костылей)
	TODO набраться опыта и исправить!!!
*/

// TODO РЕШЕНО НЕ ВЕРНО В ТУПУЮ

class Decimal {
	using Type = unsigned char;

public:
	explicit Decimal( int sz = 1 );
	explicit Decimal( const char * str );
	explicit Decimal( const std::string & str );
	Decimal( const Decimal & d );
	~Decimal( );
	const Decimal & operator = ( const Decimal & d );
	Decimal & operator += ( const Decimal & other );
	Decimal & operator -= ( const Decimal & other );
	Decimal & operator *= ( const Decimal & other );
	Decimal & operator /= ( const Decimal & other );

	Type & operator [] ( int index );
	const Type & operator [] ( int index ) const;

	friend std::ostream & operator << ( std::ostream & out, const Decimal & d );
	//friend std::istream & operator >> ( std::istream & in, Decimal & d );
	//Поскольку все операторы сравнения являются бинарными и не изменяют свои левые операнды,
	//то выполнять перегрузку следует через дружественные функции.
	friend bool operator <= ( const Decimal & first, const Decimal & second );
	friend bool operator >= ( const Decimal & first, const Decimal & second );
	friend bool operator < ( const Decimal & first, const Decimal & second ); //первое меньше второго?
	friend bool operator > ( const Decimal & first, const Decimal & second );
	friend bool operator == ( const Decimal & first, const Decimal & second );
	friend bool operator != ( const Decimal & first, const Decimal & second );
	friend Decimal operator - ( const Decimal & first, const Decimal & second );
	friend Decimal operator - ( const Decimal & first, int x );
	friend Decimal operator - ( int x, const Decimal & first );
	friend Decimal operator * ( const Decimal & first, const Decimal & second );
	friend Decimal operator * ( const Decimal & first, int x );
	friend Decimal operator * ( int x, const Decimal & first );
	friend Decimal operator / ( const Decimal & first, const Decimal & second );
	friend Decimal operator / ( const Decimal & first, int x );
	friend Decimal operator / ( int x, const Decimal & second );

	size_t Count( )const;
	std::string ToString( )const;

	//private:
public:
	//вспомогательные методы
	std::string ModulToString( )const;


	bool isZero( ) const;
	void Trim( ); //обрезает нули
	Decimal summa( const Decimal & a, const Decimal & b ) const; //вспомогательный метод вычисления суммы, где первый аргумент больше или равен второму
	Decimal raznost( const Decimal & a, const Decimal & b ) const; //вспомогательный метод вычисления суммы, где первый аргумент больше или равен второму
	Decimal Mult10( )const; //умножает на 10
	Decimal MultPoryadok( std::size_t x ) const; //умножает на порядки 1 - 10б 2 - 100
	Decimal MultToNumber(/*const Decimal & mutiplication, */int multiplicator ) const;//умножает на число
	Decimal MultModules( const Decimal & first, const Decimal & second ) const; //Произведение по модулю большее на меньшее first >= second
	Decimal ModulDecimal( const Decimal & dec ) const; //возвращает модуль числа

//	int FindMnogitel( const Decimal & delimoe, const Decimal & delitel )const;
	Decimal PickOutNum( const Decimal & delimoe, const Decimal & delitel )const; //выделяет часть числа для алгоритма деления, (подчисло с старшего разряда)
//  Decimal NewPickOutNum(const Decimal &delimoe, int curIndex, const Decimal &delitel, const Decimal & )const;
	int NumberToMnogitel( const Decimal & pickNum, const Decimal & delitel )const; //возвращает цифру результат деления выделенного числа на множитель [0 - 9]
	Decimal Divide( const Decimal & first, const Decimal & second ) const; // Делит числа беззнаково (плохо делит числа с нулями)
	Decimal Divide1( const Decimal & first, const Decimal & second ) const;// Делит любые числа беззнаково
	Decimal Divide2( const Decimal & delimoe, const Decimal & delitel ); //еще попытка
	Decimal NewDelimoe( const Decimal & delimoe, const Decimal & delitel, const Decimal & subNumber, int numberAnswer ) const;

	friend bool LessPoModule( const Decimal & first, const Decimal & second ); //проверяет что модуль первого аргумента меньше второго
	friend bool EquivalentPoModule( const Decimal & first, const Decimal & second );
	int CharToInt( const Type symbolNum ) const;
	Type IntToUChar( int num ) const;
	bool checkStringForCorrectness( const char * str ) const; //проверить строку на корректность

	//bool IsOkString( const std::string & str );
	//std::string ToNumber()const;
	//void InitNewStr( const std::string & str );
	//void ToZero();

private:
	static const int MAX_SIZE = 100; //хранит максимальный размер числа
	Type * decm; //указатель на массив гдето в куче
	size_t count; //количество элементов фактическое
	bool negative{ false }; //признак отрицательного числа (число отрицательное ? да, нет)
};

