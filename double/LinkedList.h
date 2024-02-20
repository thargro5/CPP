
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* head;
    Node* tail;
    
};
typedef Node* ptr;

class LinkedList {
  public:
  ptr head;
  ptr tail;
  int numele;
  
  LinkedList(); 
  ~LinkedList(); 
  LinkedList(const LinkedList& rhs);
  
  void push(int data);
  
  void pop();
  
  int size() const;
  
  void print();
  
  void insert(int data, int pos);
  
  void remove(int pos);
  
  int& at(int idx) const;
  
  void operator=(const LinkedList& rhs);
  
    
    
    
    
};

#endif