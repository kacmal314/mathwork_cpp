#ifndef MATRIX_H
#define MATRIX_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// Matrix
//
// # feature test
//
// # test matrix class functions

#include "./UnitTest.h"
#include "../Filesystem.h"
#include "../Matrix.h"
#include "../Exceptions/SquareMatrixException.h"
#include "../Exceptions/ZeroDeterminantException.h"

namespace MathworkCPP
{
  namespace Testing
  {
    class MatrixTest : public UnitTest
    {

    public:

      void test() override;

    };
  }
}

#endif // MATRIX_H