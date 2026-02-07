#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "Node.h"
#include "Helper/definitions.h"

namespace MathworkCPP
{
  class FunctionNode : public Node
  {

  public:

    using Node::Node;

    //*****************************************************************************

    FunctionNode(std::string const & data) : Node(data)
    {
      this->code = static_cast<NodeTypeType>(Enumerated::NodeType::Function);

      this->argumentCount = 1;
    };

    Node* copy() const override;

    ///
    /// factory function

    Node* create(std::string const & data) override;

  };

}

#endif // FUNCTIONNODE_H