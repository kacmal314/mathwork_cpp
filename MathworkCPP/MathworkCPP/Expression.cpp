#include "Expression.h"

using namespace MathworkCPP;

//*****************************************************************************

Expression::Expression(std::string const & expressionAsString)
  : expressionAsString(expressionAsString)
  , expressionAsTree(this->parser.parse(this->expressionAsString)) {}

//*****************************************************************************

double Expression::evaluate(NamedPoint variables)
{
  BinaryTree resolvedTree { this->resolveVariables(this->expressionAsTree) };

  int nodesCount { resolvedTree.countNodes() };

  // https://en.wikipedia.org/wiki/Reverse_Polish_notation

  Node::vectorNodep postfixArray {};

  for (int i = 0; i < nodesCount; i++)
  {
    auto const & nodep { resolvedTree.postorder(i) };

    if (nodep->isFunctional())
    {
      nodep->evaluate(postfixArray);
    }
  }

  Node* first { postfixArray.front() };

  return std::stod(first->copyData());
}
