#ifndef OPERATORNODE_H
#define OPERATORNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class OperatorNode : public Node
  {

  public:

    Node* create() override;
  };
}

#endif // OPERATORNODE_H