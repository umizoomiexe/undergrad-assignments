//STACK.H FILE
#pragma once
#include <stdexcept>

template<typename T>
class stack {
private:
    static const int MAX_SIZE = 20;
    int size;
    T data[MAX_SIZE];
public:
    stack() : size(0) {}

    void push(T val) {
        if (size >= MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        data[size++] = val;
    }

    void pop() {
        if (size <= 0) {
            throw out_of_range("Called pop on empty stack.");
        }
        size--;
    }

    void pop_two() {
        if (size <= 1) {
            if (size == 0) {
                throw out_of_range("Called pop_two on empty stack.");
            } else {
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
        }
        size -= 2;
    }

    T top() const {
        if (size <= 0) {
            throw underflow_error("Called top on empty stack.");
        }
        return data[size - 1];
    }

    bool empty() const {
        return size == 0;
    }
};

//END 