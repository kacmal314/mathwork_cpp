#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class ConstantNode : public Node
  {

  public:

    Node* create() override;
  };
}

#endif // CONSTANTNODE_H