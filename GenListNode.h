/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- a general, generic listnode class for linked-list.
- supporting the GenLinkedList.h. 

*/


#ifndef GENLISTNODE_H
#define GENLISTNODE_H

#include <iostream>
#include "ListInterface.h"

using namespace std;


template <typename GenType>
class GenListNode{
public:
  GenType data;
  GenListNode<GenType> *prev;
  GenListNode<GenType> *next;

  GenListNode();
  GenListNode(GenType d);
  ~GenListNode();
};


//definition of methods starts here
template <typename GenType>
GenListNode<GenType> :: GenListNode(){
  //not using
}

template <typename GenType>
GenListNode<GenType> :: GenListNode(GenType d){
  data = d;
  prev = NULL;
  next = NULL;
}

template <typename GenType>
GenListNode<GenType> :: ~GenListNode(){
  delete prev;
  delete next;
}


#endif










