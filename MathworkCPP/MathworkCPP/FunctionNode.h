#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class FunctionNode : public Node
  {

  public:

    Node* create() override;
  };
}

#endif // FUNCTIONNODE_H