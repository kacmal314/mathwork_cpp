#ifndef NODERULE_H
#define NODERULE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// NodeRule
//
// # ExpressionParser

#include <string>

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------

  //
  // a class - has to be defined inside - namespace - otherwise it is "incomplete"

  class NodeRule
  {
  public:

    NodeRule() = default; // element-po-elemencie

    virtual bool validate(const std::string & expressionAsString) = 0;
  };
}

#endif // NODERULE_H
