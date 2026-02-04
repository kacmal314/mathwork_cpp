#ifndef BINARYTREE_H
#define BINARYTREE_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//
// BinaryTree
//
// # binary tree: parent node, lchild (2i+1), rchild (2i+2)
//
// # used by Expression class

#include <cassert>
#include <vector>

#include "NullNode.h"
#include "Node.h"

namespace MathworkCPP
{
  //-----------------------------------------------------------------------------

  ///
  /// BinaryTree owns all Node* stores in tree
  /// 
  /// * BinaryTree is responsible for deleting them

  class BinaryTree
  {
    std::vector<Node *> tree {};

  public:
    
    // odpali konstruktory domniemane prymitywow
    BinaryTree() = default;

    BinaryTree(BinaryTree const & tree);

    ~BinaryTree();

    BinaryTree& operator=(BinaryTree const & tree);

    BinaryTree operator+(BinaryTree const & tree);

    void insert(Node* node, int i);

    void clear();

    void copy(BinaryTree const & tree);

    void add(Node * node);

  };
}

#endif // BINARYTREE_H