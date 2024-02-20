 #include <iostream>

using namespace std;

#include "LinkedList.h"

typedef Node* ptr;

//class LinkedList{
 // public:
 // ptr head;
 // ptr tail;
//int numele;
  
  //constructor
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numele = 0; //used to count list
}
//deconstructor
LinkedList::~LinkedList(){
    while(numele > 0){
        pop();
    }
}

//copy constructor 
LinkedList::LinkedList(const LinkedList& rhs){
     head = nullptr;
     tail = nullptr;
     numele = 0;
     for(int i = 0; i < rhs.size(); i++){
         push(rhs.at(i));
     }
 }

 
    //push back 
void LinkedList::push(int data){
    numele++; //counting each iteration
    
    Node* activeNode = new Node();
    activeNode->data = data; 
    tail = head;
    
    if(head == nullptr){
        activeNode->prev = nullptr;
        head = activeNode;
        return;
    }
    
    while(tail->next != nullptr){
        tail = tail->next;
    }
    head->prev=activeNode;
    
    tail->next = activeNode; //assign the next ptr to new num
    activeNode->prev = tail; //assign the last num as the new prev
    tail = activeNode; //tail is now the new data
    
}

//pop back
void LinkedList::pop(){
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        numele--;
        return;
    }
    
    Node* activeNode = head;
    while(activeNode->next->next != nullptr){
        activeNode = activeNode->next;
    }
    
    delete activeNode->next;
    activeNode->next = nullptr;
    tail = activeNode;
    
    numele--; //takes away from the list 
}

int LinkedList::size() const{
    return numele;
}


void LinkedList::print(){
    for(int i = 0; i < size(); i++){
        cout << at(i) << endl;
    }
    cout<<endl;
}


void LinkedList::insert(int data, int pos){
    int index = 0;
    
    Node* activeNode = head;
    Node* temp = new Node;
    if(pos == 0){
        temp->data = data;
        temp->next = head;
        temp->prev = nullptr;
       
        
        if(head != nullptr){
            head->prev=temp;
            head = temp;
            numele++;
          
        }
    }
    if(pos == numele - 1){
        push(data);
        
    }
    
    if(index == pos - 1){
        temp->data = data;
        temp->next = activeNode->next;
        activeNode->next = temp;
        temp->prev = activeNode;
        
        numele++;
    }
    index++;
    activeNode = activeNode->next;
    
}




void LinkedList::remove(int pos){
    
int index = 0;

Node* temp = new Node;

Node* activeNode = head;

if(pos == 0){
    if(head->next == nullptr){
        head = nullptr;
    }else{
        head = head->next;
    }
    numele--;
     if(index == pos - 1){
        temp = activeNode->next->next;
        activeNode->next = temp;
        activeNode->prev = temp->prev->prev;
        numele--;
    }
    index++;
    activeNode = activeNode->next; 
    }
    
}



int& LinkedList::at(int idx) const{
    Node* activeNode = head;
    int i = 0;
    while(true){
        if(i == idx){
            return activeNode->data;
        }
        
        i++;
        activeNode = activeNode->next;
    }
}
    
void LinkedList::operator=(const LinkedList& rhs){
    
    while(numele > 0){
        pop();
    }
    
    for(int i = 0; i < rhs.size(); i++){
        push(rhs.at(i));
    }
}

    
    
//};



void test(){
    LinkedList dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    LinkedList dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    cout << "test" << endl;
    dll.print();
    cout << "test" << endl;
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
}


int main(){
    test();
    
    return 0;
}