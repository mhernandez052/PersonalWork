/*
 * Name        : todo_item.cpp
 * Author      : Luke Sathrum
 * Description : Implementation file for TodoItem class
 */
#include "todo_item.h"

TodoItem::TodoItem(string description, int priority, bool completed)
    : description_(description),
      priority_(priority),
      completed_(completed) {
}

TodoItem::~TodoItem() {
}

string TodoItem::description() {
  return description_;
}

int TodoItem::priority() {
  return priority_;
}

bool TodoItem::completed() {
  return completed_;
}

void TodoItem::set_description(string description) {
  description_ = description;
}

void TodoItem::set_priority(int priority) {
  if (priority < 1 || priority > 5) {
    priority_ = 5;
  } else {
    priority_ = priority;
  }
}

void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}

string TodoItem::ToFile() {
  stringstream ss;
  ss << Scrub(description_) << "@" << priority_ << "@" << completed_;
  return ss.str();
}

ostream& operator <<(ostream &out, const TodoItem &todo_item) {
  out.setf(std::ios::left);
  // Place the TodoItem values on the ostream
  out << setw(50) << todo_item.description_ << " "
      << todo_item.priority_ << "   ";
  // Handle the fact that booleans output as 1s and 0s
  if (todo_item.completed_)
    out << "Yes";
  else
    out << "No";
  // Return the ostream object to allow for chaining of <<
  return out;
}

/*
 * Takes a string and returns a copy of that string where all instances of the @
 * symbol has been replaced by backticks (`)
 * @param string to_scrub - The string to change @ -> `
 * @return string - A string where @ have been converted to `
 */
string TodoItem::Scrub(string to_scrub) {
  for (unsigned int i = 0; i < to_scrub.length(); i++)
    if (to_scrub.at(i) == '@')
      to_scrub.at(i) = '`';
  return to_scrub;
}
