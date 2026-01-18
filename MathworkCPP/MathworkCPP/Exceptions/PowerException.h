#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// PowerException
/// # used by Powers

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class PowerException : public Exception
    {
      public:

        PowerException();
        PowerException(std::string message);


    };

  }

}
