#pragma once
#include <string>

//ВАЖНО!!! НИКАКИХ ТЕРМИНАЛЬНЫХ НУЛЕЙ НЕ НАДО, ТАК КАК ПРЕДСТАВЛЕНИЕ - МАССИВ СИВОЛОВ, А НЕ С-СТРОКА


class Hex {

private:
	using TypeHexArray = unsigned char;
	using IntegralType = long long;
	static const int MAX_SIZE;
	TypeHexArray * m_hx{ nullptr }; //ЭТО НЕ СТРОКА, А МАССИВ СИМВОЛОВ!!! ТЕМИНАТОР НЕ НАДО!!!
	std::size_t m_count{ 0 };
	static const TypeHexArray symbolsHex[  ];

public:
	struct HexPair {
		TypeHexArray first;
		TypeHexArray second;
	};

	Hex( );
	explicit Hex( const std::string & s );
	explicit Hex( IntegralType decNum );
	Hex( const Hex & other );
	Hex & operator = ( const Hex & other );
	Hex( Hex && other )noexcept;
	Hex & operator = ( Hex && other )noexcept;
	~Hex( );

	Hex & operator += ( const Hex & other );
	Hex & operator -= ( const Hex & other );
	Hex & operator *= ( const Hex & other );
	Hex & operator /= ( const Hex & other );

	TypeHexArray & operator[]( int index );
	const TypeHexArray & operator[]( int index )const;


	friend bool operator < ( const Hex & first, const Hex & second );
	friend bool operator > ( const Hex & first, const Hex & second );
	friend bool operator >= ( const Hex & first, const Hex & second );
	friend bool operator <= ( const Hex & first, const Hex & second );
	friend bool operator == ( const Hex & first, const Hex & second );
	friend bool operator != ( const Hex & first, const Hex & second );

	friend Hex operator + ( const Hex & first, const Hex & second );
	friend Hex operator - ( const Hex & first, const Hex & second );
	friend Hex operator * ( const Hex & first, const Hex & second );
	friend Hex operator / ( const Hex & first, const Hex & second );

	std::string ToString( ) const;
	std::size_t Count( )const; //везвращает порядок числа

	//вспомогательный методы
public: //для теста
	//private:
	static std::string & ReverseString( std::string & s );
	std::string IntegralType2Hex( IntegralType num )const; //интегральный тип в строку
	TypeHexArray NumToChar( int n )const; //число в символ
	int CharToNum( char ch )const; //символ в число
	bool IsOkString( const std::string & s ); //проверяет строку на число
	HexPair ToHexMaxInt255( int f )const; //перевод из инта в пару до 255
	void TrimZero( );
	//для сложения
	Hex AddictionNumbers( const Hex & first, const Hex & second )const; //складывает 2 числа
	HexPair Sum2Num( TypeHexArray first, TypeHexArray second )const; //сумма 2 цифр в пару
	HexPair Sum3Num( TypeHexArray first, TypeHexArray second, TypeHexArray third )const; //сумма 3 цифр в пару
	//для вычитания
	Hex SubtractNumbers( const Hex & first, const Hex & second )const; //вычитает 2 числа
	HexPair Sub2Num( TypeHexArray first, TypeHexArray second )const; //вычитает цифры
	//умножение
	HexPair Mult2Numbers( TypeHexArray a, TypeHexArray b )const; //перемножает 2 символа HEX(0 - F)
	Hex MultToOneNumber( const Hex & a, TypeHexArray symbol )const; //умножает на символ HEX(0 - F)
	Hex Mult10( const Hex & a )const; //дописывает 0 у конец
	Hex Mult10xX( const Hex & a, int n )const; //Дописывает n нулей
	Hex Mult( const Hex & a, const Hex & b )const; //произведение
	//деление
	Hex PickOutPodchislo( const Hex & delimoe, const Hex & delitel )const; //Выделяет подчисло
	TypeHexArray SearchOneNum( const Hex & delimoe, const Hex & delitel )const; //Ищет цифру частного
	Hex Divide( const Hex & delimoe, const Hex & delitel )const; //само деление
};

