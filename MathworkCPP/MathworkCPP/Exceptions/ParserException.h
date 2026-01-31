#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ParserException
/// 
/// # function parsing exception information
/// 
/// # exception recovery functions

#include "Exception.h"

namespace MathworkCPP
{
  namespace Exceptions
  {
    class ParserException : public Exceptions::Exception
    {
    public:

      ParserException() : Exception("parser exception") {};
      ParserException(std::string message) : Exception(message) {};
    };
  }
}

#endif // PARSEREXCEPTION_H
