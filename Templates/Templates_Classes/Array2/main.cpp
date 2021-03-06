#include <iostream>
#include <stdexcept>

#include "array2.h"

int main( ) {
  try {
    int64_t test_arr[] { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 };
    Array2< int64_t, 10 > arrInt( test_arr, test_arr + 10 );
    std::cout << arrInt << std::endl;
    std::cin >> arrInt;
    std::cout << arrInt << std::endl;
    //    Array2< int, 10 > arrInt1( test_arr, test_arr + 10 );
    //    std::cout << arrInt1 << std::endl;
    //    Array2< int, 10 > arrInt3 = arrInt + arrInt1;
    //    std::cout << "arrInt3 = " << arrInt3 << std::endl;
    //    Array2< int, 10 > arrInt4 = arrInt - arrInt1;
    //    std::cout << "arrInt4 = " << arrInt4 << std::endl;
    //    Array2< int, 10 > arrInt5 = arrInt * arrInt1;
    //    std::cout << "arrInt5 = " << arrInt5 << std::endl;
    //    Array2< int, 10 > arrInt6 = arrInt / arrInt1;
    //    std::cout << "arrInt6 = " << arrInt6 << std::endl;

    //  double test_arr_double[] { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 };
    //  Array2< double, 10 > doubleArr( test_arr_double, test_arr_double + 10 );
    //  std::cout << doubleArr << std::endl;

  } catch ( std::bad_alloc &e ) {
    std::cerr << "BAD_ALLOCATED" << e.what( ) << std::endl;
  } catch ( std::range_error &e ) {
    std::cerr << "RANGE" << e.what( ) << std::endl;
  } catch ( std::runtime_error &e ) {
    std::cerr << "RANGE" << e.what( ) << std::endl;
  } catch ( std::exception &e ) {
    std::cerr << "EXCEPT" << e.what( ) << std::endl;
  } catch ( ... ) {
    std::cerr << "UNEXPECTED" << std::endl;
  }

  return 0;
}
