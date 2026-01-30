#ifndef FILENAMETEST_H
#define FILENAMETEST_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// FileNameTest
//
// # unit test
//
// # test file name reading

#include "./UnitTest.h"
#include "../Filesystem.h"

namespace MathworkCPP
{
  namespace Testing
  {
    class FileNameTest : public UnitTest
    {

    public:

      void test() override;

    };
  }
}

#endif // FILENAMETEST_H