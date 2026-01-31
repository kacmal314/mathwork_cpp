#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// SquareMatrixException
/// # used by Matrix
/// # used when square Matrix was expected

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class SquareMatrixException : public Exception
    {
      public:

        SquareMatrixException() : Exception("# of Columns and # of Rows have to be equal") {};
        SquareMatrixException(std::string message) : Exception(message) {};


    };

  }

}
