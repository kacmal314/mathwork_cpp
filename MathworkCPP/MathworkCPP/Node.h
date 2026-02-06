#ifndef NODE_H
#define NODE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// Node
//
// used by: BinaryTree (Expression -> 1 Binary Tree -> N Nodes)

#include <functional> // std::function
#include <typeinfo>
#include <string>

#include "Helper/declarations.h"
#include "Enumerated/NodeType.h"

namespace MathworkCPP
{
  class NullNode;
  class ConstantNode;
  class VariableNode;
  class OperatorNode;
  class FunctionNode;

  class Node
  {

  public:

    using vectorNodep = std::vector<Node*>;

  protected:

    using evaluationLookups = std::function<double(vectorDouble)>;

    static const evaluationLookups lookups;

    std::string data {};

    NodeTypeType code {};

    int argumentCount {};

  public:

    Node() {};

    //*****************************************************************************

    Node(std::string const & data) : data(data) {};

    vectorNodep shiftArguments(vectorNodep & postfixArray);

    ///
    /// cannot: define "inline"
    /// 
    /// * problem: circular dependency
    
    bool isNull() const;

    bool isOperator() const;

    bool isFunction() const;

    ///
    /// is dependent on argument(s)
    
    bool isFunctional() const;

    virtual Node* copy() const = 0;

    virtual Node* create(std::string const & data) = 0;

    //*****************************************************************************

    virtual void evaluate(vectorNodep & postfixArray) { return; };
  };
}

#endif // NODE_H