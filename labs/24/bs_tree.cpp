/*
 * Name        : bst_tree.h
 * Author      : Martin Hernandez
 * Description : Creating a Binary Search Tree
 */

#include "bs_tree.h"

BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}
BSTree::~BSTree() {
  Clear();
}
bool BSTree::Insert(int valueToInsert) {
  return Insert(valueToInsert, root_);
}
void BSTree::Clear() {
  Clear(root_);
}
unsigned int BSTree::GetSize() const {
  return size_;
}
string BSTree::InOrder() {
  return InOrder(root_);
}
// Private Member Functions
bool BSTree::Insert(int valToInsert, BSTNode*& subRoot) {
  if (subRoot == NULL) {
    BSTNode* newNode = new BSTNode (valToInsert);
    subRoot = newNode;
    size_++;
    return true;
} else if (valToInsert < subRoot->GetContents()) {
    return Insert(valToInsert, subRoot->GetLeftChild());
} else if (valToInsert > subRoot->GetContents()) {
    return Insert(valToInsert, subRoot->GetRightChild());
} else {
    return false;
  }
}
void BSTree::Clear(BSTNode*& iterator) {
  if (iterator != NULL) {
    Clear(iterator->GetLeftChild());
    Clear(iterator->GetRightChild());
    delete iterator;
    size_--;
    iterator = NULL;
  }
}
string BSTree::InOrder(BSTNode* subRoot) {
  stringstream ss;
  if (subRoot != NULL) {
    ss << InOrder(subRoot->GetLeftChild());
    ss << subRoot->GetContents() << " ";
    ss << InOrder(subRoot->GetRightChild());
  }
  return ss.str();
}
