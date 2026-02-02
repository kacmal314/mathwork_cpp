#ifndef BINARYTREE_H
#define BINARYTREE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// BinaryTree
//
// # binary tree: parent node, lchild (2i+1), rchild (2i+2)
//
// # used by Expression class

#include <vector>

#include "Node.h"

namespace MathworkCPP
{
  class BinaryTree
  {
    std::vector<Node *> tree {};

  public:
    
    // odpali konstruktory domniemane prymitywow
    BinaryTree() = default;

    BinaryTree(BinaryTree const & tree);

    ~BinaryTree();

    BinaryTree operator+(BinaryTree const & tree);

    void add(Node * node);

  };
}

#endif // BINARYTREE_H