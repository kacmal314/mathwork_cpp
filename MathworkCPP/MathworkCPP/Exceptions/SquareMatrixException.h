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

        SquareMatrixException();
        SquareMatrixException(std::string message);


    };

  }

}
