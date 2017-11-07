/*
 * Name        : todo_list.cpp
 * Author      : Martin Hernandez
 * Description : This is the data manager class
 *
 */

#include "todo_list.h"

TodoList::TodoList() {
  currentListSize_ = 0;
  maxListSize_  = 25;
  list_ = new TodoItem*[maxListSize_];
  for (unsigned int i = 0; i < maxListSize_; i++) {
    list_[i] = NULL;
  }
}

TodoList::~TodoList() {
    delete [] list_;
    list_ = NULL;
}

void TodoList::AddItem(TodoItem* item) {
  if (currentListSize_ == maxListSize_) {
    increaseList10_();
  }
  list_[currentListSize_] = item;
  currentListSize_++;
}

void TodoList::DeleteItem(unsigned int locationToDelete) {
  unsigned int index = locationToDelete - 1;
  if (index <= currentListSize_) {
    delete list_[index];
    removeIndex(index);
    currentListSize_--;
  } else {
    cout << "Invalid Index Location" << endl;
  }
}

TodoItem* TodoList::GetItem(unsigned int locationToRetrieve) {
  unsigned int index = locationToRetrieve - 1;
  if (locationToRetrieve > 0 && locationToRetrieve <= currentListSize_) {
    return list_[index];
  } else {
    return NULL;
  }
}

unsigned int TodoList::GetSize() {
  return currentListSize_;
}

unsigned int TodoList::GetCapacity() {
  return maxListSize_;
}

void TodoList::Sort() {
  TodoItem* swap;
  for (int i = currentListSize_-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
       if (list_[j]->priority() > list_[j+1]->priority()) {
        swap = list_[j];
        list_[j] = list_[j+1];
        list_[j+1] = swap;
      }
    }
  }
}

string TodoList::ToFile() {
  stringstream ss;
  for (unsigned int i = 0; i < currentListSize_; i++) {
    if (list_[i] == NULL) {
      ss <<"";
  } else {
      ss << list_[i]->ToFile() << endl;
    }
  }
  return ss.str();
}

ostream& operator <<(ostream &out, const TodoList &outList) {
  unsigned int i;
  for (i = 0; i < outList.currentListSize_; i++) {
    out << i+1 << ": " << *outList.list_[i] << endl;
  }
  return out;
}

 /*
  * When List is full, dynamically allocates 10 extra indices
  */
void TodoList::increaseList10_() {
  maxListSize_ = maxListSize_ + 10;
  TodoItem** temp = new TodoItem*[maxListSize_];
  for (unsigned int i = 0; i < currentListSize_; i++) {
    temp[i] = list_[i];
  }
  for (unsigned int i = currentListSize_; i < maxListSize_; i++) {
    temp[i] = NULL;
  }
  delete [] list_;
  list_= temp;
}
/*
 * Compaction for when a location's data is cleared
 */
void TodoList::removeIndex(int locationToDelete ) {
  for (unsigned int i = locationToDelete; i < currentListSize_ -1 ; i++) {
    list_[i] = list_[i+1];
  }
  list_[currentListSize_ -1] = NULL;
}
