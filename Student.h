/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the Student class simulates a single student, with all relevant information recorded.

*/


#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
private:
  int timeArrived;
  int timeNeeded;
  /*
    how long has been waiting in the line
  */
  int waitTime;

public:
  Student();
  ~Student();
  Student(int t1, int t2);

  /*
    update wait time to record time spent in the queue
  */
  void updateWaitTime();

  int getTimeArrived();
  int getTimeNeeded();
  int getWaitTime();

};


#endif




