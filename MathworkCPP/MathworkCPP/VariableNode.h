#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include <string>

#include "Node.h"

namespace MathworkCPP
{
  class VariableNode : public Node
  {

  protected:

    NodeTypeType code { static_cast<NodeTypeType>(Enumerated::NodeType::Variable) };

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;

  };
}

#endif // VARIABLENODE_H