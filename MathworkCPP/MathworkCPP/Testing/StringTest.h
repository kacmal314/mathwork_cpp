#ifndef STRINGTEST_H
#define STRINGTEST_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// StringTest
//
// # class test

#include "./UnitTest.h"
#include "../Extended/String.h"

namespace MathworkCPP
{
  namespace Testing
  {
    class StringTest : public UnitTest
    {

    public:

      void test() override;

    };
  }
}

#endif // STRINGTEST_H