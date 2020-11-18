/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the Simulator class handles the general flow and everything about the entire simulation, the core class of tg=he program.

*/


#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "Window.h"
#include "Student.h"
#include "FileReader.h"
#include "GenQueue.h"

using namespace std;


class Simulator{
private:
  /*
    the current base time, starting from 0
  */
  int currentTime;
  /*
    preQueue records all the students that are going to arrive, recorded directly from the given text file.
    queue records the students who have already arrived, waiting in the line and not yet go to the window.
    postQueue records the students who have already finished processing. Mainly for statistical analysis.
    windows contains all the windows generated and processing the students.
    statistics records all the statistical data with float value, paired with a string key.
  */
  GenQueue<Student*> *preQueue;
  GenQueue<Student*> *queue;
  GenQueue<Student*> *postQueue;
  vector<Window*> *windows;
  map<string, float> *statistics;
  int numWindows;
  int totalProcessedStudents;

public:
  FileReader *fileReader;

  Simulator();
  ~Simulator();

  /*
    the main function. Handles the general flow of the entire simulation.
  */
  void startSimulation(string filePath);
  /*
    the following functions reads the file using the FileReader, interprete the information and initialize the preQueue, windows, etc.
  */
  void readFile(string filePath);
  void initializePreQueue();
  void initializeWindows(int n);
  /*
    handles the specific behaviours of each "round", aka each time unit, of the process
  */
  void updateProcess();
  /*
    check ending condition.
    If the num students in the postQueue is same as total students going to be processed, then entire process ends.
  */
  bool checkEnd();
  /*
    analyze and calculates the desired statistical data.
  */
  void analyzeStatistics();

  /*
    output the statistical data to the console.
  */
  void outputStatistics();

};


#endif





