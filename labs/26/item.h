/*
 * Name        : item.h
 * Author      : Martin Hernandez
 * Description : Creating a parent/child class
 */
#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <sstream>
using std::stringstream;
using std::string;

class Item {
 public:
  Item(string name = "item", unsigned int value = 0)
    : name_(name), value_(value) {
    }
  ~Item();
  // Accesors
  string name();
  unsigned int value();
  // Mutators
  void set_name(string name);
  void set_value(unsigned int value);
  string ToString();
 private:
  string name_;
  unsigned int value_;
};
#endif /*ITEM_H_*/
