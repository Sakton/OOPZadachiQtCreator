#ifndef GOODS36B_H
#define GOODS36B_H
#include <string>

class Goods36B {
 public:
  Goods36B( const std::string& name = "", const std::string& date = "",
            int32_t id = 0, double price = 0.0, int32_t count = 0 );

  friend void Display( const Goods36B& gd );
  friend std::string ToString( const Goods36B& gd );

  friend double Cost( const Goods36B& gd );

  friend double Price( const Goods36B& gd );
  friend void SetPrice( Goods36B& gd, double price );

  friend int32_t GetCount( const Goods36B& gd );
  friend void SetCount( Goods36B& gd, const int32_t& value );

  friend void AddCount( Goods36B& gd, int32_t count );
  friend void SubCount( Goods36B& gd, int32_t count );

 private:
  std::string name_;
  std::string date_;
  int32_t id_nakladnoy_;
  double price_;
  int32_t count_;
};

#endif // GOODS36B_H
