/*
* Name        : sl_list.h
* Author      : Martin Hernandez
* Description : NODE LIST
*/
#ifndef SL_LIST_H_
#define SL_LIST_H_

#include "sl_node.h"
#include <cstddef>
#include <sstream>
#include <string>

using std::endl;
using std::string;
using std::stringstream;
class SLList {
 public:
  SLList();
  ~SLList();
  void Insert(int valueToInsert);
  bool RemoveFirstOccurence(int valueToRemove);
  int GetHead() const;
  int GetTail() const;
  void Clear();
  unsigned int size() const;
  string ToString() const;
 private:
  void InsertHead(int input);
  void InsertTail(int input);
  void RemoveHead();
  void RemoveTail();
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
};

#endif /*SL_LIST_H_*/
