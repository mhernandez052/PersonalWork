/*
 * Name        : sl_node.h
 * Author      : Martin Hernandez
 * Description : Header for sl_node.cpp
 *               
 */

#ifndef SL_NODE_H_
#define SL_NODE_H_

#include <cstddef>

class SLNode {
 public:
  SLNode();
  SLNode(int overloaded);
  ~SLNode();
  void set_contents(int contents);
  int contents() const;
  void set_next_node(SLNode* next_node);
  SLNode* next_node() const;
 private:
  SLNode* next_node_;
  int contents_;
};

#endif  /*SL_NODE_H_*/
