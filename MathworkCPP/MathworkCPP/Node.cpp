#include "Node.h"
#include "NullNode.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "OperatorNode.h"
#include "FunctionNode.h"

using namespace MathworkCPP;

const Node::mapStringLookup Node::lookups {

  {"+", [](vectorDouble operands) -> double { return operands[0] + operands[1]; } },

  {"-", [](vectorDouble operands) -> double { return operands[0] - operands[1]; } },

  {"*", [](vectorDouble operands) -> double { return operands[0] * operands[1]; } },

  {"/", [](vectorDouble operands) -> double { return operands[0] / operands[1]; } },

  {"^", [](vectorDouble operands) -> double { return std::pow(operands[0], operands[1]); } },

  {"sind", [](vectorDouble operands) -> double { return sin(operands[0] * PI / 180.0); } },

  {"log", [](vectorDouble operands) -> double { return log(operands[0]); } }

};

//*****************************************************************************

double Node::evaluateFor(vectorDouble arguments) const
{
  try
  {
    Node::evaluationLookup symbolLookup {
      // lookups is static Node::member
      Node::lookups.at(this->data) };

    return symbolLookup(arguments);
  }
  catch (std::out_of_range ex)
  {
    throw std::out_of_range("cannot lookup this symbol: " + this->data);
  }
}

//*****************************************************************************

void Node::evaluate(vectorNodep & postfixArray)
{
  // zdejmujemy argumenty ...

  vectorNodep arguments { this->shiftArguments(postfixArray) };

  vectorDouble argumentsAsDouble { Convert::toVectorDouble(arguments) };

  double value { this->evaluateFor(argumentsAsDouble) };

  Node* constantNode { new ConstantNode(std::to_string(value)) };

  // ... wkladamy wynik :)

  postfixArray.push_back(constantNode);
}

//*****************************************************************************

Node::vectorNodep Node::shiftArguments(vectorNodep & postfixArray)
{
  auto iterator { postfixArray.end() - this->argumentCount };

  auto values { std::vector(iterator, postfixArray.end()) };

  postfixArray.erase(iterator, postfixArray.end());

  return values;
}

//*****************************************************************************

bool Node::isNull() const
{
  return typeid(*this) == typeid(NullNode {});
}

//*****************************************************************************

bool Node::isVariable() const
{
  return typeid(*this) == typeid(VariableNode {});
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