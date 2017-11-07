/*
 * Name        : todo_list.h
 * Author      : Martin Hernandez
 * Description : This is the data manager class
 *
 */

#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <cstddef>
#include <iostream>
#include <iomanip>
#include "todo_item.h"
using std::ostream;
using std::endl;
using std::string;
using std::stringstream;

class TodoList {
 public:
/*
 * Constructor
 * Dynamically allocates memory for the TodoList
 */
    TodoList();
/*
 * Destructor  for TodoList
 * Clears the memory associated from the list_ Array
 */
    ~TodoList();
/*
 * Takes in a *TodoItem to Add to the next free space in the Array
 * @param TodoItem* item  - Item to be added
 */
    void AddItem(TodoItem* item);
/* Removes Item at an index within the Array
 * @param unsigned int locationToDelete - The location in the index to remove
 */
    void DeleteItem(unsigned int locationToDelete);
/*
 *Returns a TodoItem* within the array
 *@param unsigned int locationToRetrieve - The location of the item to retrieve
 *
 */
    TodoItem* GetItem(unsigned int locationToRetrieve);
/*
 * Accesor for Size
 */
    unsigned int GetSize();
/*
 * Accessor for Capacity
 */
    unsigned int GetCapacity();
/* 
 * Sorts Array based on priority 
 */
    void Sort();
/*
 * Returns a string containing all TodoItems in the list. Uses the 
 * TodoItems.ToFile() function to create. 
 */
    string ToFile();
/*
 * Outputs a numbered list of all TodoItems present in the list. 
 */
    friend ostream& operator <<(ostream &out, const TodoList &outList);

 private:
    TodoItem** list_;
    unsigned int maxListSize_;
    unsigned int currentListSize_;
    void increaseList10_();
    void removeIndex(int locationToDelete);
};
#endif /* TODO_LIST_H */
