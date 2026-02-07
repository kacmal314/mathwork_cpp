#ifndef EXPRESSION_H
#define EXPRESSION_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///
/// Expression
/// 
/// # model multivariable mathematical expression

#include <string>

#include "Enumerated/NodeType.h"
#include "VariableNode.h"
#include "Node.h"
#include "ExpressionParser.h"
#include "BinaryTree.h"
#include "NamedPoint.h"

namespace MathworkCPP
{
  class Expression
  {

  protected:

    ExpressionParser parser {};

    std::string expressionAsString {};

    BinaryTree expressionAsTree {};

  public:

    Expression() = default;
    Expression(std::string const & expressionAsString);

    virtual double evaluate(NamedPoint variables = {});

  protected:

    BinaryTree resolveVariables(NamedPoint const & variables);
  };

}

#endif // EXPRESSION_H