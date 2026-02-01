#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include <string>

#include "Node.h"

namespace MathworkCPP
{
  class VariableNode : public Node
  {
  public:

    Node* create() override;
  };
}

#endif // VARIABLENODE_H