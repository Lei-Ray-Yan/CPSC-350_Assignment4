/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the Window class simulates each window of the office, can accept Students and count time, stores information individually.

*/


#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Student.h"

using namespace std;

class Window{
private:
  int remainingTime;
  int idleTime;
  bool empty;
  Student *student;

public:
  Window();
  ~Window();

  /*
    attach a reference of a Student object to the window, simulating "processing at the window"
  */
  void addStudent(Student *s);
  /*
    the following functions update corresponding attributes and variables for simulating counting and processing.
  */
  void updateTime();
  void updateIdleTime();
  void updateStatus();

  /*
    the utility functions that return a private variable, etc.
  */
  Student* getStudent();
  int getIdleTime();
  bool isEmpty();

};


#endif




















