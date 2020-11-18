/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- a general, generic queue that is based on a general, generic linked-list which inherit from a general, generic, abstract list interface
- implemented in the same file.

*/


#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include "GenLinkedList.h"

using namespace std;


template <typename GenType>
class GenQueue{
private:
  GenListNode<GenType> *head;
  GenListNode<GenType> *tail;
  /*
    aka the linked-list used to hold the data
  */
  GenLinkedList<GenType> *queue;

  unsigned int size;

public:
  GenQueue();
  ~GenQueue();

  /*
    insert back and remove front
  */
  void insert(GenType d);
  GenType remove();

  /*
    the utility functions.
  */
  GenType peek();
  bool isEmpty();
  unsigned int getSize();
  GenListNode<GenType>* getHead();
  GenListNode<GenType>* getTail();
  void updateAttributes();  //update the pointer to head, tail, and the size
  void printAll();
};


//constructors
template <typename GenType>
GenQueue<GenType> :: GenQueue(){
  head = NULL;
  tail = NULL;
  queue = new GenLinkedList<GenType>();
  size = 0;
}

template <typename GenType>
GenQueue<GenType> :: ~GenQueue(){
  delete head;
  delete tail;
  delete queue;
}


//core functions
template <typename GenType>
void GenQueue<GenType> :: insert(GenType d){
  queue->insertBack(d);
  updateAttributes();
}

template <typename GenType>
GenType GenQueue<GenType> :: remove(){
  GenType removedData = queue->removeFront();
  updateAttributes();

  return removedData;
}


//miscellenious
template <typename GenType>
GenType GenQueue<GenType> :: peek(){
  return (queue->tail);
}

template <typename GenType>
bool GenQueue<GenType> :: isEmpty(){
  return (size==0);
}

template <typename GenType>
unsigned int GenQueue<GenType> :: getSize(){
  return size;
}

template <typename GenType>
GenListNode<GenType>* GenQueue<GenType> :: getHead(){
  return head;
}

template <typename GenType>
GenListNode<GenType>* GenQueue<GenType> :: getTail(){
  return tail;
}

template <typename GenType>
void GenQueue<GenType> :: updateAttributes(){
  head = queue->getHead();
  tail = queue->getTail();
  size = queue->getSize();
}

template <typename GenType>
void GenQueue<GenType> :: printAll(){
  queue->printList();
}




#endif











