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
  void InsertHead(int input);
  void RemoveHead();
  void Clear();
  unsigned int size();
  string ToString() const;
 private:
  SLNode* head_;
  unsigned int size_;
};

#endif /*SL_LIST_H_*/
