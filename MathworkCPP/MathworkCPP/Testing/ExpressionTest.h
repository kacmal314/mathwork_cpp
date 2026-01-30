#ifndef EXPRESSIONTEST_H
#define EXPRESSIONTEST_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// ExpressionTest
//
// # feature test
//
// # testing mathematical expressions

#include "./UnitTest.h"
#include "../Expression.h"

namespace MathworkCPP
{
  namespace Testing
  {
    class ExpressionTest : public UnitTest
    {

    public:

      void test() override;

    };
  }
}

#endif // EXPRESSIONTEST_H