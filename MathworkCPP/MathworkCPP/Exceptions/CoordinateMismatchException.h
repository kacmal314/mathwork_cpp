#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// CoordinateMismatchException
/// # used by Point
/// # used by Polynomial

#include "CoordinateException.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class CoordinateMismatchException : public CoordinateException
    {
      public:

        CoordinateMismatchException();
        CoordinateMismatchException(std::string message);

      private:

        void                          act();
    };

  }

}
