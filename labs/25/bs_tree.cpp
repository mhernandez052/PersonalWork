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
bool BSTree::Remove(int valueToRemove) {
  return Remove(valueToRemove, root_);
}
int BSTree::FindMin() {
  if (root_ != NULL) {
    return FindMin(root_);
  }
return 0;
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
bool BSTree::Remove(int valToRemove, BSTNode*& subRoot) {
  if (subRoot == NULL) {
    return false;
  } else if (valToRemove < subRoot->GetContents()) {
    return Remove(valToRemove, subRoot->GetLeftChild());
  } else if (valToRemove > subRoot->GetContents()) {
    return Remove(valToRemove, subRoot->GetRightChild());
  } else {
    if (subRoot->GetLeftChild() == NULL && subRoot->GetRightChild() == NULL) {
     delete subRoot;
     subRoot = NULL;
     size_--;
     return true;
    } else if (subRoot->GetLeftChild() != NULL && subRoot->GetRightChild() == NULL) {
    BSTNode* temp =subRoot;
    subRoot = temp->GetLeftChild(); 
    delete temp;
    size_--;
    return true;
    } else if (subRoot->GetRightChild() != NULL && subRoot->GetLeftChild() == NULL) {
    BSTNode* temp =subRoot;
    subRoot = temp->GetRightChild(); 
    delete temp;
    size_--;
    return true;
    } else {
    int min = FindMin(subRoot->GetRightChild());
    subRoot->SetContents(min);
    return Remove(min, subRoot->GetRightChild());
    }
  }
}
int BSTree::FindMin(BSTNode* subRoot) const {
  if (subRoot->GetLeftChild()!= NULL) {
    return FindMin(subRoot->GetLeftChild());
} else { 
    return subRoot->GetContents(); 
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
