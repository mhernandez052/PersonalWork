/*
 * Name        : magic_item.h
 * Author      : Martin Hernandez
 * Description : Creating a parent/child class
 */

#ifndef MAGIC_ITEM_H_
#define MAGIC_ITEM_H_

#include "item.h"

class MagicItem : public Item {
 public:
  MagicItem(string name = "magicitem", unsigned int value = 0,
        string description = "no description", unsigned int mana_required = 0)
    : Item(name, value), description_(description),
      mana_required_(mana_required)  {
  }
  ~MagicItem();
  // Accesors
  string description();
  unsigned int mana_required();
  // Mutatorss
  void set_description(string description);
  void set_mana_required(unsigned int mana_required);
  string ToString();
 private:
  string description_;
  unsigned int mana_required_;
};

#endif /* MAGIC_ITEM_H_ */
