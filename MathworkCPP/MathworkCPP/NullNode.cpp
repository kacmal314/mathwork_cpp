#include "NullNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node* NullNode::create()
{
  return new NullNode();
}
