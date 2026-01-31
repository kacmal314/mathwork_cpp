#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// SolvingFunctionException 
/// # used by Polynomial
/// # used when unable to return function value

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class SolvingFunctionException : public Exception
    {
      public:

        SolvingFunctionException() : Exception("Cannot solve function") {};
        SolvingFunctionException(std::string message) : Exception(message) {};


    };

  }

}
