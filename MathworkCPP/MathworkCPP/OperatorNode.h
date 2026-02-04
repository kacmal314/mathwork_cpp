#ifndef OPERATORNODE_H
#define OPERATORNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class OperatorNode : public Node
  {

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;
  };
}

#endif // OPERATORNODE_H