/*
 * Name        : todo_ui.cpp
 * Author      : Martin Hernandez
 * Description : User Interface
 * Sources     : n/a
 */
#include "todo_ui.h"


TodoUI::TodoUI() {
}
TodoUI::~TodoUI() {
}
void TodoUI::Menu() {
  for (;;) {
    int int_var;
    if (list_.GetSize() != 0) {
      cout << "\nWelcome to The List Interface"  << endl;
      cout << "1) Create New Item" << endl;
      cout << "2) To Edit an item"  << endl;
      cout << "3) To delete an item"  << endl;
      cout << "4) To view all items"  << endl;
      cout << "5) To view specific item"  << endl;
      cout << "6) To delete all items"  << endl;
      cout << "7) To Exit"  << endl;
      int_var = reader_.readInt(1, 7);
      Cls_();
      if (int_var == 1) {
        Create_();
      } else if (int_var == 2) {
          Edit_();
      } else if (int_var == 3) {
        DeleteItem_();
      } else if (int_var == 4) {
        DisplayAllItems_();
      } else if (int_var == 5) {
        DisplayOneItem_();
      } else if (int_var == 6) {
        cout << "Clearing List...\n";
        ClearList_();
      } else if (int_var == 7) {
        cout << "Exiting...\n";
        break;
      }
    } else {
        cout << "\nWelcome to The List Interface"  << endl;
        cout << "1) Create New Item" << endl;
        cout << "2) To view all items"  << endl;
        cout << "3) To Exit"  << endl;\
        int_var = reader_.readInt(1, 3);
        Cls_();
        if (int_var == 1) {
          Create_();
      } else if (int_var == 2) {
          DisplayAllItems_();
      } else if (int_var == 3) {
          cout << "Exiting...\n";
          break;
        }
      }
  }
}
/*
 * Takes in input an description and priorty to create an item to add to list
 */
void TodoUI::Create_() {
  string string_description;
  unsigned int int_priority;
  cout << "Creating Item...\n";
  cout << "Enter a short reminder description: ";
  string_description = reader_.readString(false);
  cout << "What is its priority (1-5)? (1 Being high priority): ";
  int_priority = reader_.readInt(1, 5);
  TodoItem* newItem = new TodoItem(string_description, int_priority);
  list_.AddItem(newItem);
  cout << "\nItem Created!\n";
}
/*
 * Asks User which item to edit, and which aspect of the item
 */
void TodoUI::Edit_() {
  TodoItem* temp;
  unsigned int input;
  string new_description;
  DisplayAllItems_();
  cout << "Editing Item...\n";
  cout << "Select item to edit: ";
  input = reader_.readInt(1, list_.GetSize());
  temp = list_.GetItem(input);
  cout << temp -> ToFile() << endl << "Enter: \n"
      << "  1) To change description\n" <<
      "  2) To change priority\n  3) To change completion\n  ";
  input = reader_.readInt(1, 3);
  if (input == 1) {
    cout << "Enter a new short description: ";
    new_description = reader_.readString(false);
    temp -> set_description(new_description);
    cout << "Description set!" << endl;
  } else if (input == 2) {
    cout << "Enter new priority: ";
    input = reader_.readInt(1, 5);
    temp -> set_priority(input);
    cout << "Priority set!" << endl;
  } else {
    temp -> set_completed(!(temp -> completed()));
    cout << "Completion status now set to: ";
      if (temp -> completed() == 1) {
        cout << "Yes" << endl;;
      } else {
          cout << "No" << endl;
      }
    }
}
/*
 * Asks User which location they would like removed from list
 */
void TodoUI::DeleteItem_() {
  unsigned int input;
  DisplayAllItems_();
  cout << "Select item to delete: ";
  input = reader_.readInt(1, list_.GetSize());
  list_.DeleteItem(input);
  cout << "Item Deleted at location: "<< input << endl;
}
/*
 * Outputs a numbered list of all items present within the list
 */
void TodoUI::DisplayAllItems_() {
    cout << "Displaying List Contents...\n";
    cout << "Description" << setw(56) <<"(Priority/Completion)" << endl;
    if (list_.GetSize() == 0) {
      cout << "[ List is empty ]" << endl;
  } else {
      list_.Sort();
      cout << list_;
    }
}
/*
 * Ask user Which item in the array they would like to displayed
 */
void TodoUI::DisplayOneItem_() {
  TodoItem* temp;
  unsigned int input;
  cout<< "Enter item to display between (1-"<< list_.GetSize() << "): \n";
  input = reader_.readInt(1, list_.GetSize());
  cout << "Item at location " << input << " is: " << endl;
  cout << "Description" << setw(53) <<"Priority/Completion" << endl;
  temp = list_.GetItem(input);
  cout << *temp << endl;
}
/*
 * Calls DeleteItem () to clear the contents of the list
 */
void TodoUI::ClearList_() {
  while (list_.GetSize() != 0) {
    list_.DeleteItem(1);
  }
}
/*
 * Aesthetics
 */
void TodoUI::Cls_() {
  cout << string(20, '\n');
}
