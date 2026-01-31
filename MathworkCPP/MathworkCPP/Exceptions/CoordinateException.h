#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// CoordinateException
/// # used by Point

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class CoordinateException : public Exception
    {
    public:

      CoordinateException() : Exception() {};

      CoordinateException(std::string message) : Exception(message) {};
    };

  }

}
