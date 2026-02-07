#ifndef NODE_H
#define NODE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// Node
//
// used by: BinaryTree (Expression -> 1 Binary Tree -> N Nodes)

#include <map>
#include <functional> // std::function
#include <typeinfo>
#include <string>

#include "Exceptions/NodeNotEvaluable.h"
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

    using evaluationLookup = std::function<double(vectorDouble)>;

    using mapStringLookup = std::map<std::string, evaluationLookup>;

    ///
    /// interface member data
    /// 
    /// * static member belong to Base Class
    /// 
    /// * shadow it in Derived Class
    /// 
    /// no memory address
    /// 
    /// * unless shadowed in Derived Class and defined in .cpp

    static const mapStringLookup lookups;

    std::string data {};

    NodeTypeType code {};

    int argumentCount {};

  public:

    //*****************************************************************************

    Node() : Node("") {};

    //*****************************************************************************

    Node(std::string const & data) : data(data) {};

    vectorNodep shiftArguments(vectorNodep & postfixArray);

    ///
    /// cannot: define "inline"
    /// 
    /// * problem: circular dependency
    
    bool isNull() const;

    ///
    /// const this
    /// 
    /// * "I promise I keep this pointer const"
    /// 
    /// * NOT: "I only accept const pointers"

    bool isVariable() const;

    bool isOperator() const;

    bool isFunction() const;

    ///
    /// is dependent on argument(s)
    
    bool isFunctional() const;

    virtual Node* copy() const = 0;

    virtual Node* create(std::string const & data) = 0;

    //*****************************************************************************

    virtual double evaluateFor(vectorDouble arguments) const
    {
      throw Exceptions::NodeNotEvaluable("this node cannot be simplified");
    };

    //*****************************************************************************

    virtual void evaluate(vectorNodep & postfixArray) { return; };

    //*****************************************************************************

    std::string copyData() const { return this->data; }

    //*****************************************************************************

    NodeTypeType copyCode() const { return this->code; }
  };
}

#endif // NODE_H