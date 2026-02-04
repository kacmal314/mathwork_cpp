#include "OperatorNode.h"

using namespace MathworkCPP;

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
