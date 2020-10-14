#include "dictionary.h"
#include <algorithm>
#include <iostream>

Dictionary::Dictionary(const std::wstring& name)
    : nameDict_ { name }
    , dict_ { nullptr }
    , capacity_ { 0 }
    , size_ { 0 }
{
}

Dictionary::Dictionary( const Dictionary & other )
{
    MyTypePtr t( new WordCard[ other.Size( ) ] );
    for ( int i = 0; i < other.Size( ); ++i ) {
        t[ i ] = other.dict_[ i ];
    }
    size_ = other.Size( );
    nameDict_ = other.nameDict( );
    capacity_ = other.Size( );
    dict_ = std::move( t );
}

Dictionary & Dictionary::operator=( const Dictionary & other )
{
    if ( this != &other ) {
        MyTypePtr t( new WordCard[ other.Size( ) ] );
        for ( int i = 0; i < other.Size( ); ++i ) {
            t[ i ] = other.dict_[ i ];
        }
        size_ = other.Size( );
        nameDict_ = other.nameDict( );
        capacity_ = other.capacity_;
        dict_ = std::move( t );
    }
    return *this;
}

Dictionary::Dictionary( Dictionary && other ) noexcept
{
    dict_ = std::move( other.dict_ );
    size_ = other.size_;
    capacity_ = other.capacity_;
    nameDict_ = other.nameDict_;

    other.size_ = 0;
    other.capacity_ = 0;
    nameDict_ = L"";
}

Dictionary & Dictionary::operator=( Dictionary && other ) noexcept
{
    if ( this != &other ) {
        dict_ = std::move( other.dict_ );
        size_ = other.size_;
        capacity_ = other.capacity_;
        nameDict_ = other.nameDict_;

        other.size_ = 0;
        other.capacity_ = 0;
        nameDict_ = L"";
    }
    return *this;
}

void Dictionary::AddWordcard(const std::wstring& w, const std::wstring& p)
{
    //1.в карточках есть поле актуал вот вперва ищем неактуальную и в этом же проходе надо искать
    //надо ли вообще вставлять

    WordCard t( w, p );

    int indexAdd = size_;
    bool flag = true;
    for ( int i = 0; i < size_; ++i ) {
        if ( dict_[ i ] == t ) {
            flag = false;
            break;
        }
        if ( !dict_[ i ].aktual ) {
            indexAdd = i;
        }
    }

    if ( flag ) {
        if ( ( indexAdd + 1 ) >= capacity_ ) {
            resize( capacity_ * 2 + 1 );
        }
        dict_[ indexAdd ] = WordCard( w, p );
        dict_[ indexAdd ].aktual = true;
        if ( indexAdd == size_ )
            ++size_;
    }
}

void Dictionary::Display()
{
    for (int i = 0; i < size_; ++i) {
        if (dict_[i].aktual) {
            dict_[i].Display();
        }
    }
}

void Dictionary::Remove( const std::wstring & w, const std::wstring & p )
{
    WordCard t( w, p );
    int ind = find( t );
    if ( ind >= 0 ) {
        dict_[ ind ].aktual = false;
    }
}

std::wstring Dictionary::nameDict() const
{
    return nameDict_;
}

void Dictionary::setNameDict(const std::wstring& nameDict)
{
    nameDict_ = nameDict;
}

Dictionary Dictionary::Intersection( const Dictionary & other )
{
    Dictionary res( L"result dictionary" );

    for ( int i = 0; i < Size( ); ++i ) {
        if ( other.findBinary( dict_[ i ].word ) != -1 ) {
            res.AddWordcard( dict_[ i ].word, dict_[ i ].perevod );
        }
    }
    return res;
}

Dictionary Dictionary::operator+( const Dictionary & other )
{
    Dictionary res = *this;

    for ( int i = 0; i < other.Size( ); ++i ) {
        if ( res.findBinary( other.dict_[ i ].word ) == -1 )
            res.AddWordcard( other.dict_[ i ].word, other.dict_[ i ].perevod );
    }
    return res;
}

Dictionary Dictionary::operator-( const Dictionary & other )
{
    Dictionary res = *this;

    for ( int i = 0; i < other.Size( ); ++i ) {
        if ( res.findBinary( other.dict_[ i ].word ) != -1 )
            res.Remove( other.dict_[ i ].word, other.dict_[ i ].perevod );
    }

    return res;
}

size_t Dictionary::find( const Dictionary::WordCard & other ) const
{
    // тут тонкое место... так как структура массив, то в данном случае лучше однопроходный алгоритм O( N ), т.к.для
    // бинарного алгоритма нужна постоянная сортировка тогда O( logN ) * O( N * N )
    // ( N * N - сортировка вставкой тут ), тогда
    // O( N * N * logN ), что > O( N )
    for ( int i = 0; i < size_; ++i ) {
        if ( dict_[ i ] == other && dict_[ i ].aktual ) {
            return i;
        }
    }
    return -1;
}

int Dictionary::findBinary( const std::wstring & other ) const
{
    int l = 0;
    int r = size_ - 1;

    while ( l <= r ) {
        int m = ( l + r ) / 2;
        if ( dict_[ m ].word == other )
            return m;
        if ( dict_[ m ].word < other ) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

size_t Dictionary::findAdd( ) const
{
    for ( int i = 0; i < size_; ++i ) {
        if ( !dict_[ i ].aktual ) {
            return i;
        }
    }
    return size_;
}

void Dictionary::sortLess( )
{
    for (int i = 1; i < size_; ++i) {
        WordCard t = dict_[i];
        int j = i - 1;
        for (; j >= 0 && t.word <= dict_[j].word; j--) {
            dict_[j + 1] = dict_[j];
        }
        dict_[j + 1] = t;
    }
}

void Dictionary::resize(int capacity)
{
    MyTypePtr t(new WordCard[capacity]);
    int j = 0;
    for (int i = 0; i < size_; ++i, ++j) {
        if (dict_[i].aktual) {
            t[j] = dict_[i];
        }
    }
    dict_ = std::move(t);
    size_ = j;
    capacity_ = capacity;
}

int32_t Dictionary::Size( ) const
{
    return size_;
}

Dictionary::WordCard::WordCard( )
    : aktual { false }
{
}

Dictionary::WordCard::WordCard(const std::wstring& w, const std::wstring& p)
{
    word = w;
    perevod = p;
    aktual = true;
}

void Dictionary::WordCard::Display()
{
    std::wcout << word << L" => " << perevod << std::endl;
}
