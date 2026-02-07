#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionValidator
/// 
/// works on: Polynomial
/// works on: ExpressionType

#include <string>

#include "NodeRule.h"
#include "Extended/String.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------

  //
  // # removing whitespace
  //
  // # normalizing unary operators (--x) -> (+x)
  //
  // # validating characters (invalid are: $ @)
  //
  // # rewriting implicit multiplication (2x) -> (2 * x)
  //
  // # replacing constants (pi) -> (3.141592)

  class ExpressionValidator
  {

    std::vector<NodeRule> rules
    {
      // ^ : special regex character, even in capturing group
      NodeRule("(\\+|-|\\*|\\/|\\^){2,}", "invalid operator syntax: double operator"),
      NodeRule("\\.\\.", "invalid floating point symbol: double dot .."),
      NodeRule(",", "invalid floating point symbol: comma,"),
      NodeRule("[@$#&]", "invalid variable name: invalid chars @$#&"),
      NodeRule("sind[^(]", "invalid sine degree function syntax: try sind(...)"),
      NodeRule("log[^(]", "invalid log function syntax: try log(...)")
    };

  public:

    std::string validate(const std::string & expressionAsString);

  private:

    std::string preprocess(const std::string & expressionAsString);
  };

}
