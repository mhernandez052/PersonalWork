/*
* Name        : dl_list.h
* Author      : Martin Hernandez
* Description : Doubly linked list
*/
#include "dl_node.h"

DLNode::DLNode() {
  contents_ = 0;
  previous_Node_ = NULL;
  next_Node_ = NULL;
}
DLNode::~DLNode() {
}
void DLNode::SetContents(int contents) {
  contents_ = contents;
}
void DLNode::SetNext(DLNode* next_Node) {
  next_Node_ = next_Node;
}
void DLNode::SetPrevious(DLNode* previous_Node) {
  previous_Node_ = previous_Node;
}
int DLNode::GetContents() const {
  return contents_;
}
DLNode* DLNode::GetNext() const {
  return next_Node_;
}
DLNode* DLNode::GetPrevious() const {
  return previous_Node_;
}

