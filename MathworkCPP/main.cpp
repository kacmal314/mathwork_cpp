
#include <iostream>

#include "MathworkCPP.h"

using namespace MathworkCPP;


int main()
{

  UnitTest::testInverseMatrix();

  std::cout << UnitTest::testFilesystemClass();

  std::cout << UnitTest::testStringClass();

  std::cout << UnitTest::testRandomClass();

  std::cout << UnitTest::testMatrixClass();

  return 0;
}