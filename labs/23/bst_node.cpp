/*
 * Name        : bst_node.cpp
 * Author      : Martin Hernandez
 * Description : Creating a Node for a Binary Search Tree
 */
#include "bst_node.h"

BSTNode::BSTNode() {
  leftChild_ = NULL;
  rightChild_ = NULL;
  contents_ = 0;
}
BSTNode::BSTNode(int contents) {
  leftChild_ = NULL;
  rightChild_ = NULL;
  contents_ = contents;
}
BSTNode::~BSTNode() {
  rightChild_ = NULL;
  leftChild_ = NULL;
}
void BSTNode::SetContents(int contents) {
  contents_= contents;
}
int BSTNode::GetContents() const {
  return contents_;
}
int& BSTNode::GetContents() {
  return contents_;
}
void BSTNode::SetLeftChild(BSTNode* nlChild) {
  leftChild_ = nlChild;
}
void BSTNode::SetRightChild(BSTNode* nrChild) {
  rightChild_ = nrChild;
}
BSTNode* BSTNode::GetLeftChild() const {
  return leftChild_;
}
BSTNode*& BSTNode::GetLeftChild() {
  return leftChild_;
}
BSTNode* BSTNode::GetRightChild() const {
  return rightChild_;
}
BSTNode*& BSTNode::GetRightChild() {
  return rightChild_;
}
