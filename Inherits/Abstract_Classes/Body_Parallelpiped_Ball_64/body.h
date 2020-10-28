#ifndef BODY_H
#define BODY_H


class Body
{
 public:
  virtual ~Body( ) {}
  virtual double Area( ) const = 0;
  virtual double Volume( ) const = 0;
};

#endif // BODY_H
