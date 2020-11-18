/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- a general, generic, abstract list interface, containing only virstual functions representing basic list functions. 

*/


#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include <iostream>

using namespace std;

template <typename GenType>
class ListInterface{
  virtual void insertFront(GenType d) = 0;
  virtual void insertBack(GenType d) = 0;
  virtual GenType removeFront() = 0;
  virtual GenType removeBack() = 0;

  virtual int find(GenType d) = 0;
  virtual GenType deletePos(int pos) = 0;
  virtual bool removeNode(GenType d) = 0;

  virtual void printList() = 0;
  virtual bool isEmpty() = 0;
  virtual unsigned int getSize() = 0;

};

#endif















