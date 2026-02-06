#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "Node.h"

namespace MathworkCPP
{
  class ConstantNode : public Node
  {

  protected:

    NodeTypeType code { static_cast<NodeTypeType>(Enumerated::NodeType::Constant) };

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;

  };
}

#endif // CONSTANTNODE_H