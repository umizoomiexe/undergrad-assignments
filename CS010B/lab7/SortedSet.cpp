//SortedSet.cpp

#include <iostream>

#include "SortedSet.h"
using namespace std; 

//constructors and destructor
    SortedSet::SortedSet() :IntList() {
    }

// Copy constructor
    SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy){
    }

    SortedSet::SortedSet(const IntList &intlist) :  IntList(intlist){
        this->remove_duplicates();
        this-> selection_sort();
    }
    SortedSet::~SortedSet(){
        //derived class so will use IntList destructor
    }

    //ACCESSORS
    //his function returns true if the value passed in is a member of the set, otherwise false.
    bool SortedSet::in(int value) const{
        IntNode *current = head; //pointer to head
        while (current != nullptr){
            if(current -> value == value) {//dereferencing to see if equal
                return true;
            }
            current = current->next; //check next value 
        }
        return false;
    }

   SortedSet SortedSet::operator|(const SortedSet & unionset) { //okay 
        SortedSet unioncomplete; 

        IntNode *current = head;
        while (current != nullptr) {
            unioncomplete.add(current->value);
            current = current->next;
        }
        current = unionset.head;
        while(current != nullptr) { //chdk
            unioncomplete.add(current->value);
            current = current->next; 
        }

        return unioncomplete; 
    }

    SortedSet SortedSet::operator&(const SortedSet &intersection) {
        SortedSet final; //creating final output 

        IntNode* current1 = head;
        IntNode* current2 = intersection.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->value == current2->value) {
                final.add(current1->value);
                current1 = current1->next;
                current2 = current2->next;
            } 
            else if (current1->value < current2->value) {
                current1 = current1->next;
            } 
            else {
                current2 = current2->next;
            }
        }

        return final;
    }

 //MUTATORS
    void SortedSet::add(int value){
        // check if the value is already in the set
        //check to see if it not in there ( bool in) 
        //imnsert ordered 

        if(in(value) == true){
            return; //since already in set, no nee dto add (no duplicates allowed)
        }

        IntList::insert_ordered(value);
    }


    
    void SortedSet::push_front(int value){
        add(value); 
    }
    void SortedSet::push_back(int value){
        add(value);
    }
    void SortedSet::insert_ordered(int value){
        add(value);
    }
    SortedSet& SortedSet::operator|=( SortedSet &other){
        SortedSet complete = *this | other;
        clear();
        
        IntNode* curr = complete.head;
        while (curr != nullptr) {
            add(curr->value);
            curr = curr->next;
        }
        *this = complete; 
        return *this;
 
    }
    SortedSet& SortedSet::operator&=( SortedSet &other){
        if(empty()) {
            clear();
            return *this;
        }
        SortedSet final = *this & other;
        clear();
        IntNode* curr = final.head;

        while (curr != nullptr) {
            add(curr->value);
            curr = curr->next;
        }
        return *this;
    }








