#ifndef NODERULE_H
#define NODERULE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// NodeRule
//
// # ExpressionParser

#include <regex>
#include <string>

#include "Exceptions/ParserException.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------

  //
  // a class - has to be defined inside - namespace - otherwise it is "incomplete"

  class NodeRule
  {

  protected:

    std::string rule {};
    std::string errorMessage {};

  public:

    // = default: element-po-elemencie
    NodeRule(std::string rule, std::string errorMessage)
      : rule(rule)
      , errorMessage(errorMessage) {}

    void validate(const std::string & expressionAsString);

    // returning a copy: getter has to return a copy
    inline std::string getErrorMessage()
    {
      return this->errorMessage;
    }
  };
}

#endif // NODERULE_H
