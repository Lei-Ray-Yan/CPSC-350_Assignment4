/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the main file. Combining all functions together and handles user intreactions, etc.

*/

/*
*     If this is late, I would like to use 1 of the late policy extention days please  :)
*/


#include <iostream>
#include "simulator.h"

using namespace std;


int main (int argc, char **argv){
  //check if file path provided
  if(argc < 2){
    cout << "Seems like you forgot to provide the file path :) " << endl;
    exit(1);
  }

  //process the simulation
  string filePath = argv[1];
  Simulator *simulator = new Simulator();

  simulator->startSimulation(filePath);

  //cleaning up
  delete simulator;
  return 0;
}






















