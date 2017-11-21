/*
* Name        : dl_list.cpp
* Author      : Martin Hernandez
* Description : Doubly linked list
*/
#include "dl_list.h"

DLList::DLList() {
  head_= NULL;
  tail_ = NULL;
  currentSize_ = 0;
}

DLList::~DLList() {
  Clear();
}

unsigned int DLList::GetSize() const {
  return currentSize_;
}

void DLList::PushFront(int contents) {
  DLNode* new_Node = new DLNode();
  new_Node->SetContents(contents);
  if (head_ == NULL) {
    new_Node->SetNext(NULL);
    tail_ = new_Node;
  } else {
    new_Node->SetNext(head_);
    head_->SetPrevious(new_Node);
  }
  head_ = new_Node;
  currentSize_++;
}

void DLList::PushBack(int contents) {
  DLNode* new_Node = new DLNode();
  new_Node->SetContents(contents);
  if (tail_ == NULL) {
    new_Node->SetPrevious(NULL);
    head_ = new_Node;
  } else {
    new_Node->SetPrevious(tail_);
    tail_->SetNext(new_Node);
  }
  new_Node->SetNext(NULL);
  tail_ = new_Node;
  currentSize_++;
}

int DLList::GetFront() const {
  if (head_== NULL) {
    std::cerr << "List Empty";
    return 0;
} else {
    return head_->GetContents();
  }
}

int DLList::GetBack() const {
  if (tail_== NULL) {
    std::cerr << "List Empty";
    return 0;
} else {
    return tail_->GetContents();
  }
}

void DLList::PopFront() {
  if (head_== NULL) {
    tail_ = NULL;
    std::cerr << "List Empty";
} else if (head_ != NULL && currentSize_ == 1) {
    delete head_;
    head_ = NULL;
    tail_ = NULL;
    currentSize_--;
} else {
    DLNode* t;
    t = head_;
    head_ = head_->GetNext();
    delete t;
    head_->SetPrevious(NULL);
    currentSize_--;
  }
}

void DLList::PopBack() {
  if (tail_== NULL) {
    head_ = NULL;
    std::cerr << "List Empty";
} else if (tail_ != NULL && currentSize_ == 1) {
    tail_->SetNext(NULL);
    tail_->SetPrevious(NULL);
    delete tail_;
    head_ = NULL;
    tail_ = NULL;
    currentSize_--;
  } else {
    DLNode* t;
    t = tail_;
    tail_= tail_->GetPrevious();
    delete t;
    tail_->SetNext(NULL);
    currentSize_--;
  }
}

void DLList::RemoveFirst(int valueToRemove) {
  if (head_ == NULL) {
    std::cerr << "Not Found";
} else if (head_!= NULL) {
    DLNode* iterator;
    DLNode* trailer;
    iterator = head_;
    while (iterator != NULL && iterator->GetContents() != valueToRemove) {
      trailer = iterator;
      iterator = iterator->GetNext();
    }
    if (iterator == NULL) {
       std::cerr << "Not Found";
  } else if (iterator == head_) {
      PopFront();
  } else if (iterator == tail_) {
      PopBack();
  } else {
    trailer->SetNext(iterator->GetNext());
    DLNode* temp = iterator->GetNext();
    temp->SetPrevious(trailer);
    delete iterator;
    currentSize_--;
    }
  }
}

void DLList::RemoveAll(int valuesToRemove) {
  if (Exists(valuesToRemove) == false) {
    std::cerr<< "Not Found";
} else {
    DLNode* iterator;
    DLNode* tempToDelete;
    DLNode* trainWreck;
    iterator = head_;
    while (iterator!= NULL) {
      if(iterator->GetContents() == valuesToRemove) {
        if (iterator == head_) {
         PopFront(); 
        } else if (iterator == tail_) {
          PopBack();
        } else {
          tempToDelete = iterator;
          trainWreck = tempToDelete-> GetNext();
          iterator = iterator->GetPrevious();
          iterator->SetNext(trainWreck);
          trainWreck->SetPrevious(iterator);
          delete tempToDelete;
          currentSize_--;
        }
      }
      iterator = iterator->GetNext();
    }
  }
}

bool DLList::Exists(int valueToFind) {
  if (head_ == NULL) {
    return false;
} else {
    DLNode* iterator;
    iterator = head_;
    while (iterator != NULL && iterator->GetContents() != valueToFind) {
      iterator = iterator->GetNext();
    }
    if (iterator == NULL) {
      return false;
    }
    return true;
  }
}

void DLList::Clear() {
  while (head_ != NULL) {
    DLNode* t = head_;
    head_ = head_->GetNext();
    delete t;
    t = head_;
    currentSize_--;
  }
  tail_ = NULL;
}

string DLList::ToStringForwards() {
  stringstream ss;
  if (head_ == NULL) {
    std::cerr<< "List Empty";
    return ss.str();
  }
  DLNode* iterator;
  iterator = head_;
  while (iterator->GetNext() != NULL) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetNext();
  }
  ss << iterator->GetContents();
  return ss.str();
}

string DLList::ToStringBackwards() {
  stringstream ss;
  if (tail_ == NULL) {
    std::cerr<< "List Empty";
    return ss.str();
  }
  DLNode* iterator;
  iterator = tail_;
  while (iterator->GetPrevious()!= NULL) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetPrevious();
  }
  ss << iterator->GetContents();
  return ss.str();
}
