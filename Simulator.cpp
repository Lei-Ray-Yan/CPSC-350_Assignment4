/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the implementation of Simulator.h

*/


#include "Simulator.h"


//constructor destructor
Simulator :: Simulator(){
  currentTime = 0;
  preQueue = new GenQueue<Student*>();
  queue = new GenQueue<Student*>();
  postQueue = new GenQueue<Student*>();
  windows = new vector<Window*>();
  statistics = new map<string, float>();
  numWindows = 0;

  fileReader = new FileReader();
}

Simulator :: ~Simulator(){
  delete preQueue;
  delete queue;
  //delete postQueue;
  delete windows;
  delete statistics;

  delete fileReader;
}


//core functions
void Simulator :: startSimulation(string filePath){   //the main flow controls
  readFile(filePath);

  while(!checkEnd()){
    updateProcess();
  }

  analyzeStatistics();
  outputStatistics();
}

void Simulator :: readFile(string filePath){
  fileReader->filePath = filePath;
  fileReader->readLineToVector();

  initializePreQueue();
}

void Simulator :: initializePreQueue(){
  vector<string> fileContent = fileReader->fileContent;

  bool innerLoop = false;
  int arriveTime = -1;
  int numStudents = -1;
  for(int i=0; i<fileContent.size(); ++i){
    //1st line: read the number of windows
    if(i==0){
      numWindows = stoi(fileContent[i]);
      initializeWindows(numWindows);
      continue;
    }

    //inner loop: read the students data, update both the main loop and inner loop
    if(arriveTime < 0){
      arriveTime = stoi(fileContent[i]);
      continue;
    }
    if(numStudents < 0){
      numStudents = stoi(fileContent[i]);
      continue;
    }
    for(int j=0; j<numStudents; ++i, ++j){
      innerLoop = true;
      int neededTime = stoi(fileContent[i]);
      Student *s = new Student(arriveTime, neededTime);
      preQueue->insert(s);
      continue;
    }
    //after the current inner loop, reset the values for catching the nest inner loop
    if(innerLoop){
      arriveTime = -1;
      numStudents = -1;
      innerLoop = false;
    }
  }

  totalProcessedStudents = preQueue->getSize();

  GenListNode<Student*> *curr = new GenListNode<Student*>();
  curr = preQueue->getHead();
}

void Simulator :: initializeWindows(int n){
  numWindows = n;
  for(int i=0; i<n; ++i){
    Window *w = new Window();
    windows->push_back(w);
  }
}

void Simulator :: updateProcess(){
  //preQueue to queue
  GenListNode<Student*> *curr =  new GenListNode<Student*>();
  curr = preQueue->getHead();

  while(curr != NULL){
    Student *s = new Student();
    s = curr->data;
    int arriveTime = s->getTimeArrived();

    curr = curr->next;

    if(arriveTime <= currentTime){
      queue->insert(s);
      preQueue->remove();
    }else{
      break;
    }
  }

  //queue to windows
  for(int i=0; i<numWindows; ++i){
    Window *w = new Window();
    w = windows->at(i);
    if(w->isEmpty()){
      if(!(queue->isEmpty())){
        Student *s = new Student();
        s = queue->remove();
        w->addStudent(s);
      }
    }
  }

  //update in queue wait time
  GenListNode<Student*> *curr2 = new GenListNode<Student*>();
  curr2 = queue->getHead();
  while(curr2 != NULL){
    Student *s = new Student();
    s = curr2->data;
    s->updateWaitTime();
    curr2 = curr2->next;
  }

  //process in windows, and update window idle time
  for(int i=0; i<numWindows; ++i){
    Window *w = windows->at(i);
    if(w->isEmpty()){ //for idle time update
      w->updateIdleTime();
      continue;
    }
    Student *s = w->getStudent();
    w->updateTime();
    w->updateStatus();
    if(w->isEmpty()){ //for removing student from window
      postQueue->insert(s);
    }
  }

  //update current time
  currentTime += 1;

}

bool Simulator :: checkEnd(){
  if((postQueue->getSize()) >= totalProcessedStudents){
    return true;
  }

  return false;
}

void Simulator :: analyzeStatistics(){
  //required informations
  float meanStudentWaitTime = 0;
  float medianStudentWaitTime = 0;
  float longestStudentWaitTime = 0;
  float numStudentWaitMoreThanTenMin = 0;
  float meanWindowIdleTime = 0;
  float longestWindowIdleTime = 0;
  float numWindowIdleMoreThanFiveMin = 0;

  //analyzing students' statistics
  vector<int> studentsWaitTime;   //excluding 0 mins of wait
  vector<int> allStudentsWaitTime;  //including 0 mins of wait

  GenListNode<Student*> *curr = new GenListNode<Student*>();
  curr = postQueue->getHead();
  while(curr != NULL){
    int currStudentWaitTime = (curr->data)->getWaitTime();
    if(currStudentWaitTime > 0){
        studentsWaitTime.push_back(currStudentWaitTime);
    }
    allStudentsWaitTime.push_back(currStudentWaitTime);
    curr = curr->next;
  }

  sort(studentsWaitTime.begin(), studentsWaitTime.end());
  sort(allStudentsWaitTime.begin(), allStudentsWaitTime.end());

  //calculates student mean, longest, etc.
  int totalStudentWaitTime = 0;
  int moreThanTenMin = 0;
  int longestWaitTime = 0;
  for(int i=0; i<studentsWaitTime.size(); ++i){
    totalStudentWaitTime += studentsWaitTime[i];
    if (studentsWaitTime[i]>10){
      moreThanTenMin += 1;
    }
    if(studentsWaitTime[i]>longestWaitTime){
      longestWaitTime = studentsWaitTime[i];
    }
  }

  //calculates student median, etc
  int medPosition = 0;
  float medValue = 0;
  if(allStudentsWaitTime.size() == 0){
    medValue = 0;
  }
  else if((allStudentsWaitTime.size())%2 == 0){
    medPosition = allStudentsWaitTime.size()/2 - 1;
    medValue = (float(allStudentsWaitTime[medPosition])+float(allStudentsWaitTime[medPosition+1]))/2;
  }
  else{
    medPosition = round(float(allStudentsWaitTime.size())/2) - 1;
    medValue = float(allStudentsWaitTime[medPosition]);
  }

  meanStudentWaitTime = totalStudentWaitTime == 0 ? 0 : float(totalStudentWaitTime)/ float(studentsWaitTime.size());
  medianStudentWaitTime = medValue;
  longestStudentWaitTime = longestWaitTime;
  numStudentWaitMoreThanTenMin = float(moreThanTenMin);


  //analyzing windows' statistics
  vector<int> windowsIdleTime;

  for(int i=0; i<numWindows; ++i){
    windowsIdleTime.push_back((windows->at(i))->getIdleTime());
  }

  int longestIdleTime = 0;
  int numIdleMoreThanFiveMin = 0;
  int totalIdleTime = 0;
  for(int i=0; i<windowsIdleTime.size(); ++i){
    totalIdleTime += windowsIdleTime[i];
    if(windowsIdleTime[i] > 5){
      numIdleMoreThanFiveMin += 1;
    }
    if(longestIdleTime < windowsIdleTime[i]){
      longestIdleTime = windowsIdleTime[i];
    }
  }

  meanWindowIdleTime = float(totalIdleTime)/ float(windowsIdleTime.size());
  longestWindowIdleTime = float(longestIdleTime);
  numWindowIdleMoreThanFiveMin = float(numIdleMoreThanFiveMin);


  //recording the analyzed datas
  statistics->insert({"meanStudentWaitTime", meanStudentWaitTime});
  statistics->insert({"medianStudentWaitTime", medianStudentWaitTime});
  statistics->insert({"longestStudentWaitTime", longestStudentWaitTime});
  statistics->insert({"numStudentWaitMoreThanTenMin", numStudentWaitMoreThanTenMin});

  statistics->insert({"meanWindowIdleTime", meanWindowIdleTime});
  statistics->insert({"longestWindowIdleTime", longestWindowIdleTime});
  statistics->insert({"numWindowIdleMoreThanFiveMin", numWindowIdleMoreThanFiveMin});
}


//assisting functions

void Simulator :: outputStatistics(){
  cout << "The mean student wait time: " << statistics->find("meanStudentWaitTime")->second << endl;
  cout << "The median student wait time: " << statistics->find("medianStudentWaitTime")->second << endl;
  cout << "The longest student wait time: " << statistics->find("longestStudentWaitTime")->second << endl;
  cout << "The number of students waiting over 10 minutes: " << statistics->find("numStudentWaitMoreThanTenMin")->second << endl;

  cout << "The mean window idle time: " << statistics->find("meanWindowIdleTime")->second << endl;
  cout << "The longest window idle time: " << statistics->find("longestWindowIdleTime")->second << endl;
  cout << "Number of windows idle for over 5 minutes: " << statistics->find("numWindowIdleMoreThanFiveMin")->second << endl;
}







