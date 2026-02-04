#ifndef NODE_H
#define NODE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// Node
//
// used by: BinaryTree (Expression -> 1 Binary Tree -> N Nodes)

#include <string>

namespace MathworkCPP
{
  class Node
  {

  protected:

    std::string data {};

  public:

    Node() = default;

    Node(std::string const & data) : data(data) {};

    virtual Node* copy() const = 0;

    virtual Node* create(std::string const & data) = 0;
  };
}

#endif // NODE_H