#ifndef OBJECT_H
#define OBJECT_H

class Object {
 public:
  Object( );
  ~Object( );
  static int getCOUNT( );

 private:
  static int COUNT;
};

#endif // OBJECT_H
