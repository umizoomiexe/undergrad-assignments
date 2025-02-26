//INTLIST.CPP FILE
#include "IntList.h"

#include <iostream>
#include <exception>

using namespace std;

#include <iostream>
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *current = rhs.dummyHead.next; 
    //TEST CASE: while current node is not the dummy tail, keep printing 
    while (current != &rhs.dummyTail) {
        out << current->data;
        //TEST CASE: to avoid extra space being printed after last node 
        if (current->next != &rhs.dummyTail) {
            out << " ";
        }
        current = current->next;
    }
    return out;
}

IntList::~IntList() {
  // You can't actually throw an exception in a destructor "as-is"
  // throw runtime_error(HERE);
}

void IntList::push_front(int val) {
    //TEST CASE:  If the list is empty
   if (dummyHead.next == &dummyTail) {
      IntNode *newNode = new IntNode(val);

      dummyHead.next = newNode;
      newNode->prev = &dummyHead;
      newNode->next = &dummyTail;
      dummyTail.prev = newNode;
   }
   else {
      IntNode *temp = new IntNode(val);

      temp->next = dummyHead.next;
      temp->prev = &dummyHead;
      dummyHead.next->prev = temp;
      dummyHead.next = temp;
   }
}


void IntList::pop_front() {
    //TEST CASE:  If the list is not empty, proceed with function 
    if (dummyHead.next != &dummyTail) {
        IntNode *temp = dummyHead.next;

        dummyHead.next = temp->next;
        temp->next->prev = &dummyHead;
        delete temp;
    }
    // if empty list, we exit function 
}


void IntList::push_back(int value) {
    //TEST CASE:  If the list is empty, handle dummyhead and dummytail as such 
    if (dummyHead.next == &dummyTail) {
        IntNode *newNode = new IntNode(value);

        dummyHead.next = newNode;
        newNode->prev = &dummyHead;
        newNode->next = &dummyTail;
        dummyTail.prev = newNode;
    }
    else {
        IntNode *temp = new IntNode(value);
        temp->prev = dummyTail.prev;
        temp->next = &dummyTail;
        dummyTail.prev->next = temp;
        dummyTail.prev = temp;
    }
}

void IntList::pop_back() {
  //TEST CASE:  If the list is not empty, handle dummyhead and dummytail as such 
    if (dummyHead.next != &dummyTail) {
        IntNode *temp = dummyTail.prev;

        dummyTail.prev = temp->prev;
        temp->prev->next  = &dummyTail; // make old tail's previous into new next 
        delete temp;
    }
    // if empty list, we exit function 
}

bool IntList::empty() const {
    return dummyHead.next == &dummyTail;
}

void IntList::printReverse() const {
    IntNode *current = dummyTail.prev; 
    //TEST CASE: while we haven't reached the dummyhead, keep printing in reverse
    while (current != &dummyHead) {
      cout << current->data;
        if (current->prev != &dummyHead) {
            cout << " ";
        }
        current = current->prev;
    }
    cout << endl;
}

//END OF INTLIST.CPP