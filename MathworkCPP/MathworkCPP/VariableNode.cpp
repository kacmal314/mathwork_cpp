#include "VariableNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node* VariableNode::copy() const
{
  Node *node { new VariableNode(*this) };

  return node;
}

//*****************************************************************************

Node* VariableNode::create(std::string const & data)
{
  return new VariableNode(data);
}
