//IntList.cpp

#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) {
}

IntList::~IntList(){
    clear();
}

bool IntList::empty() const {
    return head == nullptr;
}

const int &IntList::front() const {
    return head->value;
}

const int &IntList::back() const {
    return tail->value;
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head;
        head = head->next;
        //head = (*head).next; 
        delete temp;


        // Update tail if the list becomes empty
        if (empty()) {
            tail = nullptr;
        }
    }
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

ostream &operator<<(ostream &out, const IntList &list) {
    IntNode *current = list.head;
    while (current != nullptr) {
        out << current->value;
        if (current->next != nullptr) {
            out << " ";
        }
        current = current->next;
    }
    return out;
}
// deep copy - not only the values of the object's members are copied but also the objects that those members point to are copied
/*IntList::IntList(const IntList &cpy) : head(nullptr), tail(nullptr) {
    for (IntNode *current = cpy.head; current != nullptr; current = current->next) {
        push_front(current->value);
    }
}*/
IntList::IntList(const IntList &cpy) : head(nullptr), tail(nullptr) {
    for (IntNode *current = cpy.head; current != nullptr; current = current->next) {
        push_back(current->value);
    }
}

IntList &IntList::operator=(const IntList &rhs) {
    // Check for self-assignment
    if (this != &rhs) {
        clear();

        for (IntNode *current = rhs.head; current != nullptr; current = current->next) {
            push_back(current->value);
        }

    }

    return *this;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);

    if (empty()) {
        head = tail = newNode;
    } else {
        // traverse  list to find last node like video said 
        IntNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        
        tail = newNode;
    }
}

void IntList::selection_sort() {
    
    for (IntNode *i = head; i != nullptr; i = i->next) {
//set first node as min
        IntNode *minNode = i;
  //find actual min
        for (IntNode *j = i->next; j != nullptr; j = j->next) {
            if (j->value < minNode->value) {
                minNode = j;
            }
        }
    //swap 
        int temp = i->value;
        i->value = minNode->value;
        minNode->value = temp;
    }
}

void IntList::insert_ordered(int value) {

    if (empty()) {
        push_back(value);
        return;
    }

    if (value <= head->value) {
        push_front(value);
        return;
    }
/* current ->next != nullptr && what you wrote to avoid a seg fault */
    IntNode *newNode = new IntNode(value);
    IntNode *current;
    for (current = head; current->next != nullptr && current->next->value <= value; current = current->next);

    newNode->next = current->next;
    current->next = newNode;

    if (newNode->next == nullptr) {
        tail = newNode;
    }

}

void IntList::remove_duplicates() {
    if (empty()) {
        return;
    }

    IntNode *current = head;

    while (current != nullptr) {
        IntNode *runner = current;

        while (runner->next != nullptr) {
            if (runner->next->value == current->value) {
                // duplicate - remove the node
                IntNode *duplicate = runner->next;
                runner->next = runner->next->next;

                // update tail if the last node is removed
                if (duplicate == tail) {
                    tail = runner;
                }

                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

