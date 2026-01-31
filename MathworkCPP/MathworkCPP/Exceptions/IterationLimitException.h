#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// IterationLimitException
/// 
/// # used by HookeJeeves
/// 
/// # used by iterative algorithms

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class IterationLimitException : public Exception
    {
      public:

        IterationLimitException()
          : Exception("Iterations Limit reached, precision compromised") {};

        IterationLimitException(std::string message)
          : Exception(message) {};


    };

  }

}
