/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- a general file reader class, which reads a text file and store each line in a vector. Mainly for conveniency and resuability.

*/

#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class FileReader{
public:
  string filePath;
  vector<string> fileContent;
  int lineCount = 0;

  FileReader();
  ~FileReader();
  FileReader(string newFilePath);

  /*
    read the file from filePath pre-determined, store the content into the vector as string for each line in the file.
  */
  bool readLineToVector();

  /*
    output the current vector content to console. Mainly for debugging.
  */
  void outputContentToConsole();

};


#endif










