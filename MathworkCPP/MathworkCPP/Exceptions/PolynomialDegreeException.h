#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// PolynomialDegreeException
/// # used by Polynomial

#include "Exception.h"

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class PolynomialDegreeException : public Exception
    {
      public:

        PolynomialDegreeException();
        PolynomialDegreeException(std::string message);


    };

  }

}
