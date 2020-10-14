#pragma once
#include <cstdint>
#include <string>
#include <iostream>

//индексы 0 и 1 - копейки
//рубли начинаются с индекса 2
//ограничения: передаваемый формат RRRRRR....RR.(,)CC;

class Money4 {
public:
	explicit Money4( const std::string & s = { "0,00" } );
private:
	explicit Money4( int16_t sz );
	explicit Money4( int16_t arr[], int sz, int begin, int end );
public:
	~Money4( );
	//explicit Money4( const int16_t arr[] );
	Money4( const Money4 & rhs );
	Money4( Money4 && rhs )noexcept;
	Money4 & operator=( const Money4 & rhs );
	Money4 & operator = ( Money4 && rhs )noexcept;

	int16_t & operator[]( int index );

	Money4 & operator += ( const Money4 & rhs );
	Money4 & operator -= ( const Money4 & rhs );
	Money4 & operator *= ( const Money4 & rhs );
	Money4 & operator /= ( const Money4 & rhs );

	friend Money4 operator + ( const Money4 & lhs, const Money4 & rhs );
	friend Money4 operator - ( const Money4 & lhs, const Money4 & rhs );
	friend Money4 operator * ( const Money4 & lhs, const Money4 & rhs );
	friend Money4 operator / ( const Money4 & lhs, const Money4 & rhs );

	friend bool operator < ( const Money4 & lhs, const Money4 & rhs );
	friend bool operator > ( const Money4 & lhs, const Money4 & rhs );
	friend bool operator <= ( const Money4 & lhs, const Money4 & rhs );
	friend bool operator >= ( const Money4 & lhs, const Money4 & rhs );
	friend bool operator == ( const Money4 & lhs, const Money4 & rhs );
	friend bool operator != ( const Money4 & lhs, const Money4 & rhs );

	std::string ToString( )const;
	int16_t Size( )const;
	friend std::ostream & operator << ( std::ostream & out, const Money4 & rhs );
	friend std::istream & operator >> ( std::ostream & out, Money4 & rhs );
	void TrimZero( );
	void DeleteNegative( );

	//private:
	void NormaliseString( std::string & s );
	bool IsValidString( const std::string & s )const;
	bool IsValidSize( int sz )const;
	void copyArr( int16_t to[ ], int16_t from[ ], int sz );
	Money4 Modul( const Money4 & lhs )const;
	Money4 addingModules( const Money4 & lhs, const Money4 & rhs )const; //сложение чисел по модулю (первый аргумент >= второго)
	Money4 substractionModules( const Money4 & lhs, const Money4 & rhs )const;//вычитание чисел по модулю (первый аргумент >= второго)
	//Money4 MultOneNumber( const Money4 & umnogaemoe, int16_t mnogitel, int16_t poryadok )const;
	Money4 MultOneNumber( const Money4 & umnogaemoe, int16_t mnogitel )const;
	Money4 MultModules( const Money4 & umnogaemoe, const Money4 & mnogitel )const;
	Money4 MiltTo_10x( const Money4 & umnogaemoe, int16_t poryadok )const;
	//так как при умножении чисел с знаками после запятой, общее количество знаков после запятой в результате складывается
	//функция обраотки 2 последних знаков запятой, так как при умножении получим 4 знака после запятой
	void PopravkaMult( ); //отбрасывает 2 символа последние
	Money4 DivideModules( const Money4 & delimoe, const Money4 & delitel );

private:
	static const int MAX_LEN = 100;
	int16_t * m_arr;
	int16_t m_size;
	bool m_negative;
};

