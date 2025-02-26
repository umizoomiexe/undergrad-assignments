#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int value) const {
    return exists(head, value);
}

  bool IntList::exists(IntNode *curr, int value) const {
    if (curr) {
        if (curr->value == value) {
            return true;
        }
        return exists(curr->next, value);
    }
    return false;
}


ostream & operator<<(ostream &out, const IntList &list) {
    return operator<<(out, list.head);
}

ostream & operator<<(ostream &out, IntNode *curr) {
    if (curr) {
        out << curr->value;
        if (curr->next) {
            out << " ";
        }
        return operator<<(out, curr->next);
    }
    return out;
}










