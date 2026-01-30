#ifndef EXPRESSIONPARSER_h
#define EXPRESSIONPARSER_h

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionParser
/// 
/// # define expression parsing

#include <vector>
#include <string>

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
