#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class FunctionNode : public Node
  {

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;
  };
}

#endif // FUNCTIONNODE_H