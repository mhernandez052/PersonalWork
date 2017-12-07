/*
 * Name        : bst_tree.h
 * Author      : Martin Hernandez
 * Description : Creating a Binary Search Tree
 */

#ifndef BST_TREE_H_
#define BST_TREE_H_

#include "bst_node.h"
class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int valueToInsert);
  bool Remove(int valueToRemove);
  int FindMin();
  void Clear();
  unsigned int GetSize() const;
  string InOrder();
 private:
  BSTNode* root_;
  unsigned int size_;
  bool Insert(int valToInsert, BSTNode*& subRoot);
  bool Remove(int valToRemove, BSTNode*& subRoot);
  int FindMin(BSTNode* subRoot) const;
  void Clear(BSTNode*& iterator);
  string InOrder(BSTNode* contents);
};

#endif /*BST_TREE_H_*/
