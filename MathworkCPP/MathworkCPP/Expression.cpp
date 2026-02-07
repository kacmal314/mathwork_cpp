#include "Expression.h"

using namespace MathworkCPP;

//*****************************************************************************

Expression::Expression(std::string const & expressionAsString)
  : expressionAsString(expressionAsString)
  , expressionAsTree(this->parser.parse(this->expressionAsString)) {}

//*****************************************************************************

BinaryTree Expression::resolveVariables(NamedPoint const & variables)
{
  BinaryTree tree { this->expressionAsTree };

  int nodesCount { tree.countNodes() };

  for (int i = 0; i < nodesCount; i++)
  {
    Node* nodep { tree.postorder(i) };

    if (nodep->isVariable())
    {
      std::string variable { nodep->copyData() };

      std::string constant = std::to_string(variables[variable]);

      tree[tree.find(nodep)] = new ConstantNode { constant };

    }
  }

  return tree;
}

//*****************************************************************************

double Expression::evaluate(NamedPoint variables)
{
  BinaryTree resolvedTree { this->resolveVariables(variables) };

  int nodesCount { resolvedTree.countNodes() };

  // https://en.wikipedia.org/wiki/Reverse_Polish_notation

  Node::vectorNodep postfixArray {};

  for (int i = 0; i < nodesCount; i++)
  {
    auto const & nodep { resolvedTree.postorder(i) };
    
    if (nodep->isFunctional())
    {
      nodep->evaluate(postfixArray);
      continue;
    }

    postfixArray.push_back(nodep);
  }

  Node* first { postfixArray.front() };

  return std::stod(first->copyData());
}
