/*
 * Name        : Coding Assignment 1
 * Author      : Martin Hernandez
 * Description : Header for Coding Assignment 1
 * Sources     : n/a
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ios_base;
using std::boolalpha;
// Declare Function Prototypes Here (What goes above main)
void CountCharacters(string rString , int &rAlpha, int &rDig);
string UpAndDown(string input);
int CountWords(string input);
double ComputeMeanAverage(int a[], unsigned int size);
int FindMinValue(int a[], unsigned int size);
int FindMaxValue(int a[], unsigned int size);
#endif /* ASSIGNMENT_1_H */
