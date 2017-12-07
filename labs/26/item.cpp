/*
 * Name        : item.cpp
 * Author      : Martin Hernandez
 * Description : Creating a parent/child class
 */

#include "item.h"

/*Item::Item(string name, unsigned int value) {
}*/
Item::~Item() {
}
string Item::name() {
    return name_;
}
unsigned int Item::value() {
    return value_;
}
void Item::set_name(string name) {
    name_ = name;
  }
void Item::set_value(unsigned int value) {
    value_ = value;
}
string Item::ToString() {
  stringstream ss;
    ss << name_ << ", $" << value_;
    return ss.str();
}
