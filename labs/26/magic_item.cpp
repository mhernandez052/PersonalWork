/*
 * Name        : magic_item.cpp
 * Author      : Martin Hernandez
 * Description : Creating a parent/child class
 */


#include "magic_item.h"

/*MagicItem::MagicItem(string name, unsigned int value, string description,
            unsigned int mana_required) {
}*/
MagicItem::~MagicItem() {
}
  // Accesors
string MagicItem::description() {
  return description_;
}
unsigned int MagicItem::mana_required() {
  return mana_required_;
}
  // Mutatorss
void MagicItem::set_description(string description) {
  description_ = description;
}
void MagicItem::set_mana_required(unsigned int mana_required) {
  mana_required_= mana_required;
}
string MagicItem::ToString() {
  stringstream ss;
  ss << Item::ToString();
  ss << ", " << description_ << ", requires " <<
  mana_required_ << " mana";
  return ss.str();
}
