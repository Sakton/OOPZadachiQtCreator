#ifndef GOODS49_H
#define GOODS49_H
#include "date29b.h"
#include <string>

class Goods49 {
public:
    void Init( const std::string & name = "",
	const std::string & date = "",
	int32_t id = 0,
	double price = 0.0,
	int32_t count = 0 );

    void Display( ) const;
    std::string ToString( ) const;
    //void Read(  );

    double Cost( ) const;

    double Price( ) const;
    void SetPrice( double price );

    int32_t GetCount( ) const;
    void SetCount( const int32_t & value );

    int CountDays( const std::string & day ) const;

    void AddCount( int32_t count );
    void SubCount( int32_t count );

private:
    std::string name_;
    //std::string date_;
    Date29B date_;
    int32_t id_nakladnoy_;
    double price_;
    int32_t count_;
};

#endif // GOODS49_H
