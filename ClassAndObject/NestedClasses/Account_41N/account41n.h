#ifndef ACCOUNT41N_H
#define ACCOUNT41N_H
#include <string>

//TODO Nestead Classes пропуск этих заданий
//пример готов

class Account41N {

    class Money24B {
    public:
	void Init( int32_t rb, int16_t cp );
	void Display( ) const;
	void Read( );
	std::string ToString( ) const;

	Money24B Add( const Money24B & b );
	Money24B Sub( const Money24B & b );
	Money24B Mul( double x );
	double Div( const Money24B & b );
	Money24B Div( double x );
	bool Eq( const Money24B & b );
	bool NotEqu( const Money24B & b );
	bool Less( const Money24B & b );
	bool LessOrEq( const Money24B & b );
	bool Greater( const Money24B & b );
	bool GreaterOrEq( const Money24B & b );

	int32_t GetRub( ) const;
	uint8_t GetCop( ) const;

    private:
	int32_t rub { 0 };
	uint8_t cop { 0 };
    };

public:
    void Init( std::string name, std::string acc, double proc, double summ );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    std::string name( ) const;
    void setName( const std::string & name );
    void AddSumm( double sm );
    void SubSumm( double sm );
    void AddProcent( );
    double ToDollar( double cours );
    double ToEuro( double cours );
    std::string ToChislitelnoe( );

private:
    std::string Sotni( int chislo );
    std::string Desyatki( int chislo );
    std::string Edinitsy( int chislo );
    std::string ParseSotni( int chislo );
    std::string ParseThousand( int chislo );
    std::string ParseMillion( int chislo );

private:
    std::string name_;
    std::string accountNum_;
    double procent_;
    //double summa_;
    Money24B summa_;
};

#endif // ACCOUNT41N_H
