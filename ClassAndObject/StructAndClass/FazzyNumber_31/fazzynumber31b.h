#ifndef FAZZYNUMBER31B_H
#define FAZZYNUMBER31B_H
#include <string>

//TODO пока пропуск, оно бестолковое

class FazzyNumber31B {
public:
    void Init( double e1, double x, double e2 );
    //void Read(  );
    void Display( ) const;
    std::string ToString( ) const;

    FazzyNumber31B Add( const FazzyNumber31B & oth ) const;
    FazzyNumber31B Sub( const FazzyNumber31B & oth ) const;
    FazzyNumber31B Mul( const FazzyNumber31B & oth ) const;
    FazzyNumber31B Div( const FazzyNumber31B & oth ) const;
    FazzyNumber31B Rev( const FazzyNumber31B & oth ) const;

public:
    double e1_;
    double x_;
    double e2_;
};

#endif // FAZZYNUMBER31B_H
