#ifndef INVERSEMATRIXTEST_H
#define INVERSEMATRIXTEST_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// InverseMatrixTest
//
// # unit test
//
// # test calculating matrix inverse

#include "./UnitTest.h"
#include "../Matrix.h"
#include "../Exceptions/SquareMatrixException.h"
#include "../Exceptions/ZeroDeterminantException.h"

namespace MathworkCPP
{
  namespace Testing
  {
    class InverseMatrixTest : public UnitTest
    {

    public:

      void test() override;

    };
  }
}

#endif // INVERSEMATRIXTEST_H