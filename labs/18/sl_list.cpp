/*
* Name        : sl_list.cpp
* Author      : Martin Hernandez
* Description : NODE LIST
*/
#include "sl_list.h"

SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}

SLList::~SLList() {
  Clear();
}

void SLList::InsertHead(int input) {
  SLNode* new_Node = new SLNode(input);
  if (head_ != NULL) {
    new_Node->set_next_node(head_);
  }
    head_ = new_Node;
    size_++;
}

void SLList::RemoveHead() {
  if (head_ != NULL) {
    SLNode* t =  head_;
    head_ = head_-> next_node();
    delete t;
    size_--;
  }
}

void SLList::Clear() {
  while (head_ != NULL) {
    SLNode* t = head_;
    head_ = head_->next_node();
    delete t;
    t = head_;
    size_--;
  }
}

unsigned int SLList::size() {
  return size_;
}

string SLList::ToString() const {
  SLNode* iterator;
  stringstream ss;
  iterator = head_;
  while (iterator != NULL) {
    if (iterator->next_node() == NULL) {
      ss << iterator->contents();
      break;
    }
    ss << iterator->contents() << ", ";
    iterator = iterator->next_node();
  }
  return ss.str();
}
