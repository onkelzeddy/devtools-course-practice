//  Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>
#include <vector>

#include "include/binary_tree.h"


Node::Node(const int V, Node* P,
  Node* L, Node* R) : Value(V), Left(L),
  Right(R), Parent(P) {}
Node::Node(const Node& n) :
  Value(n.Value), Left(nullptr),
  Right(nullptr), Parent(nullptr) {}


BinaryTree::BinaryTree():root(nullptr), curr(nullptr) {}
BinaryTree::BinaryTree(int v) {
  root = new Node(v);
  curr = nullptr;
}
Node* BinaryTree::FindMin(Node* node) const {
  Node* tmp = node;
  while (tmp->Left !=
      nullptr) {
  tmp = tmp->Left;
}
  return tmp;
}
void BinaryTree::Reset() {
  if (root != nullptr) {
    curr = FindMin(root);
  } else {
  throw std::string("Сan't resert");
  }
}
int BinaryTree::GetValue() const {
  if (curr != nullptr) {
    return curr->Value;
  } else {
    throw std::string("Сan't set next");
  }
}
void BinaryTree::Insert(int v) {
  if (Find(v) != nullptr) {
    throw std::string("Сan't extract a value");
  }
  if (root == nullptr)  {
    root = new Node(v);
    return;
  }
  Node* x = root, * y;
  while (x != nullptr) {
    y = x;
    if (v < x->Value) {
    x = x->Left;
  } else {
    x = x->Right;
  }
  }
  if (v < y->Value) {
    y->Left = new Node(v, y);
  } else {
    y->Right = new Node(v, y);
  }
}
Node* BinaryTree::Find(int k)  const {
  Node* tmp = root;
  while ((tmp != nullptr) && (tmp->Value != k)) {
    if (k < tmp->Value) {
    tmp = tmp->Left;
  } else {
    tmp = tmp->Right;
  }
  }
  return tmp;
}
Node* BinaryTree::FindNext(Node* node) const {
  Node* res = nullptr;
  if (node->Right != nullptr) {
    res = FindMin(node->Right);
  return res;
  }
  res = node->Parent;
  Node* tmp = node;
  while ((res != nullptr) && (tmp == res->Right)) {
    tmp = res;
  res = res->Parent;
  }
  return res;
}
void BinaryTree::SetNext() {
  if (root != nullptr) {
    curr = FindNext(curr);
  }
}
void BinaryTree::Delete(int k) {
  Node* z = Find(k);
  if (Find(k) == nullptr) {
      throw std::string("\tThe item being deleted is not in the tree\n");
  }
  Node* y = nullptr, * x = nullptr;
  if ((z->Left != nullptr) && (z->Right != nullptr)) {
    y = FindNext(z);
  } else {
    y = z;
  }
  if (y->Left != nullptr) {
    x = y->Left;
  } else {
    x = y->Right;
  }
  if (x != nullptr) {
    x->Parent = y->Parent;
  }
  if (y->Parent != nullptr) {
    if (y == y->Parent->Left) {
      y->Parent->Left = x;
    } else {
      y->Parent->Right = x;
    }
  }
  if (y != z) {
    z->Value = y->Value;
  }
  if (z == root && z->Left == nullptr && z->Right == nullptr) {
    root = nullptr;
  }
}
Node* BinaryTree::FindMax(Node* node)  const {
  Node* tmp = node;
  while (tmp->Right != nullptr) {
    tmp = tmp->Right;
  }
  return tmp;
}
bool BinaryTree::IsEnd() const {
  return curr->Value == FindMax(root)->Value;
}
