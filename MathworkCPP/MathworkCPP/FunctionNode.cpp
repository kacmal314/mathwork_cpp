#include "FunctionNode.h"

using namespace MathworkCPP;

//*****************************************************************************

void FunctionNode::evaluate(Node::vectorNodep & postfixArray)
{
  Node::vectorNodep arguments { this->shiftArguments(postfixArray) };

  //Node* value { this->lookup(this->data) };

  //postfixArray.push_back(value);
}

//*****************************************************************************

Node* FunctionNode::copy() const
{
  Node *node { new FunctionNode(*this) };

  return node;
}

//*****************************************************************************

Node* FunctionNode::create(std::string const & data)
{
  return new FunctionNode(data);
}
