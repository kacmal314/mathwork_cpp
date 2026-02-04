#ifndef NULLNODE_H
#define NULLNODE_H


#include "Node.h"

namespace MathworkCPP
{
  class NullNode : public Node
  {

  public:

    using Node::Node;

    // this is nicely called: "virtual copy"
    // its that Abstract Base has virtual function copy()
    // and this allows Derived Class to deep copy elements
    Node* copy() const override;

    Node* create(std::string const & data) override;
  };
}

#endif // NULLNODE_H