/*
 * Name        : bst_node.h
 * Author      : Martin Hernandez
 * Description : Creating a Node for a Binary Search Tree
 */
#ifndef BST_NODE_H_
#define BST_NODE_H_

#include <cstddef>

class BSTNode {
 public:
  BSTNode();
  BSTNode(int contents);
  ~BSTNode();
  void SetContents(int contents);
  int GetContents() const;
  int& GetContents();
  void SetLeftChild(BSTNode* nlChild);
  void SetRightChild(BSTNode* nrChild);
  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();
  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();
 private:
  BSTNode* leftChild_;
  BSTNode* rightChild_;
  int contents_;
};

#endif  /*BST_NODE_H_*/
