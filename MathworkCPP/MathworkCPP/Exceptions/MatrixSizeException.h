#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// MatrixSizeException
/// # used by Matrix

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class MatrixSizeException : public Exception
    {
      public:

        MatrixSizeException();
        MatrixSizeException(std::string message);


    };

  }

}
