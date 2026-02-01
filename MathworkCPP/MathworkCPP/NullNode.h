#ifndef NULLNODE_H
#define NULLNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class NullNode : public Node
  {

  public:

    Node* create() override;
  };
}

#endif // NULLNODE_H