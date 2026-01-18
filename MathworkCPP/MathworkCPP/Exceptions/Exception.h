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
      public:

        Exception();
        Exception(std::string message);

        static void                        IsErrorRaised(bool isError);
        static bool                        IsErrorRaised();
        static void                        IsWarningRaised(bool isWarning);
        static bool                        IsWarningRaised();

        std::string                        Message();

      protected:

        std::string                 message;

      private:

        static bool                 isErrorRaised;
        static bool                 isWarningRaised;


    };

  }

}
