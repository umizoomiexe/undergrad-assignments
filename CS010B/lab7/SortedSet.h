//SortedSet.h
/* A set is a collection of unique values. That is, a list that does not have 
any duplicates. In our case, we will also keep the list sorted (ascending order), 
so our type will be SortedSet.*/


#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream> 

#include "IntList.h"

class SortedSet : public IntList {
    private: 

    public: 
    //constructors and destructor
    SortedSet(); 
    SortedSet(const SortedSet &cpy);
    SortedSet(const IntList &intlist);
    ~SortedSet();

    //accessors - functions that dont change anything and simply retrieve info 
    bool in(int value) const;
    SortedSet operator|(const SortedSet &unionset) ;
    SortedSet operator&(const SortedSet &intersection) ;

    // //mutators - functions that edit info 
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet& operator|=( SortedSet &other);
    SortedSet& operator&=( SortedSet &other);

};

#endif

