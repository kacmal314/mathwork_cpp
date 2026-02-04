#include "NullNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node* NullNode::copy() const
{
  // member data initialized with proper type of zero
  Node *node { new NullNode { *this } };

  return node;
}

//*****************************************************************************

Node* NullNode::create(std::string const & data)
{
  return new NullNode(data);
}
