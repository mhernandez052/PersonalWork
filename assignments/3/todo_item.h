/*
 * Name        : todo_item.h
 * Author      : Luke Sathrum
 * Description : A class to hold a Todo Item, which is made up of a description,
 *               priority and a completed status.
 */

#ifndef TODO_ITEM_H_
#define TODO_ITEM_H_

#include <iostream>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostream;
using std::setw;

/*
 * Class TodoItem
 * Stores a description, priority and completed status that represents a single
 * Todo Item. This Todo Item will be used by a Todo List to store multiple
 * Todo Items.
 */
class TodoItem {
 public:
  /*
   * Constructor
   * Sets the description, priority and completed status of a TodoItem.
   * @param string description - Holds a description of a TodoItem
   * @param int priority       - Holds a priority of a TodoItem
   *                             Defaults to 1
   * @param bool completed     - Holds a completed status of a TodoItem
   *                           - Defaults to false
   */
  TodoItem(string description, int priority = 1, bool completed = false);

  /*
   * Destructor for TodoItem. Does Nothing.
   */
  ~TodoItem();

  /*
   * Accessor for description_
   * @return string - The TodoItem's current description.
   */
  string description();

  /*
   * Accessor for priority_
   * @return int - The TodoItem's current priority.
   */
  int priority();

  /*
   * Accessor for completed_
   * @return bool - The TodoItem's current completed status.
   */
  bool completed();

  /*
   * Mutator for description_
   * @param string description - The TodoItem's new description.
   */
  void set_description(string description);

  /*
   * Mutator for priority_
   * Makes sure the priority is between 1 and 5. If not it sets it to 5.
   * @param int priority - The TodoItem's new priority, set to 5 on error.
   */
  void set_priority(int priority);

  /*
   * Mutator for completed_
   * @param bool completed - The TodoItem's new completed status.
   */
  void set_completed(bool completed);

  /*
   * Creates a string that represents a TodoItem's values. Separates each value
   * with the @ symbol. Calls Scrub() to replace @ symbols in description with
   * backticks (`)
   * @return string - A representation of a TodoItem. Ex: "a description@3@1"
   */
  string ToFile();

  /*
   * An Overloaded Inseration Operator. Allows an entire TodoItem object to be
   * placed on the output stream.
   * @param ostream &out - An output stream
   * @param const TodoItem &todo_item - The TodoItem to be outputted
   * @return ostream& - The same output stream that was passed into the function
   */
  friend ostream& operator <<(ostream &out, const TodoItem &todo_item);

 private:
  string description_;
  int priority_;
  bool completed_;
  string Scrub(string to_scrub);
};

#endif /* TODO_ITEM_H_ */
