/*
* Name        : dl_list.h
* Author      : Martin Hernandez
* Description : Doubly linked list
*/
#ifndef DL_LIST_H_
#define DL_LIST_H_

#include "dl_node.h"

class DLList {
 public:
/*
 * Doubly-linked list constructor
 */
  DLList();
/*
 * Destructor
 * Calls Clear();
 */
  ~DLList();
/*
 * Accessor for list size
 * @returns unsigned int - current size of list
 */
  unsigned int GetSize() const;
/*
 * Creates a new node with contents provided to set to the head of the list
 * @param contents - contents to be inserted
 */
  void PushFront(int contents);
/*
 * Creates a new node with contents provided to set at the end of the list
 * @param contents - contents to be inserted
 */
  void PushBack(int contents);
/*
 * Accessor for Head of list
 * @returns- Head of list
 */
  int GetFront() const;
/*
 * Accessor for Tail of list
 * @returns- Tail of list
 */
  int GetBack() const;
/*
 * Removes head of list
 * standard error outputs "List Empty" if list is empty
 */
  void PopFront();
/*
 * Removes tail of list
 * standard error outputs "List Empty" if list is empty
 */
  void PopBack();
/*
 * Finds and removes an instance of a word in the list
 * @param valueToRemove- value to find and remove
 */
  void RemoveFirst(int valueToRemove);
/*
 * Finds a word in the list and removes every instance of that word
 * @param valuesToRemove - Value to find and remove
 */
  void RemoveAll(int valuesToRemove);
/*
 * Checks to see if a word exists in the list
 * @param valueToFind- value to find
 * @return- true if found, false if not
 */ 
  bool Exists(int valueToFind);
/*
 * Removes every node from the list and sets Head and Tail to NULL
 */ 
  void Clear();
/*
 * Standard outputs the lists contents in an advancing order
 * @return string- string of words in progressing fashion
 */ 
  string ToStringForwards();
/*
 * Standard outputs the lists contents in an a reverse order
 * @return string- string of words in reverse fashion
 */ 
  string ToStringBackwards();
 private:
  unsigned int currentSize_;
  DLNode* head_;
  DLNode* tail_;
};
#endif /* DL_LIST_H_ */
