#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include <string>

#include "Node.h"

namespace MathworkCPP
{
  class VariableNode : public Node
  {

  public:

    // this adds visibility of Base::Base constructors

    using Node::Node;

    //*****************************************************************************

    VariableNode(std::string const & data) : Node(data)
    {
      this->code = static_cast<NodeTypeType>(Enumerated::NodeType::Variable);
    };

    Node* copy() const override;

    Node* create(std::string const & data) override;

  };
}

#endif // VARIABLENODE_H