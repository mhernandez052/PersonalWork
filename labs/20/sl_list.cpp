/*
* Name        : sl_list.cpp
* Author      : Martin Hernandez
* Description : NODE LIST
*/
#include "sl_list.h"
#include <iostream>


SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

SLList::~SLList() {
  Clear();
}

void SLList::Insert(int valueToInsert) {
  if (head_ == NULL || GetHead() >= valueToInsert) {
    InsertHead(valueToInsert);
  } else if (GetTail() <= valueToInsert) {
    InsertTail(valueToInsert);
  } else {
    SLNode* new_Node = new SLNode (valueToInsert);
    SLNode* iterator;
    SLNode* trailer;
    iterator = head_;
    while (iterator->contents() < valueToInsert) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
    new_Node->set_next_node(iterator);
    trailer ->set_next_node(new_Node);
    size_++;
  }
}

bool SLList::RemoveFirstOccurence(int valueToRemove) {
  if (head_ == NULL) {
    return false;
} else if (head_!= NULL) {
    SLNode* iterator;
    SLNode* trailer;
    iterator = head_;
    while (iterator != NULL && iterator->contents() != valueToRemove) {
      trailer = iterator;
      iterator = iterator -> next_node();
    }
    if (iterator == NULL) {
      return false;
  } else if (iterator == head_) {
      RemoveHead();
  } else if (iterator == tail_) {
      RemoveTail();
  } else {
    trailer -> set_next_node(iterator->next_node());
    delete iterator;
    size_--;
    }
  }
  return true;
}

void SLList::InsertHead(int input) {
  SLNode* new_Node = new SLNode(input);
  new_Node-> set_next_node(head_);
  if (head_ == NULL) {
    tail_ = new_Node;
  }
  head_ = new_Node;
  size_++;
}

void SLList::InsertTail(int input) {
  SLNode* new_Node = new SLNode(input);
  if (tail_ != NULL) {
    tail_ -> set_next_node(new_Node);

  } else {
    head_ = new_Node;
  }
  tail_ = new_Node;
  tail_ -> set_next_node(NULL);
  size_++;
}

void SLList::RemoveHead() {
  if (head_ == NULL) {
    tail_ = NULL;
  } else if (head_ != NULL && size_ == 1) {
    delete head_;
    head_ = NULL;
    tail_ = NULL;
    size_--;
  } else {
    SLNode* t =  head_;
    head_ = head_-> next_node();
    delete t;
    size_--;
  }
}

void SLList::RemoveTail() {
  if (tail_ == NULL) {
    head_ = NULL;
  } else if (tail_!= NULL && size_ == 1) {
    delete tail_;
    head_ = NULL;
    tail_ = NULL;
    size_--;
  } else {
    SLNode* iterator;
    iterator = head_;
    while (iterator -> next_node() != NULL) {
      tail_ = iterator;
      iterator = iterator -> next_node();
    }
    delete iterator;
    tail_ -> set_next_node(NULL);
    size_--;
  }
}

int SLList::GetHead() const {
  if (head_ != NULL) {
    return head_ -> contents();
  }
  return 0;
}

int SLList::GetTail() const {
  if (tail_ != NULL) {
    return tail_ -> contents();
  }
  return 0;
}

void SLList::Clear() {
  while (head_ != NULL) {
    SLNode* t = head_;
    head_ = head_ -> next_node();
    delete t;
    t = head_;
    size_--;
  }
  tail_ = NULL;
}

unsigned int SLList::size() const {
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
