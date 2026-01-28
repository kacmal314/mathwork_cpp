#pragma once


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// ExpressionParser
/// 
/// # define expression parsing

#include <string>

#include "Extended/String.h"
#include "BinaryTree.h"
#include "Expression.h"

namespace MathworkCPP
{
  class ExpressionParser
  {

  public:

    BinaryTree parse(const std::string & expressionAsString);

  private:

    void validate(const std::string & expressionAsString);
    std::string preprocess(const std::string & expressionAsString);
  };
}