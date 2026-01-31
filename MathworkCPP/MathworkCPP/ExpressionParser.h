#ifndef EXPRESSIONPARSER_h
#define EXPRESSIONPARSER_h

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionParser
/// 
/// # define expression parsing

#include <vector>
#include <string>

#include "Extended/String.h"
#include "Helper/declarations.h"
#include "Enumerated/ExpressionType.h"
#include "ExpressionValidator.h"
#include "BinaryTree.h"

namespace MathworkCPP
{

  //-----------------------------------------------------------------------------

  //
  // parsing is not: removing whitespace
  // parsing is not: preprocessing

  class ExpressionParser
  {
    vector2String symbolArrays
    {
      // inverse precedence
      /* 0: */ {"+", "-"},
      /* 1: */ {"*", "/"},
      /* 2: */ {"^"},
      /* 3: */ {"sin", "log"}
    };

  public:

    BinaryTree parse(const std::string & expressionAsString);

    bool is(Enumerated::ExpressionType type);

    bool isOnly(Enumerated::ExpressionType type);

  private:

    std::string validate(const std::string & expressionAsString);

    bool isConstant();
  };
}

#endif // EXPRESSIONPARSER_h
