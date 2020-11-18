/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the implementation of Window.h.

*/


#include <iostream>
#include "Window.h"


//constructor destructor
Window :: Window(){
  remainingTime = 0;
  idleTime = 0;
  empty = true;
  student = NULL;
}

Window :: ~Window(){
  delete student;
}


//core functions
void Window :: addStudent(Student *s){
  student = s;
  remainingTime = s->getTimeNeeded();
  updateStatus();
}

void Window :: updateTime(){
  remainingTime -= 1;
}

void Window :: updateIdleTime(){
  idleTime += 1;
}

void Window :: updateStatus(){  //if process time reached, then clean the current student up, update empty or not, getting ready for the next student.
  if(remainingTime <= 0){
    student = NULL;
  }
  student == NULL ? empty = true : empty = false;
}


//assisting functions
Student* Window :: getStudent(){
  return student;
}

int Window :: getIdleTime(){
  return idleTime;
}

bool Window :: isEmpty(){
  return empty;
}


