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

        CoordinateException();
        CoordinateException(std::string message);


    };

  }

}
