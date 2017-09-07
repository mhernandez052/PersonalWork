/*
 * Name        : Coding Assignment 1
 * Author      : Martin Hernandez
 * Description : Functions to practice Strings and Arrays
 * Sources     : n/a
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
void CountCharacters(string rString , int &rAlpha, int &rDig) {
    rAlpha = 0;
    rDig = 0;
    if (rString.size() > 0) {
        for (unsigned int i = 0 ; i < rString.size(); i++) {
        if (isalpha(rString[i])) {
        rAlpha++;
        }
    }
    for (unsigned int j = 0; j < rString.size(); j++) {
        if (isdigit(rString[j])) {
            rDig++;
            }
        }
    }
}
string UpAndDown(string input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (i % 2 == 0) {
            input.at(i)=toupper(input.at(i));
        } else if (i % 2 == 1) {
            input.at(i)=tolower(input.at(i));
        }
    }
    return input;
}

int CountWords(string input) {
  if (input.size() >  0) {
    int spaces = 1;
    for (unsigned int i = 0; i < input.size(); i++) {
      if (input.at(i) == ' ') {
          spaces++;
      }
    }
    return spaces;
  } else {
    return 0;
  }
}

double ComputeMeanAverage(int a[], unsigned int size) {
    double average = 0;
    for (unsigned int i = 0; i < size; i++) {
        average +=   (a[i]);
    }
    return (average/size);
}

int FindMinValue(int a[], unsigned int size) {
  int lowest = a[0];
    for (unsigned int i = 1; i < size; i++) {
        if (a[i]< lowest) {
            lowest = a[i];
        }
    }
    return lowest;
}
int FindMaxValue(int a[], unsigned int size) {
  int highest = a[0];
    for (unsigned int i = 1; i < size; i++) {
        if (a[i]> highest) {
            highest = a[i];
        }
    }
    return highest;
}
