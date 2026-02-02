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

    virtual Node* copy() = 0;

    virtual Node* create() = 0;
  };
}

#endif // NODE_H