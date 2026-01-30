
#include <iostream>

#include "MathworkCPP.h"

using namespace MathworkCPP;

int main()
{
  //test(new Testing::InverseMatrixTest {});
  test(new Testing::MatrixTest {});
  test(new Testing::FileNameTest {});
  test(new Testing::RandomIntTest {});
  test(new Testing::StringTest {});
  test(new Testing::ExpressionTest {});

  return 0;
}