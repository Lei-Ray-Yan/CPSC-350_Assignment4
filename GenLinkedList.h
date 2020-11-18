/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 4

- a general, generic linked-list which inherit from a general, generic, abstract list interface, contains all generally used list functions.
- acts like a implementation of the virtual interface.

*/


#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H

#include <iostream>
#include "ListInterface.h"
#include "GenListNode.h"

using namespace std;


template <typename GenType>
class GenLinkedList : ListInterface<GenType>{
private:
  GenListNode<GenType> *head;
  GenListNode<GenType> *tail;
  unsigned int size;

public:
  GenLinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
  }

  ~GenLinkedList(){
    delete head;
    delete tail;
  }


  //core functions
  void insertFront(GenType d){
    GenListNode<GenType> *node = new GenListNode<GenType>(d);
    if(size == 0){
      tail = node;
    }
    else{
      head->prev = node;
      node->next = head;
    }
    head = node;
    ++size;
  }

  void insertBack(GenType d){
    GenListNode<GenType> *node = new GenListNode<GenType>(d);
    if(size == 0){
      head = node;
    }
    else{
      tail->next = node;
      node->prev = tail;
    }
    tail = node;
    ++size;
  }

  GenType removeFront(){
    GenListNode<GenType> *node = head;
    if(head->next == NULL){
      tail = NULL;
    }
    else{
      head->next->prev = NULL;
    }
    head = head->next;
    size--;
    node->next = NULL;
    GenType temp = node->data;

    delete node;
    return temp;
  }

  GenType removeBack(){
    GenListNode<GenType> *node = tail;
    if(tail->prev == NULL){
      head = NULL;
    }
    else{
      tail->prev->next = NULL;
    }
    tail = tail->prev;
    size--;
    node->prev = NULL;
    GenType temp = node->data;

    delete node;
    return temp;
  }


  //asisting methods
  int find(GenType d){
    int pos = -1;
    GenListNode<GenType> *curr = head;

    while(curr != NULL){
      pos++;
      if(curr->data == d){
        break;
      }
      curr = curr->next;
    }

    if(curr == NULL){
      pos = -1;
    }

    return pos;
  }

  GenType deletePos(int pos){
    int currPos = 0;
    GenListNode<GenType> *curr = head;
    GenListNode<GenType> *previ = head;

    while(currPos != pos){
      previ = curr;
      curr = curr->next;
      currPos++;
    }

    if(curr == head){
      head = NULL;
    }

    if(curr == tail){
      previ->next = NULL;
      tail = previ;
    }
    else{
      previ->next = curr->next;
      curr->next->prev = previ;
    }
    curr->prev = NULL;
    curr->next = NULL;

    GenType temp = curr->data;
    cout << "curr: " << temp << endl;
    cout << "prev: " << previ->data << endl;

    size--;
    delete curr;
    return temp;
  }

  bool removeNode(GenType d){
    GenListNode<GenType> *curr = head;

    while(curr->data != d){
      curr = curr->next;
      if(curr == NULL){
        return false;
      }
    }

    if(curr == head){
      head = curr->next;
    }
    else if(curr == tail){
      tail = curr->prev;
    }
    else{
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
    }

    curr->prev = NULL;
    curr->next = NULL;

    delete curr;
    size--;

    return true;
  }


  //miscellenious methods
  void printList(){
    GenListNode<GenType> *curr = head;

    cout << "→ ";
    while(curr != NULL){
      cout << curr->data;
      cout << " ";
      curr = curr->next;
    }
    cout << " ←" << endl;
  }

  bool isEmpty(){
    return (size == 0? true : false);
  }

  unsigned int getSize(){
    return size;
  }

  GenListNode<GenType>* getHead(){
    return head;
  }

  GenListNode<GenType>* getTail(){
    return tail;
  }



};


#endif















