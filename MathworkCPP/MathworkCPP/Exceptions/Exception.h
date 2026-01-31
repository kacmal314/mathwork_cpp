#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Exception
/// 
/// # aggregate class

#include <string>

namespace MathworkCPP
{
  namespace Exceptions
  {
    class Exception
    {

      protected:

        std::string message;

      public:

        Exception() = default;
        Exception(std::string message) : message(message) {};

        //*****************************************************************************

        inline std::string getMessage()
        {
          return this->message;
        }
    };

  }

}
