#include "BinaryTree.h"

using namespace MathworkCPP;

//*****************************************************************************

BinaryTree::BinaryTree(BinaryTree const & tree)
{

  this->copy(tree);
}

//*****************************************************************************

BinaryTree::~BinaryTree()
{
  this->clear();
}

//*****************************************************************************

BinaryTree& BinaryTree::operator=(BinaryTree const & tree)
{
  if (this == &tree)
  {
    return *this;
  }

  this->copy(tree);

  return *this;
}

//*****************************************************************************

BinaryTree BinaryTree::operator+(BinaryTree const & rhs)
{
  BinaryTree lhs { *this };

  for (Node* node : rhs.tree)
  {
    lhs.add(node->copy());
  }

  return lhs;
}

//*****************************************************************************

Node* BinaryTree::postorder(int valueIndex)
{
  return this->postorder(valueIndex, 0);
}

//*****************************************************************************

///
/// valueIndex
/// 
/// * 0: means first postorder value found is returned
/// 
/// * 1: means second postorder value found is returned
/// 
/// * n: means nth postorder value found is returned

Node* BinaryTree::postorder(int valueIndex, int nodeIndex)
{
  static int valueIndex_ {};

  if (nodeIndex >= this->tree.size())
  {
    // tree: out of range

    return nullptr;
  }

  if (nodeIndex == 0)
  {
    // initialization

    valueIndex_ = valueIndex;
  }
  
  Node* l_value {this->postorder(valueIndex, 2 * nodeIndex + 1)}; // L
  Node* r_value {this->postorder(valueIndex, 2 * nodeIndex + 2)}; // R

  if (valueIndex_ == 0)
  {
    return this->tree.at(nodeIndex); // V;
  }

  // searching for 1st element: index 0
  // then: 0 -> -1
  valueIndex_--;

  // both l_value and r_value may be nullptr
  // it is ok: r_value (nullptr) will be returned
  return l_value != nullptr ? l_value : r_value;
}

//*****************************************************************************

void BinaryTree::insert(Node* node, int i)
{
  // 0 - 0 + 1 = 1
  int treeLength { i - static_cast<int>(this->tree.size()) + 1};

  for (int t = 0; t < treeLength; t++)
  {
    this->tree.push_back(new NullNode {});
  }

  //
  // constexpr ::at
  // C++14 removes "const" from "constexpr"
  //
  // przypisanie wskaznika do wektora wskaznikow
  this->tree.at(i) = node;
}

//*****************************************************************************

void BinaryTree::clear()
{
  for (Node* ptr : this->tree)
  {
    delete ptr;
  }

  this->tree.clear();
}

//*****************************************************************************

void BinaryTree::copy(BinaryTree const & tree)
{
  this->clear();

  this->tree.reserve(tree.tree.size());

  for (Node* ptr : tree.tree)
  {
    this->add(ptr->copy());
  }
}

//*****************************************************************************

void BinaryTree::add(Node * node)
{
  ///
  /// https://en.cppreference.com/w/cpp/error/assert.html
  ///
  /// disabling macro-definition: #define NDEBUG
  /// 
  /// * before #include <cassert>
  ///
  /// compilation time assertion
  /// 
  /// * check if evaluates to a "zero" of any type
  /// 
  /// * yes: print to std::error and call std::abort
  /// 
  /// * no: nothing happens
  assert(node != nullptr);

  this->tree.push_back(node);
}