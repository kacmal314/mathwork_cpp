#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ZeroDeterminantException
/// # used by Matrix
/// # used when singular Matrix is unexpected

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class ZeroDeterminantException : public Exception
    {
      public:

        ZeroDeterminantException() : Exception("Matrix's Determinant cannot be zero") {};
        ZeroDeterminantException(std::string message) : Exception(message) {};


    };

  }

}
