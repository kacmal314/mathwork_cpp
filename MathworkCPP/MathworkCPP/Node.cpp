#include "Node.h"
#include "NullNode.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "OperatorNode.h"
#include "FunctionNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node::vectorNodep Node::shiftArguments(vectorNodep & postfixArray)
{
  auto iterator { postfixArray.end() - this->argumentCount };

  auto values { std::vector(iterator, postfixArray.end()) };

  postfixArray.erase(iterator);

  return values;
}

//*****************************************************************************

bool Node::isNull() const
{
  return typeid(*this) == typeid(NullNode {});
}

//*****************************************************************************

bool Node::isOperator() const
{
  return typeid(*this) == typeid(OperatorNode {});
}

//*****************************************************************************

bool Node::isFunction() const
{
  return typeid(*this) == typeid(FunctionNode {});
}

//*****************************************************************************

bool Node::isFunctional() const
{
  using Enumerated::NodeType;

  return this->code & (NodeTypeType(NodeType::Operator) | NodeTypeType(NodeType::Function));
}