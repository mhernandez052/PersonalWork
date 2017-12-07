/*
 * Name        : food_item.h
 * Author      : Martin Hernandez
 * Description : Creating a parent/child class
 */

#ifndef FOOD_ITEM_H_
#define FOOD_ITEM_H_

#include "item.h"

class FoodItem : public Item {
 public:
  FoodItem(string name = "fooditem", unsigned int value = 0,
  unsigned int calories = 0, string unit_of_measure = "nounits",
  double units = 0)
    : Item(name, value), calories_(calories), unit_of_measure_(unit_of_measure),
      units_(units) {
  }
  ~FoodItem();
  // Accesors
  unsigned int calories();
  string unit_of_measure();
  double units();
  // Mutators
  void set_calories(unsigned int calories);
  void set_unit_of_measure(string unit_of_measure);
  void set_units(double units);
  string ToString();
 private:
  unsigned int calories_;
  string unit_of_measure_;
  double units_;
};
#endif /*FOOD_ITEM_H_*/
