/*
 * Name        : todo_ui.h
 * Author      : Martin Hernandez
 * Description : User Interface
 * Sources     : n/a
 */
#ifndef TODO_UI_H
#define TODO_UI_H

#include "todo_list.h"
#include "CinReader.h"
class TodoUI {
 public:
/*
 * Constructor for TodoUI
 * Does Nothing
 */
  TodoUI();
/*
 * Destructor for TodoUI
 * Does Nothing
 */
  ~TodoUI();
/*
 * Displays Options for  the User Interface
 */
  void Menu();

 private:
  CinReader reader_;
  TodoList list_;
  void Create_();
  void Edit_();
  void DeleteItem_();
  void DisplayAllItems_();
  void DisplayOneItem_();
  void ClearList_();
  void Cls_();
};

#endif /* TODO_UI_H */
