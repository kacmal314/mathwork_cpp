#include "BinaryTree.h"

using namespace MathworkCPP;

//*****************************************************************************

BinaryTree::~BinaryTree()
{
  for (auto ptr : this->tree)
  {
    delete ptr;
  }
}

//*****************************************************************************

void BinaryTree::add(Node * node)
{
  this->tree.push_back(node);
}