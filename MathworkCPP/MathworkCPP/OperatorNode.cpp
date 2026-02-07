
#include "OperatorNode.h"

using namespace MathworkCPP;

const OperatorNode::mapStringLookup OperatorNode::lookups {

  {"+", [](vectorDouble operands) -> double { return operands[0] + operands[1]; } },

  {"-", [](vectorDouble operands) -> double { return operands[0] - operands[1]; } },

  {"*", [](vectorDouble operands) -> double { return operands[0] * operands[1]; } },

  {"/", [](vectorDouble operands) -> double { return operands[0] / operands[1]; } },

  {"^", [](vectorDouble operands) -> double { return std::pow(operands[0], operands[1]); } },

};

//*****************************************************************************

double OperatorNode::evaluateFor(vectorDouble arguments) const
{
  OperatorNode::evaluationLookup symbolLookup {
    // lookups is static OperatorNode::
    OperatorNode::lookups.at(this->data) };

  return symbolLookup(arguments);
}

//*****************************************************************************

void OperatorNode::evaluate(vectorNodep & postfixArray)
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

Node* OperatorNode::copy() const
{
  Node *node { new OperatorNode(*this) };

  return node;
}

//*****************************************************************************

Node* OperatorNode::create(std::string const & data)
{
  return new OperatorNode(data);
}
