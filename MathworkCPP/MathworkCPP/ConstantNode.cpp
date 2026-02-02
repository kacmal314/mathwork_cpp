#include "ConstantNode.h"

using namespace MathworkCPP;

//*****************************************************************************

Node* ConstantNode::copy()
{

}

//*****************************************************************************

Node* ConstantNode::create()
{
  return new ConstantNode();
}
