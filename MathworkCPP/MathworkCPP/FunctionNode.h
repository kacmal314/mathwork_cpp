#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <cmath>

#include "Node.h"
#include "Helper/definitions.h"

namespace MathworkCPP
{
  class FunctionNode : public Node
  {

  protected:

    NodeTypeType code { static_cast<NodeTypeType>(Enumerated::NodeType::Function) };

    int argumentCount { 1 };

  public:

    using Node::Node;

    Node* copy() const override;

    Node* create(std::string const & data) override;

    void evaluate(Node::vectorNodep & postfixArray) override;

  private:

    //*****************************************************************************

    inline double sin_(double degree)
    {
      return sin(degree * PI / 180.0);
    }
    
    //*****************************************************************************

    inline double log_(double x)
    {
      return log(x);
    }

  };

}

#endif // FUNCTIONNODE_H