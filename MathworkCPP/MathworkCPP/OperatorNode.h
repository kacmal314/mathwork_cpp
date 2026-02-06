#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Node.h"

namespace MathworkCPP
{
  class OperatorNode : public Node
  {

  protected:

    NodeTypeType code { static_cast<NodeTypeType>(Enumerated::NodeType::Operator) };

    int argumentCount { 2 };

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;
  };
}

#endif // OPERATORNODE_H