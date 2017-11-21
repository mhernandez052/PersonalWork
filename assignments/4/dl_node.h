/*
* Name        : dl_node.h
* Author      : Martin Hernandez
* Description : Doubly linked list
*/
#ifndef DL_NODE_H_
#define DL_NODE_H_

#include <cstddef>
#include <iostream>
#include <sstream>
using std::string;
using std::stringstream;

class DLNode {
 public:
/*
 * Node Constructor
 */
  DLNode();
/*
 * Destructor
 * Does nothing
 */
  ~DLNode();
/*
 * Contents mutator
 */
  void SetContents(int contents);
/*
 * Next Node mutator
 */
  void SetNext(DLNode* next_Node);
/*
 * Previous Node mutator
 */
  void SetPrevious(DLNode* previous_Node);
/*
 * Contents accessor
 */
  int GetContents() const;
/*
 * Next Node accessor
 */
  DLNode* GetNext() const;
/*
 * Previous Node accessor
 */
  DLNode* GetPrevious() const;
 private:
  int contents_;
  DLNode* previous_Node_;
  DLNode* next_Node_;
};
#endif /*DL_NODE_H_*/
