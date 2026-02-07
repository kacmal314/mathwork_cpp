#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "Node.h"

namespace MathworkCPP
{
  class ConstantNode : public Node
  {

  public:

    using Node::Node;

    //*****************************************************************************

    ConstantNode(std::string const & data) : Node(data)
    {
      this->code = static_cast<NodeTypeType>(Enumerated::NodeType::Constant);
    };

    Node* copy() const override;

    Node* create(std::string const & data) override;

  };
}

#endif // CONSTANTNODE_H