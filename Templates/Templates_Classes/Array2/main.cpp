#include <iostream>

#include "array2.h"

int main()
{
  int test_arr[] { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 };
  Array2< int, 10 > arrInt( test_arr, test_arr + 10 );
  std::cout << arrInt << std::endl;
  std::cin >> arrInt;
  std::cout << arrInt << std::endl;
  //  Array2< int, 10 > arrInt1( test_arr, test_arr + 10 );
  //  Array2< int, 10 > arrInt3 = arrInt + arrInt1;
  //  std::cout << "arrInt3 = " << arrInt3 << std::endl;
  //  Array2< int, 10 > arrInt4 = arrInt - arrInt1;
  //  std::cout << "arrInt4 = " << arrInt4 << std::endl;
  //  Array2< int, 10 > arrInt5 = arrInt * arrInt1;
  //  std::cout << "arrInt5 = " << arrInt5 << std::endl;
  //  Array2< int, 10 > arrInt6 = arrInt / arrInt1;
  //  std::cout << "arrInt6 = " << arrInt6 << std::endl;

  //  double test_arr_double[] { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 };
  //  Array2< double, 10 > doubleArr( test_arr_double, test_arr_double + 10 );
  //  std::cout << doubleArr << std::endl;

  return 0;
}
