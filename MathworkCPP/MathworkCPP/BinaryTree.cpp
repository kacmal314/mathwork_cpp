#include "BinaryTree.h"

using namespace MathworkCPP;

//*****************************************************************************

BinaryTree::BinaryTree(BinaryTree const & tree)
{
  // to nie jest potrzebne
  // nie piszemy przeciez operatora=
  // if (this == &tree)

  this->~BinaryTree();

  this->tree.reserve(tree.tree.size());

  // referencja do wskaznika jest chyba niepotrzebna
  // wskazniki wykorzystujemy zeby optymalizowac prace na duzych obiektach
  // wspazniki nie sa duzymy obiektami: przykladowo: int* to 4 B
  for (auto const /* & */ ptr : tree.tree)
  {
    this->tree.push_back(& (*ptr).copy());
  }
}

//*****************************************************************************

BinaryTree::~BinaryTree()
{
  for (auto ptr : this->tree)
  {
    delete ptr;
  }
}

//*****************************************************************************

BinaryTree BinaryTree::operator+(BinaryTree const & tree)
{
  BinaryTree newTree { *this };

  for (auto const & node : tree.tree)
  {
    newTree.tree.push_back(node);
  }

  return newTree;
}

//*****************************************************************************

void BinaryTree::add(Node * node)
{
  this->tree.push_back(node);
}