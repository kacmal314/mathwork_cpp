#ifndef EXPRESSION_H
#define EXPRESSION_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Expression
/// 
/// # model multivariable mathematical expression

#include <string>

#include "ExpressionParser.h"
#include "BinaryTree.h"
#include "NamedPoint.h"

namespace MathworkCPP
{
  class Expression
  {

  private:

    ExpressionParser parser {};

    std::string expressionAsString {};

    BinaryTree expressionAsTree {};

  public:

    Expression() = default;
    Expression(std::string const & expressionAsString);

    virtual double evaluate(NamedPoint variables);

  };

}

#endif // EXPRESSION_H