#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <memory>
#include <string>
#include <vector>

// FIXME operator[]() ??
// TODO РЕШЕНО НЕ ВЕРНО В ТУПУЮ

class Dictionary {

    struct WordCard {
        std::wstring word;
        std::wstring perevod;
        bool aktual;

        WordCard( );
        WordCard( const std::wstring & w, const std::wstring & p );

        void Display( );

        friend bool operator==( const WordCard & a, const WordCard & b )
        {
            return ( a.word == b.word && a.perevod == b.perevod );
        }
    };

    using MyTypePtr = std::unique_ptr< WordCard[] >;

public:
    explicit Dictionary( const std::wstring & name );
    Dictionary( const Dictionary & other );
    Dictionary & operator=( const Dictionary & other );
    Dictionary( Dictionary && other ) noexcept;
    Dictionary & operator=( Dictionary && other ) noexcept;

    void AddWordcard( const std::wstring & w, const std::wstring & p );
    void Display( );
    void Remove( const std::wstring & w, const std::wstring & p );

    std::wstring nameDict( ) const;
    void setNameDict( const std::wstring & nameDict );

    Dictionary Intersection( const Dictionary & other ); //пересечение
    Dictionary operator+( const Dictionary & other );
    Dictionary operator-( const Dictionary & other );

    void sortLess( );

    int32_t Size( ) const;

private:
    std::size_t find( const WordCard & other ) const;
    int findBinary( const std::wstring & other ) const;
    std::size_t findAdd( ) const;
    void resize( int capacity );

private:
    std::wstring nameDict_;
    //std::vector< WordCard > dict_;
    MyTypePtr dict_;
    int32_t capacity_;
    int32_t size_;
};

#endif // DICTIONARY_H
