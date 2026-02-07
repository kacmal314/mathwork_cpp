#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include <cmath>

#include "Convert.h"
#include "ConstantNode.h"
#include "Node.h"

namespace MathworkCPP
{
  class OperatorNode : public Node
  {

  public:

    using Node::Node;

    //*****************************************************************************

    OperatorNode(std::string const & data) : Node(data)
    {
      this->code = static_cast<NodeTypeType>(Enumerated::NodeType::Operator);

      this->argumentCount = 2;
    };

    Node* copy() const override;

    Node* create(std::string const & data) override;
  };
}

#endif // OPERATORNODE_H