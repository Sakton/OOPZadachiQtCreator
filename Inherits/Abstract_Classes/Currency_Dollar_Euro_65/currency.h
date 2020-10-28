#ifndef CURRENCY_H
#define CURRENCY_H


class Currency
{
 public:
  virtual ~Currency( ) {}
  virtual double change( ) const = 0;
  virtual void display( ) const = 0;
};

#endif // CURRENCY_H
