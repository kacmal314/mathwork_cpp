#include "FunctionNode.h"

using namespace MathworkCPP;

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
