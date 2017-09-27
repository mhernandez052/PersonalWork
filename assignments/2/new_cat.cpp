/*
 * Name        : New Cat
 * Author      : Martin Hernandez
 * Description : Program to concatenate files
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::cin;

int main(int argc, char *argv[]) {
  ifstream fin;
  string filename;
  string str;
  bool fileSuccess = true;
  string noFile;
  if (argc == 1) {
    while (!cin.eof()) {
      getline(cin, noFile);
      cout << noFile << endl;;
      if (cin.eof()) {
        return true;
      }
    }
  } else {
  for (int i = 1; i < argc; i++) {
    filename = argv[i];
    fin.open(filename.c_str());
    if (fin.is_open()) {
      fin.close();
  } else {
      cout<< "File Does Not Exist" << endl;
      fileSuccess = false;
      return 1;
    }
  }
  if (fileSuccess == true) {
    for (int i = 1; i < argc; i++) {
      filename = argv[i];
      fin.open(filename.c_str());
    while (!(fin.eof())) {
      getline(fin, str);
      cout << str << endl;
    }
    fin.close();
    }
  }
  }
}
