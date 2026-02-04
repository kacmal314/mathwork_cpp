#include "ConstantNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node* ConstantNode::copy() const
{
  Node *node { new ConstantNode(*this) };

  return node;
}

//*****************************************************************************

Node* ConstantNode::create(std::string const & data)
{
  return new ConstantNode(data);
}
