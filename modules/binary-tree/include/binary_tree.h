//  Copyright 2023 Semenova Veronika

#ifndef MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
#define MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_

#include <vector>

struct Node {
  int Value;
  Node* Left;
  Node* Right;
  Node* Parent;

  Node(const int V = 0.0, Node* P = nullptr,
  Node* L = nullptr, Node* R = nullptr);
  explicit Node(const Node& n);
};

class BinaryTree {
  Node* root;
  Node* curr;
  Node* FindMin(Node* node) const;
  Node* FindMax(Node* node) const;
  Node* FindNext(Node* node) const;
 public:
  BinaryTree();
  explicit BinaryTree(const int v);
  explicit BinaryTree(const std::vector<int>& v)
      : root(nullptr), curr(nullptr) {
     for (const auto& value : v) {
         Insert(value);
     }
  }

  Node* Find(int k) const;
  void Insert(int k);
  void Delete(int k);

  int GetValue() const;
  void Reset();
  void SetNext();
  bool IsEnd() const;
};

#endif  //  MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
