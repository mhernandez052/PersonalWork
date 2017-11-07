/*
 * Name        : driver.cpp
 * Author      : Martin Hernandez
 * Description : Demonstrates The Todo_UI program
 * Sources     : n/a
 */

#include "todo_list.h"
#include "todo_ui.h"

int main() {
/* 
 * Creates an instance of the TodoUI
 */
  TodoUI Instance;
/*
 * Calls the Menu() function
 */
  Instance.Menu();
  return 0;
}
