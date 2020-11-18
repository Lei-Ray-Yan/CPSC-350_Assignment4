/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the implementation of Students.h.

*/


#include "Student.h"


//constructor destructor
Student :: Student(){
  timeArrived = 0;
  timeNeeded = 0;
  waitTime = 0;
}

Student :: ~Student(){
  //do nothing
}

Student :: Student(int t1, int t2){
  timeArrived = t1;
  timeNeeded = t2;
  waitTime = 0;
}


//core functions
void Student :: updateWaitTime(){
  waitTime += 1;
}

//assisting functions
int Student :: getTimeArrived(){
  return timeArrived;
}

int Student :: getTimeNeeded(){
  return timeNeeded;
}

int Student :: getWaitTime(){
  return waitTime;
}




