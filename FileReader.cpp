/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- the implementation of FileReader.h

*/


#include "FileReader.h"

using namespace std;


//constructors destructors
FileReader :: FileReader(){
  filePath = "";
}

FileReader :: ~FileReader(){
  //do nothing;
}

FileReader :: FileReader(string newFilePath){
  filePath = newFilePath;
}



//core functions
bool FileReader :: readLineToVector(){
  ifstream inFile;

  inFile.open(filePath);
  if(!inFile.is_open()){
    cout << "Error: file not found by given file path. " << endl;
    return false;
  }

  string currLine;
  while(getline(inFile, currLine)){
    fileContent.push_back(currLine);
  }

  return true;
}



//assisting functions
void FileReader :: outputContentToConsole(){
  for(int i=0; i<fileContent.size(); ++i){
    cout << fileContent[i] << endl;
  }
}










